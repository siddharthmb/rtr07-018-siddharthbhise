#include "CatmullRom.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <string.h> // for memcpy_s
#include <windows.h>

// global variable declarations
extern FILE *gpFile;

CatmullRomPoints_t *newCatmullRomPointsObject(void)
{
    // variable declarations
    const char *logFn = "newCatmullRomPointsObject()";
    CatmullRomPoints_t *obj = NULL;

    // code
    obj = (CatmullRomPoints_t *)malloc(sizeof(CatmullRomPoints_t));
    if(obj == NULL)
    {
        fprintf(gpFile, "%s:[%s, %d] malloc failed, check!\n", logFn, __FILE__, __LINE__);
        return NULL;
    }

    memset(obj, 0x0, sizeof(CatmullRomPoints_t));

    return obj;
}

void destroyCatmullRomPointsObject(CatmullRomPoints_t **objToDelete)
{
    // variable declarations
    CatmullRomPoints_t *obj = NULL;

    // code
    if(objToDelete == NULL || *objToDelete == NULL) return;

    removeWaypoints(objToDelete);
    removePieces(objToDelete);

    obj = *objToDelete;

    free(obj);
    *objToDelete = NULL;
}

int setupPieces(CatmullRomPoints_t **objToFill, Piece_t *pieces, int totalPieces)
{
    // variable declarations
    CatmullRomPoints_t *obj = NULL;
    errno_t err;
    const char *logFn = "setupPieces()";

    // code
    if(objToFill == NULL || *objToFill == NULL) return -1;
    if(pieces == NULL || totalPieces <= 0) return -2;

    removePieces(objToFill);

    obj = *objToFill;

    obj->pieces = (Piece_t *)malloc(sizeof(Piece_t) * totalPieces);
    if(obj->pieces == NULL)
    {
        fprintf(gpFile, "%s:[%s, %d] malloc failed, check!\n", logFn, __FILE__, __LINE__);
        return -3;
    }

    err = memcpy_s(obj->pieces, sizeof(Piece_t) * totalPieces, pieces, sizeof(Piece_t) * totalPieces);
    if(err)
    {
        fprintf(gpFile, "%s: [%s, %d] Error(%d) executing memcpy_s. Check!\n", logFn, __FILE__, __LINE__, err);
        free(obj->pieces);
        obj->pieces = NULL;
        return -4;
    }

    obj->totalPieces = totalPieces;
    return 0;
}

int setPieceTStep(CatmullRomPoints_t **objToSetT, float movementPerFrame)
{
    // variable declarations
    int i;
    CatmullRomPoints_t *obj = NULL;

    // code
    if(objToSetT == NULL || *objToSetT == NULL) return -1;
    if((*objToSetT)->pieces == NULL || movementPerFrame <= 0.0f) return -2;

    obj = *objToSetT;

    for(i = 0; i < obj->totalPieces; ++i)
    {
        if(obj->pieces[i].pieceLength > 0.0f)
        {
            obj->pieces[i].tStep = movementPerFrame / obj->pieces[i].pieceLength;
        }
        else
        {
            // length is 0
            obj->pieces[i].tStep = 1.0f;
        }
    }

    return 0;
}

void removePieces(CatmullRomPoints_t **objToRemovePiecesFrom)
{
    // variable declarations
    CatmullRomPoints_t *obj = NULL;

    // code
    if(objToRemovePiecesFrom == NULL || *objToRemovePiecesFrom == NULL) return;

    obj = *objToRemovePiecesFrom;
    // delete operation
    if(obj->pieces != NULL)
    {
        free(obj->pieces);
        obj->pieces = NULL;
        obj->totalPieces = 0;
        obj->currentPiece = NULL;
    }
}

