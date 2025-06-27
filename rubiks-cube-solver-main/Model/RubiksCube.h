#ifndef RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
#define RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <random>
#include <ctime>  // Added for time()

/**
 * Base class for Rubik's Cube models
 */
class RubiksCube {
public:
    // Enum definitions remain unchanged
    enum class FACE { UP, LEFT, FRONT, RIGHT, BACK, DOWN };
    enum class COLOR { WHITE, GREEN, RED, BLUE, ORANGE, YELLOW };
    enum class MOVE {
        L, LPRIME, L2, R, RPRIME, R2,
        U, UPRIME, U2, D, DPRIME, D2,
        F, FPRIME, F2, B, BPRIME, B2
    };

    // Virtual destructor for proper polymorphism
    virtual ~RubiksCube() = default;

    // Pure virtual functions
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;
    virtual bool isSolved() const = 0;

    // Static helper functions
    static char getColorLetter(COLOR color);
    static std::string getMove(MOVE ind);

    // Member functions
    void print() const;
    std::vector<MOVE> randomShuffleCube(unsigned int times);
    RubiksCube& move(MOVE ind);
    RubiksCube& invert(MOVE ind);

    // Corner helper functions
    std::string getCornerColorString(uint8_t ind) const;
    uint8_t getCornerIndex(uint8_t ind) const;
    uint8_t getCornerOrientation(uint8_t ind) const;

    // Rotation functions (pure virtual)
    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;
    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;
    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;
    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;
    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;
    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;
};

#endif // RUBIKS_CUBE_SOLVER_RUBIKSCUBE_H
