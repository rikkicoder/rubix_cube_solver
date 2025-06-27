#ifndef RUBIKS_CUBE_SOLVER_NIBBLEARRAY_H
#define RUBIKS_CUBE_SOLVER_NIBBLEARRAY_H

#include <vector>
#include <cstddef>
#include <cstdint>

class NibbleArray {
    std::size_t size;
    std::vector<uint8_t> arr;

public:
    NibbleArray(const std::size_t size, const uint8_t val = 0xFF);

    uint8_t get(const std::size_t pos) const;
    void set(const std::size_t pos, const uint8_t val);
    uint8_t *data();
    const uint8_t *data() const;
    std::size_t storageSize() const;
    void inflate(std::vector<uint8_t> &dest) const;
    void reset(const uint8_t val = 0xFF);
};

#endif // RUBIKS_CUBE_SOLVER_NIBBLEARRAY_H
