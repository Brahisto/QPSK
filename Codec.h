#include "Bits.h"


class Coder {
    virtual void NR_code(const Bits & in, Bits & out) = 0;
};

class Decoder {
    virtual void NR_decode(const Bits & in, Bits & out) = 0;
};