/*
 * Original code from MQT DD Package (https://github.com/cda-tum/dd_package)
 * License: MIT license
 * 
 * Modifications by Qirui Zhang (qiruizh@umich.edu) for FTDD (https://github.com/QiruiZhang/FTDD)
 *   - Adapted for TDD
 *   - Changed hash function to FNV
 *
 * Modified by Vicente Lopez (voliva@uji.es). Modifications will be marked with @romOlivo.
 *   - Compute table increase the references of nodes in use.
 *   - Compute table checks for overwritten results
 *   - ContComputedCache now reserves memory for copying indices
 *   - AddComputedCache now can find equivalent operations
 */


#ifndef CTDDCOMPUTEDTABLE_HPP
#define CTDDCOMPUTEDTABLE_HPP

#include "cTDD.hpp"
#include "memoryPool.hpp"
#include "cTddUniqueTable.hpp"


/*
    Data structure for caching addition computed results
*/
class AddComputedCache {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    AddComputedCache() {}
    AddComputedCache(std::size_t Nbucket) {
        NBUCKET = Nbucket;
        MASK = NBUCKET - 1;
        table.resize(NBUCKET, nullptr);
    }

    // clear everything
    void clear() {
    /*
        for (auto& entry: table) {
            pool.release(entry);
        }
    */
        table.clear();
    }


    /*
        access functions
    */
    [[nodiscard]] std::size_t   getCount() const        { return NBUCKET; }
    [[nodiscard]] std::size_t   getHit() const          { return hits; }
    [[nodiscard]] std::size_t   getLookups() const      { return lookups; }
    // @romOlivo: Added for counting collisions
    [[nodiscard]] std::size_t   getCollisions() const   { return collisions; }
    [[nodiscard]] dataType      hitRatio() const        { return static_cast<dataType>(hits) / static_cast<dataType>(lookups); }


    /*
        Hash functions
    */
    // FNV-1a
    std::size_t hash(const Edge& edge1, const Edge& edge2) {
        hashType hash_value = fnv_offset_basis;

        std::complex<dataType> ratio = (edge1.weight != static_cast<dataType>(0))
                                       ? (edge2.weight / edge1.weight)
                                       : edge2.weight;

        std::tuple<int, int> ratio_key = get_int_key(ratio);
        const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&ratio_key);
        for (std::size_t i = 0; i < sizeof(std::tuple<int, int>); i++) {
            hash_value = (hash_value ^ static_cast<hashType>(bytes[i])) * fnv_prime;
        }

        std::uintptr_t val = reinterpret_cast<std::uintptr_t>(edge1.node);
        bytes = reinterpret_cast<const unsigned char*>(&val);
        for (std::size_t i = 0; i < sizeof(std::uintptr_t); i++) {
            hash_value = (hash_value ^ static_cast<hashType>(bytes[i])) * fnv_prime;
        }

        val = reinterpret_cast<std::uintptr_t>(edge2.node);
        bytes = reinterpret_cast<const unsigned char*>(&val);
        for (std::size_t i = 0; i < sizeof(std::uintptr_t); i++) {
            hash_value = (hash_value ^ static_cast<hashType>(bytes[i])) * fnv_prime;
        }

        return static_cast<std::size_t>(hash_value & MASK);
    }


    /* 
        Functions for the computed cache look up
    */
    // Insert an entry to the computed cache
    void insert(const Edge& edge1, const Edge& edge2, const Edge& res) {
        std::size_t hashVal = hash(edge1, edge2);
        // @romOlivo: Added for counting collisions and to be able to remove nodes not used by this table.
        Entry* entry = table[hashVal];
        if (entry == nullptr) {
            entry = pool.get();
            table[hashVal]  = entry;
        } else {
            collisions++;
            unique_table.decr_ref_count(entry->edge1.node);
            unique_table.decr_ref_count(entry->edge2.node);
            unique_table.decr_ref_count(entry->res.node);
        }
        // @romOlivo: Important to not change this weight, as it is needed to scalate the result in find
        entry->edge1 = edge1;
        entry->edge2 = edge2;
        // @romOlivo: Now this edge will store the ratio, so only 1 time is computed
        entry->edge2.weight = (edge1.weight != static_cast<dataType>(0))
                                ? (edge2.weight / edge1.weight)
                                : edge2.weight;
        entry->res = res;
        // @romOlivo: Added so now nodes used in this table can not be removed by the garbage collector.
        unique_table.incr_ref_count(edge1.node);
        unique_table.incr_ref_count(edge2.node);
        unique_table.incr_ref_count(res.node);
    }

    // @romOlivo: Reworked so now it can detect equivalent additions
    // Find an entry in the computed cache
    Edge find(const Edge& edge1, const Edge& edge2) {
        lookups++;
        std::complex<dataType> ratio12;

        // Search edge1 op edge2
        std::size_t hashVal = hash(edge1, edge2);
        Entry* entry = table[hashVal];

        if (entry != nullptr){
            // Calculate the ratio
            ratio12 = (edge1.weight != static_cast<dataType>(0))
                           ? (edge2.weight / edge1.weight)
                           : edge2.weight;
            // If nodes and ratio are the same, then is equivalent
            if (entry->edge1.node == edge1.node &&
            entry->edge2.node == edge2.node &&
            get_int_key(entry->edge2.weight) == get_int_key(ratio12)) {

            hits++;
            Edge res = entry->res;
            // Scale up the result
            res.weight *= (edge1.weight / entry->edge1.weight);
            return res;
            }
        }

        // @romOlivo: Although it seems natural to do, i could not found any case in which this was beneficial
        /*
        // Search edge2 op edge1
        hashVal = hash(edge2, edge1);
        entry = table[hashVal];

        if (entry != nullptr){
            // Calculate the ratio
            ratio12 = (edge2.weight != static_cast<dataType>(0))
                                       ? (edge1.weight / edge2.weight)
                                       : edge1.weight;
            // If nodes and ratio are the same, then is equivalent
            if (entry->edge1.node == edge2.node &&
            entry->edge2.node == edge1.node &&
            get_int_key(entry->edge2.weight) == get_int_key(ratio12)) {

            hits++;
            Edge res = entry->res;
            // Scale up the result
            res.weight *= (edge2.weight / entry->edge1.weight);
            return res;
            }
        }
        */

        return Edge();
    }

private:
    // Cache entry
    struct Entry {
        Edge    edge1;
        Edge    edge2;
        Edge    res;
    };

    // computed cache
    std::size_t NBUCKET;
    std::vector<Entry*> table{std::vector<Entry*>(0)};
    MemoryPool<Entry> pool;
    std::size_t MASK;

    // lookup statistics
    std::size_t hits    = 0;
    std::size_t lookups = 0;
    // @romOlivo: Added for counting collisions
    std::size_t collisions = 0;
};


/*
    Data structure for caching contraction computed results
*/
class ContComputedCache {

public:
    /*
        Construction/Destruction related functions
    */
    // Construction
    ContComputedCache() {}
    ContComputedCache(std::size_t Nbucket) {
        NBUCKET = Nbucket;
        MASK = NBUCKET - 1;
        table.resize(NBUCKET, nullptr);
    }

    // clear everything
    void clear() {
    /*
        for (auto& entry: table) {
            entry.res.node = nullptr;
        }
    */
    }


    /*
        access functions
    */
    [[nodiscard]] std::size_t   getCount() const        { return NBUCKET; }
    [[nodiscard]] std::size_t   getHit() const          { return hits; }
    [[nodiscard]] std::size_t   getLookups() const      { return lookups; }
    // @romOlivo: Added for counting collisions
    [[nodiscard]] std::size_t   getCollisions() const   { return collisions; }
    [[nodiscard]] dataType      hitRatio() const        { return static_cast<dataType>(hits) / static_cast<dataType>(lookups); }


    /*
        Hash functions
    */
    // FNV-1a
    std::size_t hash(Node* node1, Node* node2,
                                     const std::vector<keyType>& v0, std::size_t len0,
                                     const std::vector<keyType>& v1, std::size_t len1) {
        hashType hash = fnv_offset_basis;

        // hash the node shared pointers
        std::uintptr_t val = reinterpret_cast<std::uintptr_t>(node1);
        const unsigned char* bytes = reinterpret_cast<const unsigned char*>(&val);
        for (std::size_t i = 0; i < sizeof(std::uintptr_t); i++) { hash = ( hash ^ static_cast<hashType>(bytes[i]) ) * fnv_prime; }
        val = reinterpret_cast<std::uintptr_t>(node2);
        bytes = reinterpret_cast<const unsigned char*>(&val);
        for (std::size_t i = 0; i < sizeof(std::uintptr_t); i++) { hash = ( hash ^ static_cast<hashType>(bytes[i]) ) * fnv_prime; }

        // hash key_2_new_key_1
        // for (const auto& val : key_2_new_key_1) { hash = ( hash ^ static_cast<hashType>(val) ) * fnv_prime; }
        for (std::size_t i = 0; i < len0; ++i) {
            hash = ( hash ^ static_cast<hashType>(v0[i]) ) * fnv_prime;
        }

        // hash_key_2_new_key_2
        // for (const auto& val : key_2_new_key_2) { hash = ( hash ^ static_cast<hashType>(val) ) * fnv_prime; }
        for (std::size_t i = 0; i < len1; ++i) {
            hash = ( hash ^ static_cast<hashType>(v1[i]) ) * fnv_prime;
        }

        return static_cast<std::size_t>(hash & MASK);
    }


