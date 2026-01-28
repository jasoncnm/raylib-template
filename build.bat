@echo off

if "%1" == "clean" (del /Q bin\*)

call scripts\msvc-build-raylib.bat

call scripts\msvc-build-debug.bat
