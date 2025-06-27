#ifndef RUBIKS_CUBE_SOLVER_PERMUTATIONINDEXER_H
#define RUBIKS_CUBE_SOLVER_PERMUTATIONINDEXER_H

#include <array>
#include <bitset>
#include <cstdint>
#include <cmath>

template <size_t N, size_t K = N>
class PermutationIndexer {
    // Use uint64_t to prevent overflow for larger N values
    std::array<uint64_t, (1ULL << N)> onesCountLookup;

    // Precomputed table of falling factorials
    std::array<uint64_t, K> factorials;

    // Helper function to compute falling factorial
    static uint64_t falling_factorial(uint32_t n, uint32_t k) {
        uint64_t result = 1;
        for (uint32_t i = 0; i < k; ++i) {
            result *= (n - i);
        }
        return result;
    }

public:
    PermutationIndexer() {
        // Build population count lookup table
        for (uint32_t i = 0; i < (1ULL << N); ++i) {
            onesCountLookup[i] = std::bitset<N>(i).count();
        }

        // Precompute factorials (falling factorials)
        for (uint32_t i = 0; i < K; ++i) {
            factorials[i] = falling_factorial(N - 1 - i, K - 1 - i);
        }
    }

    uint64_t rank(const std::array<uint8_t, K>& perm) const {
        std::array<uint64_t, K> lehmer;
        std::bitset<N> seen;

        lehmer[0] = perm[0];
        seen[N - 1 - perm[0]] = 1;

        for (uint32_t i = 1; i < K; ++i) {
            seen[N - 1 - perm[i]] = 1;

            // Calculate the number of elements smaller than perm[i] that have been seen
            uint32_t numOnes = 0;
            for (uint8_t j = 0; j < perm[i]; ++j) {
                if (seen[N - 1 - j]) numOnes++;
            }

            lehmer[i] = perm[i] - numOnes;
        }

        uint64_t index = 0;
        for (uint32_t i = 0; i < K; ++i) {
            index += lehmer[i] * factorials[i];
        }
        return index;
    }
};

#endif // RUBIKS_CUBE_SOLVER_PERMUTATIONINDEXER_H
