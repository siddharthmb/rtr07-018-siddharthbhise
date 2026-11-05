cls

del build\*.obj
del *.exe

cl.exe /c /EHsc OGL.c draw_colouredBharat.c plane.c E_TimerFunctions.c CatmullRom.c /Fobuild\
rc.exe OGL.rc
link.exe build\OGL.obj build\draw_colouredBharat.obj build\plane.obj build\CatmullRom.obj build\E_TimerFunctions.obj OGL.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS

OGL.exe
