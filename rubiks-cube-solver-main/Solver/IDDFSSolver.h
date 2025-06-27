#ifndef RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
#define RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H

#include "DFSSolver.h"

template<typename T, typename H>
class IDDFSSolver : public DFSSolver<T, H> {
private:
    using Base = DFSSolver<T, H>;  // Alias for base class
    int max_depth;

public:
    IDDFSSolver(T _rubiksCube, int _max_depth = 8) : Base(_rubiksCube, _max_depth), max_depth(_max_depth) {}

    std::vector<typename RubiksCube::MOVE> solve() {
        for (int depth = 1; depth <= max_depth; depth++) {
            Base::max_search_depth = depth;  // Access via Base::
            Base::moves.clear();  // Clear previous moves
            if (Base::dfs(1)) {  // Access via Base::
                return Base::moves;
            }
        }
        return Base::moves;
     }
};

#endif //RUBIKS_CUBE_SOLVER_IDDFSSOLVER_H