int setupWaypoints(CatmullRomPoints_t **objToFill, Point_t *waypoints, int totalWaypoints, Point_t *guide1, Point_t *guide2)
{
    // variable declarations
    int i;
    int totalPieces;
    int iStatus = 0;
    Point_t *allPoints = NULL;
    Piece_t *pieces = NULL;
    CatmullRomPoints_t *obj = NULL;
    errno_t err;
    const char *logFn = "setupWaypoints()";
    BOOL bSetTStep = FALSE;

    // code
    if(objToFill == NULL || *objToFill == NULL)
    {
        fprintf(gpFile, "%s:[%s, %d] Object to fill is NULL, check!\n", logFn, __FILE__, __LINE__);
        return -1;
    }
    if(waypoints == NULL || totalWaypoints < 2)
    {
        fprintf(gpFile, "%s:[%s, %d] Waypoints are NULL or less than 2 (%d), check!\n", logFn, __FILE__, __LINE__, totalWaypoints);
        return -2;
    }
    if(guide1 == NULL || guide2 == NULL)
    {
        fprintf(gpFile, "%s:[%s, %d] Guide point is NULL, check!\n", logFn, __FILE__, __LINE__);
        return -3;
    }

    // this function may be called multiple times, so remove array of waypoints anyway
    removeWaypoints(objToFill);

    obj = *objToFill;
    obj->guide1 = *guide1;
    obj->guide2 = *guide2;

    // waypoints setup
    obj->waypoints = (Point_t *)malloc(sizeof(Point_t) * totalWaypoints);
    if(obj->waypoints == NULL)
    {
        fprintf(gpFile, "%s:[%s, %d] malloc failed, check!\n", logFn, __FILE__, __LINE__);
        return -4;
    }

    err = memcpy_s(obj->waypoints, sizeof(Point_t) * totalWaypoints, waypoints, sizeof(Point_t) * totalWaypoints);
    if(err)
    {
        fprintf(gpFile, "%s: [%s, %d] Error(%d) executing memcpy_s. Check!\n", logFn, __FILE__, __LINE__, err);
        free(obj->waypoints);
        obj->waypoints = NULL;
        return -5;
    }
    obj->totalWaypoints = totalWaypoints;
    obj->currentPieceIndex = 0;
    obj->lastPosition = obj->waypoints[0];

    // pieces setup
    allPoints = (Point_t *)malloc(sizeof(Point_t) * (totalWaypoints + 2));
    if(allPoints == NULL)
    {
        fprintf(gpFile, "%s:[%s, %d] malloc failed, check!\n", logFn, __FILE__, __LINE__);
        removeWaypoints(objToFill);
        return -6;
    }

    allPoints[0] = obj->guide1;
    for(i = 0; i < totalWaypoints; i++)
    {
        allPoints[i + 1] = obj->waypoints[i];
    }
    allPoints[totalWaypoints + 1] = obj->guide2;

    totalPieces = totalWaypoints - 1;
    pieces = (Piece_t *)malloc(sizeof(Piece_t) * totalPieces);
    if(pieces == NULL)
    {
        free(allPoints);
        allPoints = NULL;
        fprintf(gpFile, "%s:[%s, %d] malloc failed, check!\n", logFn, __FILE__, __LINE__);
        removeWaypoints(objToFill);
        return -7;
    }

    for(i = 0; i < totalPieces; i++)
    {
        pieces[i].prevNeighbour = allPoints[i];
        pieces[i].startPoint = allPoints[i + 1];
        pieces[i].endPoint = allPoints[i + 2];
        pieces[i].nextNeighbour = allPoints[i + 3];
        pieces[i].t = 0.0f;
        pieces[i].tStep = 0.0f;
        pieces[i].pieceLength = getPieceLengthFromPoints(&pieces[i].startPoint, &pieces[i].endPoint);
    }

    if(setupPieces(objToFill, pieces, totalPieces) != 0)
    {
        fprintf(gpFile, "%s:[%s, %d] Failed to setup pieces!\n", logFn, __FILE__, __LINE__);
        removeWaypoints(objToFill);
        iStatus = -8;
    }
    else
    {
        obj->currentPiece = &obj->pieces[obj->currentPieceIndex];
        bSetTStep = TRUE;
    }

    if(bSetTStep)
    {
        if(setPieceTStep(objToFill, 0.029f) != 0)
        {
            fprintf(gpFile, "%s:[%s, %d] Failed to setup step value for pieces!\n", logFn, __FILE__, __LINE__);
            removeWaypoints(objToFill);
            removePieces(objToFill);
            iStatus = -9;
        }
    }

    free(pieces);
    pieces = NULL;
    free(allPoints);
    allPoints = NULL;

    return iStatus;
}

void removeWaypoints(CatmullRomPoints_t **objToRemoveWaypointsFrom)
{
    // variable declarations
    CatmullRomPoints_t *obj = NULL;

    // code
    if(objToRemoveWaypointsFrom == NULL || *objToRemoveWaypointsFrom == NULL) return;

    obj = *objToRemoveWaypointsFrom;
    // delete op
    if(obj->waypoints != NULL)
    {
        free(obj->waypoints);
        obj->waypoints = NULL;
        obj->totalWaypoints = 0;
    }
}

