
#include "Bits.h"
#include <algorithm>

template <typename T>
class Channel {
    public:
    virtual void process(const Symbols<T> & in, Symbols<T> & out) = 0;
    virtual ~Channel() = default;
};