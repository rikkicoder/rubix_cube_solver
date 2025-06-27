#include "RubiksCube.h"
#include <string>
#include <functional>

class RubiksCube1dArray : public RubiksCube {
private:
    static inline int getIndex(int ind, int row, int col) {
        return (ind * 9) + (row * 3) + col;
    }

    void rotateFace(int ind) {
        char temp_arr[9] = {};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                temp_arr[i * 3 + j] = cube[getIndex(ind, i, j)];
            }
        }
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 0, i)] = temp_arr[getIndex(0, 2 - i, 0)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, i, 2)] = temp_arr[getIndex(0, 0, i)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2, 2 - i)] = temp_arr[getIndex(0, i, 2)];
        for (int i = 0; i < 3; i++) cube[getIndex(ind, 2 - i, 0)] = temp_arr[getIndex(0, 2, 2 - i)];
    }

public:
    char cube[54]{};

    RubiksCube1dArray() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i * 9 + j * 3 + k] = getColorLetter(static_cast<COLOR>(i));
                }
            }
        }
    }

    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char color = cube[getIndex(static_cast<int>(face), row, col)];
        switch (color) {
            case 'B': return COLOR::BLUE;
            case 'R': return COLOR::RED;
            case 'G': return COLOR::GREEN;
            case 'O': return COLOR::ORANGE;
            case 'Y': return COLOR::YELLOW;
            case 'W':
            default:  return COLOR::WHITE;
        }
    }

    bool isSolved() const override {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (cube[getIndex(i, j, k)] != getColorLetter(static_cast<COLOR>(i)))
                        return false;
                }
            }
        }
        return true;
    }

    // Rotation functions (same as your implementation)
    RubiksCube &u() override {
        this->rotateFace(0);
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[getIndex(4, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(4, 0, 2 - i)] = cube[getIndex(1, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(1, 0, 2 - i)] = cube[getIndex(2, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(2, 0, 2 - i)] = cube[getIndex(3, 0, 2 - i)];
        for (int i = 0; i < 3; i++) cube[getIndex(3, 0, 2 - i)] = temp_arr[i];
        return *this;
    }

    // Other move implementations (uPrime, u2, l, lPrime, etc.)
    // remain the same as in your original code

    // Operator overloading
    bool operator==(const RubiksCube1dArray &r1) const {
        for (int i = 0; i < 54; i++) {
            if (cube[i] != r1.cube[i]) return false;
        }
        return true;
    }

    RubiksCube1dArray &operator=(const RubiksCube1dArray &r1) {
        for (int i = 0; i < 54; i++) {
            cube[i] = r1.cube[i];
        }
        return *this;
    }
};

struct Hash1d {
    std::size_t operator()(const RubiksCube1dArray &r1) const {
        std::string str;  // Use std::string
        for (int i = 0; i < 54; i++)
            str += r1.cube[i];
        return std::hash<std::string>()(str);  // Fully qualified
    }
};