    /* 
        Functions for the computed cache look up
    */
    // Insert an entry to the computed cache
    void insert(Node* node1, Node* node2,
            const std::vector<keyType>& v1, std::size_t len1,
            const std::vector<keyType>& v2, std::size_t len2,
            const Edge& res) {

    std::size_t hashVal = hash(node1, node2, v1, len1, v2, len2);
    Entry* entry = table[hashVal];

    // @romOlivo: Added for counting collisions and to be able to remove nodes not used by this table.
    if (entry != nullptr) {
        collisions++;
        unique_table.decr_ref_count(entry->node1);
        unique_table.decr_ref_count(entry->node2);
        unique_table.decr_ref_count(entry->res.node);
    } else {
        entry = pool.get();
        table[hashVal] = entry;
    }

    // @romOlivo: Changed for a direct copy of the vector
    entry->node1 = node1;
    entry->node2 = node2;
    if (entry->key_2_new_key_1.size() < len1) {
        entry->key_2_new_key_1.resize(len1);
    }
    std::memcpy(entry->key_2_new_key_1.data(), v1.data(), len1 * sizeof(keyType));

    if (entry->key_2_new_key_2.size() < len2) {
        entry->key_2_new_key_2.resize(len2);
    }
    std::memcpy(entry->key_2_new_key_2.data(), v2.data(), len2 * sizeof(keyType));
    entry->t1 = len1;
    entry->t2 = len2;
    entry->res = res;

    // @romOlivo: Added so now nodes used in this table can not be removed by the garbage collector.
    unique_table.incr_ref_count(node1);
    unique_table.incr_ref_count(node2);
    unique_table.incr_ref_count(res.node);
}
Edge find(Node* node1, Node* node2,
          const std::vector<keyType>& v1, std::size_t len1,
          const std::vector<keyType>& v2, std::size_t len2) {
    lookups++;

    // Find edge1 op edge2
    std::size_t hashVal = hash(node1, node2, v1, len1, v2, len2);
    Entry* entry = table[hashVal];

    if (entry != nullptr && entry->node1 == node1 && entry->node2 == node2 && len1 == entry->t1 && len2 == entry->t2) {
            if (std::equal(entry->key_2_new_key_1.begin(), entry->key_2_new_key_1.end(), v1.begin()) &&
                std::equal(entry->key_2_new_key_2.begin(), entry->key_2_new_key_2.end(), v2.begin())) {
                hits++;
                return entry->res;
            }
    }

    // Find edge2 op edge1
    hashVal = hash(node2, node1, v2, len2, v1, len1);
    Entry* entry_comm = table[hashVal];

    if (entry_comm != nullptr && entry_comm->node1 == node2 && entry_comm->node2 == node1) {
        if (len1 == entry_comm->t2 && len2 == entry_comm->t1) {
            if (std::equal(entry_comm->key_2_new_key_1.begin(), entry_comm->key_2_new_key_1.end(), v2.begin()) &&
                std::equal(entry_comm->key_2_new_key_2.begin(), entry_comm->key_2_new_key_2.end(), v1.begin())) {
                hits++;
                return entry_comm->res;
            }
        }
    }

    return Edge();
}

private:
    // Cache entry
    struct Entry {
        Node*   node1;
        Node*   node2;
        std::vector<keyType> key_2_new_key_1;
        std::size_t t1;
        std::vector<keyType> key_2_new_key_2;
        std::size_t t2;
        Edge    res;

        // @romOlivo: Making a constructor so now the memory is reserved
        Entry() {
            node1 = nullptr;
            node2 = nullptr;
            key_2_new_key_1.reserve(100);
            key_2_new_key_2.reserve(100);
        }
    };

    // computed cache
    std::size_t NBUCKET;
    std::vector<Entry*> table{std::vector<Entry*>(0)};
    MemoryPool<Entry> pool;
    std::size_t MASK;

    // lookup statistics
    std::size_t hits    = 0;
    std::size_t lookups = 0;
    // @romOlivo: Added for counting collisions
    std::size_t collisions = 0;
};


/*
    Declare the global computed caches here
*/
AddComputedCache add_computed_table;
ContComputedCache cont_computed_table;

#endif //CTDDCOMPUTEDTABLE_HPP
