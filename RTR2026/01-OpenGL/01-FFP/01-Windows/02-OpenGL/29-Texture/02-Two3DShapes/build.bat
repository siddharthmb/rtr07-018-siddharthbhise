del *.obj
del *.exe

cl.exe /c /EHsc OGL.c E_TimerFunctions.c
rc.exe OGL.rc
link.exe OGL.obj E_TimerFunctions.obj OGL.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS
