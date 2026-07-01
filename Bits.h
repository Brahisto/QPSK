//Bits.h
#pragma once

#include <random>
#include <vector>
#include <iostream>
#include "Complex.h"


class Bits {
    int len_;

public:
    std::vector<int> bits_;

    explicit Bits(int len = 0);

    void random_bits();
    void show();
};


template <typename T>
class Symbols {
    int len_;
public:
    std::vector<T> syms_;

    Symbols(int len = 0) {
        if (len <= 0) len_ = 0;
        else {
            len_ = len;
            syms_.resize(len_, static_cast<T>(0));
        }
    }

    void show_bpsk() {
        std::cout << "bpsk symbols:\n";
        for (auto i = syms_.begin(); i != syms_.end();i++) {
            std::cout << *i << " ";
        }
        std::cout << "\n";
    }

    void show_qpsk() {
        std::cout << "qpsk symbols:\n";
        for (auto i = syms_.begin(); i != syms_.end();i++) {
            out(std::cout, *i);
        }
        std::cout << "\n";
    }
};