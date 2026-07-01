//CreateBits.cpp
#include "Bits.h"

Bits::Bits(int len) {
        if (len <= 0) {
            len_ = 0;
        }
        else {
            len_ = len;
            bits_.resize(len_, 0);
        }
    }
    
void Bits::random_bits() {
        std::mt19937 gen(len_);
        std::uniform_int_distribution<int> dist(0, 1);
        for (auto i = bits_.begin(); i != bits_.end();i++) {
            *i = dist(gen);
        }
    }

void Bits::show() {
    std::cout << "bits\n";
    for (auto i = bits_.begin(); i != bits_.end();i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}