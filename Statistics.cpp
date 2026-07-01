//Statistics.cpp
#include "State.h"

void State(const Bits & in, const Bits & out) {
    double BER = 0;
    for (auto i = 0;i < in.bits_.size();i++) {
        if (in.bits_[i] != out.bits_[i]) BER++;
    }
    BER /= in.bits_.size();
    std::cout << BER << std::endl;
}