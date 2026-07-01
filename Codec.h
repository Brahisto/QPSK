//Codec.h
#include "Bits.h"


class Coder {
    public:
    virtual void NR_code(const Bits & in, Bits & out) = 0;
    virtual ~Coder() = default;
};

class Decoder {
    public:
    virtual void NR_decode(const Bits & in, Bits & out) = 0;
    virtual ~Decoder() = default;
};