#ifndef MEMORYPOOL_HPP
#define MEMORYPOOL_HPP

#include <vector>
#include <cstddef>
#include <cassert>

template <typename T>
class MemoryPool {
    std::vector<T*> freeList;
    std::vector<T*> allocatedBlocks;
    static constexpr size_t BLOCK_SIZE = 1024;

public:
    MemoryPool() = default;
    size_t block_size = BLOCK_SIZE;

    T* get() noexcept {
        if (freeList.empty()) {
            allocateBlock();
        }
        T* node = freeList.back();
        freeList.pop_back();
        return node;
    }

    void release(T* node) noexcept {
        freeList.push_back(node);
    }

    ~MemoryPool() {
        for (auto* block : allocatedBlocks) {
            delete[] block;  // llama al destructor de cada elemento
        }
    }

private:
    void allocateBlock() noexcept {
        T* block = new T[block_size];
        allocatedBlocks.push_back(block);

        freeList.reserve(freeList.size() + block_size);
        for (size_t i = 0; i < block_size; ++i) {
            freeList.emplace_back(&block[i]);
        }

        block_size = block_size + BLOCK_SIZE;
    }
};

#endif