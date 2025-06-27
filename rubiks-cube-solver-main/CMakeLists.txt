cmake_minimum_required(VERSION 3.20)
project(rubiks_cube_solver)

set(CMAKE_CXX_STANDARD 14)

# Include header directories
include_directories(
        Model
        Solver
        PatternDatabases
)

# Source files for the executable
add_executable(rubiks_cube_solver
        main.cpp

        Model/RubiksCube.cpp
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Model/RubiksCubeBitboard.cpp

        PatternDatabases/NibbleArray.cpp
        PatternDatabases/PatternDatabase.cpp
        PatternDatabases/CornerPatternDatabase.cpp
        PatternDatabases/CornerDBMaker.cpp
        PatternDatabases/math.cpp
)
