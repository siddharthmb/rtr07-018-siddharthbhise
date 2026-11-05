#pragma once

// struct for points
typedef struct Point
{
    float x, y, z;
} Point_t;

// pieces (segments or paths also we can call this)
// a piece will need 4 points to be determined
typedef struct Piece
{
    Point_t prevNeighbour;
    Point_t startPoint;
    Point_t endPoint;
    Point_t nextNeighbour;
    float t;
    float tStep;
    float pieceLength;  // the distance this piece makes our plane move
} Piece_t;

// struct for catmull-rom points, using above created struct points
typedef struct CatmullRomPoints
{
    Point_t guide1, guide2;
    Point_t *waypoints;
    int totalWaypoints;
    Piece_t *pieces;
    int totalPieces;
    int currentPieceIndex;
    Piece_t *currentPiece;
    Point_t lastPosition;
    int totalPiecesTravelled;
} CatmullRomPoints_t;

// functions to create and delete catmull-rom objects
CatmullRomPoints_t *newCatmullRomPointsObject(void);
void destroyCatmullRomPointsObject(CatmullRomPoints_t **);

// functions to fill, unfill pieces from an array of Piece_t
int setupPieces(CatmullRomPoints_t **, Piece_t *, int);
void removePieces(CatmullRomPoints_t **);
int setPieceTStep(CatmullRomPoints_t **, float);

// function to fill waypoints from an array of Point_t
int setupWaypoints(CatmullRomPoints_t **, Point_t *, int, Point_t *, Point_t *);
void removeWaypoints(CatmullRomPoints_t **);

// mathematical impl
void getCatmullRomWeights(float t, float weights[4]);
void getPointOnPiece(Piece_t *piece, Point_t *pointOnPiece);
float getPieceLengthFromPoints(Point_t *, Point_t *);
float getHeadingAngle(Point_t *, Point_t *, float);
int moveAlongPiece(CatmullRomPoints_t **, Point_t *);

// catmull-rom utils functions
int checkAllPiecesTravelled(CatmullRomPoints_t *);
