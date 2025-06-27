@echo off
rmdir /s /q build
mkdir build
cd build
cmake ..
cmake --build .
cd ..
.\rubiks_cube_solver.exe
pause

@REM This script is used to rebuild the project.
@REM If you wwant to do it on linux / mac create a .sh file