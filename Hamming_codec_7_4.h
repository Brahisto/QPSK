#include "Codec.h"

class Hamming_coder_7_4 : public Coder {
    int n_;
    int k_;
    public:

    Hamming_coder_7_4() : n_(7), k_(4) {};
    virtual void NR_code(const Bits &, Bits &) override;
};

class Hamming_decoder_7_4 : public Decoder {
    int n_;
    int k_;
    public:
    Hamming_decoder_7_4() : n_(7),  k_(4) {};
    virtual void NR_decode(const Bits &, Bits &) override;
};