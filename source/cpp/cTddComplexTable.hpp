#ifndef CTDDCOMPLEXTABLE_HPP
#define CTDDCOMPLEXTABLE_HPP

#include "Complex.hpp"
#include "Definitions.hpp"

class ComplexTable {

public:
    // Construction
    ComplexTable() {}
    ComplexTable(std::size_t Nbucket) {
        NBUCKET = Nbucket;
        MASK = NBUCKET - 1;
        table.resize(NBUCKET);
        n_nodes = 0;
        add_all_basic_numbers();
    }

    // Clear everything
    void clear() {
        releaseTables();
    }

    // Finds in the complex table the object with the value searched. If not found, then adds a new one.
    Complex* Find_Or_Add(std::complex<dataType> value) {
        if (value == value_one->getOriginalValue()) {
            return value_one;
        }
        RealNumber* r_real = real_number_unique_table.find_or_add(value.real());
        RealNumber* r_imag = real_number_unique_table.find_or_add(value.imag());
        std::size_t hashVal = hash(r_real, r_imag);
        Complex* complex = searchTable(hashVal, r_real, r_imag);
        if (complex == nullptr) {
            complex = create_new_canon_node(r_real, r_imag);
            complex->next = table[hashVal];
            table[hashVal] = complex;
            n_nodes++;
        }
        return complex;
    }

    // Creates a new object that represents the complex number given.
    inline Complex* create_new_canon_node(RealNumber* r_real, RealNumber* r_imag) {
        Complex* c = pool.get();
        c->setFullRealValue(r_real, r_imag);
        return c;
    }

    // Creates a new object that represents the complex number given.
    Complex* create_new_node(std::complex<dataType> value) {
        Complex* c = pool.get();
        c->setValue(value);
        return c;
    }

    Complex* create_unsaved_new_node(std::complex<dataType> value) {
        Complex* c = new Complex();
        RealNumber* n = new RealNumber();
        n->setValUnsafe(value.real());
        c->setRealValue(n);
        n = new RealNumber();
        n->setValUnsafe(value.imag());
        c->setImaginaryValue(n);
        return c;
    }

    long getTotalNodes() {
        return n_nodes;
    }

    long getNBuckets() {
        return table.size();
    }

    // @romOlivo: Gets a string with more info about the performance and usage of the Unique Table
    std::string get_performance_metrics() {
        int max_length = 0;
        int n_buckets = 0;
        int n_nodes = 0;
        float mean_nodes = 0;
        int n_buckets_used = 0;
        float mean_used_nodes = 0;
        for (auto& bucket: table) {
            int partial_length = 0;
            n_buckets++;
            auto* current = bucket;
            while (current) {
                current = current->next;
                partial_length++;
                n_nodes++;
            }
            if (partial_length > max_length) {
                max_length = partial_length;
            }
            if (partial_length > 0) {
                n_buckets_used++;
            }
            mean_nodes = mean_nodes + partial_length;
        }
        mean_used_nodes = mean_nodes / n_buckets_used;
        mean_nodes = mean_nodes / n_buckets;
        std::ostringstream oss;
        oss << "Max length buckets: " << max_length << " / Mean nodes x bucket: " << mean_nodes
            << " / Mean nodes x used bucket: " << mean_used_nodes << "\n";
        return oss.str();
    }

    static void Init_Complex_Unique_Table(std::size_t Nbucket) noexcept;


private:

    // Definition of the hashing function for complex numbers
    inline std::size_t hash(RealNumber* r_real, RealNumber* r_imag) noexcept {
        std::uint64_t pr = reinterpret_cast<std::uint64_t>(r_real);
        std::uint64_t pi = reinterpret_cast<std::uint64_t>(r_imag);

        pr ^= (pr >> 33);
        pi ^= (pi >> 33);

        std::uint64_t h = pr * 0xff51afd7ed558ccdULL;
        h ^= pi * 0xc4ceb9fe1a85ec53ULL;

        h ^= (h >> 33);

        return static_cast<std::size_t>(h & MASK);
    }

    // Search for a given complex value if there is an object in the table that represents it.
    Complex* searchTable(const std::size_t& hashVal, RealNumber* r_real, RealNumber* r_imag) {
        Complex* find_complex = nullptr;
        Complex* complex = table[hashVal];
        while (complex != nullptr) {
            if (complex != nullptr && complex->getRealValue() == r_real && complex->getImaginaryValue() == r_imag) {
                find_complex = complex;
                break;
            }
            complex = complex->next;
        }
        return find_complex;
    }

    // Add an already created object representing a complex
    void Add_Basic_Numbers(Complex* number) {
        std::size_t hashVal = hash(number->getRealValue(), number->getImaginaryValue());
        number->next = table[hashVal];
        table[hashVal] = number;
        n_nodes++;
    }

    void add_all_basic_numbers() {
        Add_Basic_Numbers(value_one);
        Add_Basic_Numbers(value_zero);
    }

    // Release memory of the tables
    void releaseTables() {
        for (auto& bucket: table) { // a bucket in the table
            // Release bucket
            Complex* current = bucket;
            while (current) {
                Complex* temp = current;
                current = current->next;
                if (!(temp->getOriginalValue() == value_one->getOriginalValue() ||
                      temp->getOriginalValue() == value_zero->getOriginalValue())) {
                    pool.release(temp);
                }
            }
            bucket = nullptr;
        }
        n_nodes = 0;
        if (NBUCKET > 0) {
            add_all_basic_numbers();
        }
    }

    // Parameters of the table
    std::size_t NBUCKET;
    std::vector<Complex*> table{std::vector<Complex*>(0)};
    MemoryPool<Complex> pool;
    std::size_t MASK;
    long n_nodes = 0;

};

// Declare the global complex table
extern ComplexTable complex_table;

#endif
