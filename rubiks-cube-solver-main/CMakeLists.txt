cmake_minimum_required(VERSION 3.20)
project(rubiks_cube_solver LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        Model
        Solver
        PatternDatabases
)

set(SOURCES
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

add_executable(rubiks_cube_solver ${SOURCES})

foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set_target_properties(rubiks_cube_solver PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_SOURCE_DIR}"
    )
endforeach()

set_target_properties(rubiks_cube_solver PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
