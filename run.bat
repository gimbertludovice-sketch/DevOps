@echo off
title Array Operations - C Program
echo ============================================
echo    Compiling array_operations.c ...
echo ============================================
gcc array_operations.c -o array_operations.exe -Wall
if %errorlevel% neq 0 (
    echo.
    echo BUILD FAILED! Check your GCC installation.
    pause
    exit /b 1
)
echo Build successful!
echo.
echo ============================================
echo    Running Program...
echo ============================================
echo.
array_operations.exe
echo.
echo ============================================
echo    Program Finished.
echo ============================================
pause
