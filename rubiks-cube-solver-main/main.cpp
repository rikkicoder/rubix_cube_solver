#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
//#include "Model/RubiksCube3dArray.cpp"
//#include "Model/RubiksCube1dArray.cpp"
//#include "Model/RubiksCubeBitboard.cpp"
#include "Solver/DFSSolver.h"
#include "Solver/BFSSolver.h"
#include "Solver/IDDFSSolver.h"
#include "Solver/IDAstarSolver.h"
//#include "PatternDatabases/CornerPatternDatabase.h"
#include "PatternDatabases/CornerDBMaker.h"

using namespace std;

int main() {
    // =======================
    // 3D, 1D, Bitboard Models
    // =======================

    // RubiksCube3dArray object3DArray;
    // RubiksCube1dArray object1dArray;
    // RubiksCubeBitboard objectBitboard;

    // object3DArray.print();
    // if (object3DArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    // if (object1dArray.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";
    // if (objectBitboard.isSolved()) cout << "SOLVED\n\n";
    // else cout << "NOT SOLVED\n\n";

    // objectBitboard.u();
    // object3DArray.u();
    // object1dArray.u();
    // objectBitboard.print();
    // object3DArray.print();
    // object1dArray.print();

    // (repeat for other moves...)

    // =======================
    // Equality and Assignment
    // =======================

    // RubiksCubeBitboard cube1;
    // RubiksCubeBitboard cube2;
    // if (cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";
    // cube1.randomShuffleCube(1);
    // if (cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";
    // cube2 = cube1;
    // if (cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";

    // =======================
    // unordered_map Test
    // =======================

    // unordered_map<RubiksCubeBitboard, bool, HashBitboard> mp1;
    // mp1[cube1] = true;
    // cube2.randomShuffleCube(8);
    // if (mp1[cube1]) cout << "Cube1 is present\n";
    // else cout << "Cube1 is not present\n";
    // if (mp1[cube2]) cout << "Cube2 is present\n";
    // else cout << "Cube2 is not present\n";

    // =======================
    // DFS Solver Test
    // =======================

    // RubiksCube3dArray cube;
    // cube.print();
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    // DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
    // vector<RubiksCube::MOVE> solve_moves = dfsSolver.solve();
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // dfsSolver.rubiksCube.print();

    // =======================
    // BFS Solver Test
    // =======================

    // RubiksCubeBitboard cube;
    // cube.print();
    // vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // cube.print();
    // BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
    // vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();
    // for(auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();

    // =======================
    // IDDFS Solver Test
    // =======================

    RubiksCubeBitboard cube;
    cube.print();
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(7);
    cout << "Shuffle Moves : ";
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();
    IDDFSSolver<RubiksCubeBitboard, HashBitboard> iddfsSolver(cube, 7);
    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();
    cout << "Solving moves : ";
    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.getCube().print();

    // =======================
    // IDA* Solver Test
    // =======================

    // string fileName = "C:\\Users\\user\\CLionProjects\\rubiks-cube-solver\\Databases\\cornerDepth5V1.txt";
    // RubiksCubeBitboard cube;
    // auto shuffleMoves = cube.randomShuffleCube(13);
    // cube.print();
    // cout << "Shuffle Moves : ";
    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    // auto moves = idaStarSolver.solve();
    // idaStarSolver.rubiksCube.print();
    // cout << "Solving moves : ";
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";

    // =======================
    // CornerPatternDatabase Test
    // =======================

    // CornerPatternDatabase cornerDB;
    // RubiksCubeBitboard cube;
    // cube.print();
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    // cornerDB.setNumMoves(cube, 5);
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    // cube.randomShuffleCube(1);
    // cube.print();
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";
    // cornerDB.setNumMoves(cube, 6);
    // cout << (int)cornerDB.getNumMoves(cube) << "\n";

    // =======================
    // CornerDBMaker Test
    // =======================

    // string fileName = "C:\\Users\\user\\CLionProjects\\rubiks-cube-solver\\Databases\\cornerDepth5V1.txt";
    // CornerDBMaker dbMaker(fileName, 0x99);
    // dbMaker.bfsAndStore();

    // =======================
    // Example: IDA* SOLVER (Active)
    // =======================

    // string fileName = "C:\\Users\\user\\CLionProjects\\rubiks-cube-solver\\Databases\\cornerDepth5V1.txt";
    // RubiksCubeBitboard cube;
    // auto shuffleMoves = cube.randomShuffleCube(13);
    // cube.print();
    // for (auto move: shuffleMoves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // IDAstarSolver<RubiksCubeBitboard, HashBitboard> idaStarSolver(cube, fileName);
    // auto moves = idaStarSolver.solve();
    // idaStarSolver.rubiksCube.print();
    // for (auto move: moves) cout << cube.getMove(move) << " ";
    // cout << "\n";

    return 0;
}
