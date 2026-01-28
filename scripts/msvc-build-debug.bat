@echo off

set LINKER_FLAGS=/link raylib.lib kernel32.lib user32.lib shell32.lib winmm.lib gdi32.lib opengl32.lib -incremental:no -opt:ref
set COMMON_FLAGS=/DGAME_INTERNAL=1 /Zi /nologo -GR- -Od -Oi -WX -W4 -wd4530 -wd4456 -wd4505 -wd4201 -wd4100 -wd4189 -wd4996 -FC
set EXE_NAME=game.exe

cd bin
cl -I..\src\third_party\raylib ..\src\main.cpp /D_AMD64_ /Fe:%EXE_NAME% %COMMON_FLAGS% %LINKER_FLAGS% %WARNINGS% %DEFINES%
cd ..
