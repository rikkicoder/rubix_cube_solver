#ifndef RUBIKS_CUBE_SOLVER_DFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_DFSSOLVER_H

#include "../Model/RubiksCube.h"
#include <vector>

template<typename T, typename H>
class DFSSolver {
protected:
    std::vector<typename RubiksCube::MOVE> moves;
    int max_search_depth;
    T rubiksCube;

    // DFS helper function
    bool dfs(int dep) {
        if (rubiksCube.isSolved()) return true;
        if (dep > max_search_depth) return false;

        for (int i = 0; i < 18; i++) {
            RubiksCube::MOVE move = static_cast<RubiksCube::MOVE>(i);
            rubiksCube.move(move);
            moves.push_back(move);

            if (dfs(dep + 1)) return true;

            moves.pop_back();
            rubiksCube.invert(move);
        }
        return false;
    }

public:
    DFSSolver(T _rubiksCube, int _max_search_depth = 8)
        : rubiksCube(_rubiksCube), max_search_depth(_max_search_depth) {}  // Initializer list

        const T& getCube() const{return rubiksCube;}
        T& getCube() {return rubiksCube;}
        std::vector<RubiksCube::MOVE> solve() {
        moves.clear();  // Clear previous moves
        dfs(1);
        return moves;
    }
};

#endif // RUBIKS_CUBE_SOLVER_DFSSOLVER_H
