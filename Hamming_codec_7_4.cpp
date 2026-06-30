#include "Hamming_codec_7_4.h"

void Hamming_coder_7_4::NR_code(const Bits & in, Bits & out) {

    std::vector<std::vector<int>> vec(static_cast<int>(in.bits_.size() / k_) + static_cast<int>((in.bits_.size() % k_) != 0), std::vector (k_, 0));

    int u = 0;
    for (auto i = vec.begin(); i!= vec.end();i++) {
        for (auto j = (*i).begin(); j != (*i).end();j++) {
            if (u == in.bits_.size()) break;
            *j = in.bits_[u++];
        }
        (*i).resize(n_);
    }

    u = 0;

    for (auto i = vec.begin(); i != vec.end(); i++) {
        (*i)[4] = (*i)[0] ^ (*i)[1] ^ (*i)[3];
        (*i)[5] = (*i)[0] ^ (*i)[2] ^ (*i)[3];
        (*i)[6] = (*i)[1] ^ (*i)[2] ^ (*i)[3];

        for (auto j : (*i)) out.bits_[u++] = j;
    }
}

void Hamming_decoder_7_4::NR_decode(const Bits & in, Bits & out) {
    std::vector<std::vector<int>> vec(static_cast<int>(in.bits_.size() / n_) + static_cast<int>((in.bits_.size() % n_) != 0), std::vector (n_, 0));

    int u = 0;
    for (auto i = vec.begin(); i!= vec.end();i++) {
        for (auto j = (*i).begin(); j != (*i).end();j++) {
            if (u == in.bits_.size()) break;
            *j = in.bits_[u++];
        }
    }

    std::vector<int> sindrom(3, 0);
    for (auto i = vec.begin();i != vec.end();i++) {
        sindrom[0] = (*i)[0]^(*i)[1]^(*i)[3]^(*i)[4];
        sindrom[1] = (*i)[0]^(*i)[2]^(*i)[3]^(*i)[5];
        sindrom[2] = (*i)[1]^(*i)[2]^(*i)[3]^(*i)[6];

        int pos = sindrom[0] + 2*sindrom[1] + 4*sindrom[2];

        if (pos == 0) {
            (*i).resize(4);
            continue;
        }
        (*i)[pos-1] = (((*i)[pos-1]==1) ? 0 : 1);
        (*i).resize(4);
    }

    u = 0;
    for (auto i = vec.begin(); i != vec.end();i++) {
        for (auto j : (*i)) out.bits_[u++] = j;
    }
}