#ifndef MEMORYPOOL_HPP
#define MEMORYPOOL_HPP

#include <vector>
#include <cstddef>
#include <cassert>

template <typename T>
class MemoryPool {
    std::vector<T*> freeList;          // nodos disponibles
    std::vector<T*> allocatedBlocks;   // bloques completos para liberar al final
    static constexpr size_t BLOCK_SIZE = 1024; // número de nodos por bloque

public:
    MemoryPool() = default;

    // Obtener un nodo del pool
    T* get() {
        if (freeList.empty()) {
            allocateBlock();
        }
        T* node = freeList.back();
        freeList.pop_back();
        return node;
    }

    // Devolver un nodo al pool
    void release(T* node) {
        freeList.push_back(node);
    }

    // Liberar toda la memoria
    ~MemoryPool() {
        for (auto* block : allocatedBlocks) {
            delete[] block;
        }
    }

private:
    void allocateBlock() {
        // Reservamos un bloque contiguo
        T* block = new T[BLOCK_SIZE];
        allocatedBlocks.push_back(block);

        // Añadimos todos los nodos al freeList
        for (size_t i = 0; i < BLOCK_SIZE; ++i) {
            freeList.push_back(&block[i]);
        }
    }
};

#endif
