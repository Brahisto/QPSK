#include "Hamming_coder_7_4.h"

void Hamming_coder_7_4::NR_code(const Bits & in, Bits & out) {

    std::vector<std::vector<int>> vec(static_cast<int>(in.bits_.size() / 4) + 1, std::vector (4, 0));

    int u = 0;
    for (auto i = vec.begin();;i++) {
        for (auto j = (*i).begin(); j != (*i).end();j++) {
            while (u != in.bits_.size()) {
                *j = in.bits_[u++];
            }
        }
        (*i).resize(7);
    }

    u = 0;

    for (auto i = vec.begin(); i != vec.end(); i++) {
        (*i)[4] = (*i)[0] ^ (*i)[1] ^ (*i)[3];
        (*i)[5] = (*i)[0] ^ (*i)[2] ^ (*i)[3];
        (*i)[6] = (*i)[1] ^ (*i)[2] ^ (*i)[3];

        for (auto j : (*i)) out.bits_[u++] = j;
    }
}