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
            ::operator delete[](block, std::align_val_t(64));
        }
    }

private:
    void allocateBlock() noexcept {
        T* block = static_cast<T*>(
            ::operator new[](block_size * sizeof(T), std::align_val_t(64))
        );
        allocatedBlocks.push_back(block);

        freeList.reserve(freeList.size() + block_size);
        for (size_t i = 0; i < block_size; ++i) {
            freeList.emplace_back(&block[i]);
        }

        block_size = block_size + BLOCK_SIZE;
    }
};

#endif