// mathematical functions implemented
/*
    Catmull-Rom point on a piece, for t from 0 (start) to 1 (end):
    P(t) = w0 * P0 + w1 * P1 + w2 * P2 + w3 * P3
    --------------------------------------------
    w0 = 0.5 * (-t^3 + 2t^2 - t)
    w1 = 0.5 * (3t^3 - 5t^2 + 2)
    w2 = 0.5 * (-3t^3 + 4t^2 + t)
    w3 = 0.5 * (t^3 - t^2)
    --------------------------------------------
    P0 = prevNeighbour, P1 = startPoint, P2 = endPoint, P3 = nextNeighbour
    w0 + w1 + w2 + w3 = 1 for every t
    t = 0 gives P1, t = 1 gives P2
    --------------------------------------------
*/
void getCatmullRomWeights(float t, float weights[4])
{
    // variable declarations
    float t2, t3;   // t-squared, t-cubed

    // code
    t2 = t * t;
    t3 = t2 * t;

    weights[0] = 0.5f * (-t3 + 2.0f * t2 - t);
    weights[1] = 0.5f * (3.0f * t3 - 5.0f * t2 + 2.0f);
    weights[2] = 0.5f * (-3.0f * t3 + 4.0f * t2 + t);
    weights[3] = 0.5f * (t3 - t2);
}

void getPointOnPiece(Piece_t *piece, Point_t *pointOnPiece)
{
    // variable declarations
    float weights[4];

    // code
    if(piece == NULL || pointOnPiece == NULL) return;

    getCatmullRomWeights(piece->t, weights);

    pointOnPiece->x = weights[0] * piece->prevNeighbour.x + weights[1] * piece->startPoint.x + weights[2] * piece->endPoint.x + weights[3] * piece->nextNeighbour.x;
    pointOnPiece->y = weights[0] * piece->prevNeighbour.y + weights[1] * piece->startPoint.y + weights[2] * piece->endPoint.y + weights[3] * piece->nextNeighbour.y;
    pointOnPiece->z = weights[0] * piece->prevNeighbour.z + weights[1] * piece->startPoint.z + weights[2] * piece->endPoint.z + weights[3] * piece->nextNeighbour.z;
}

float getPieceLengthFromPoints(Point_t *p1, Point_t *p2)
{
    // variable declarations
    float dx, dy, dz;

    // code
    if(!p1 || !p2) return 0.0f;

    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    dz = p2->z - p1->z;

    // the formula for calculating distance between points
    // sqrt((x2-x1)^2  +  (y2-y1)^2  +  (z2-z1)^2)
    return sqrtf(dx * dx + dy * dy + dz * dz);
}

float getHeadingAngle(Point_t *from, Point_t *to, float lastAngle)
{
    // variable declarations
    float dx, dy;

    // code
    if(!from || !to) return lastAngle;
    if(getPieceLengthFromPoints(from, to) < 0.0001f) return lastAngle;

    dx = to->x - from->x;
    dy = to->y - from->y;

    return atan2f(-dx, dy) * 180.0f / (float)M_PI;
}

int moveAlongPiece(CatmullRomPoints_t **objToMove, Point_t *newPosition)
{
    // variable declarations
    CatmullRomPoints_t *obj = NULL;
    int iStatus = 0;

    // code
    if(objToMove == NULL || *objToMove == NULL) return -1;
    if((*objToMove)->currentPiece == NULL || newPosition == NULL) return -2;

    obj = *objToMove;

    getPointOnPiece(obj->currentPiece, &obj->lastPosition);

    obj->currentPiece->t = obj->currentPiece->t + obj->currentPiece->tStep;
    if(obj->currentPiece->t >= 1.0f)
    {
        // we reached, move to next piece
        if(obj->totalPiecesTravelled < obj->totalPieces) obj->totalPiecesTravelled++;

        if(obj->currentPieceIndex < obj->totalPieces - 1)
        {
            obj->currentPiece->t = 1.0f;
            obj->currentPieceIndex++;
            obj->currentPiece = &obj->pieces[obj->currentPieceIndex];
            obj->currentPiece->t = 0.0f;
        }
        else
        {
            obj->currentPiece->t = 1.0f;
            iStatus = 1;
        }
    }

    // updates the plane's position params
    getPointOnPiece(obj->currentPiece, newPosition);
    return iStatus;
}

int checkAllPiecesTravelled(CatmullRomPoints_t *obj)
{
    // code
    if(obj == NULL) return -1;
    return (obj->totalPieces == obj->totalPiecesTravelled);
}
