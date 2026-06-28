#include "Channel.h"



template <typename T>
class AWGN : public Channel<T> {
    double SNR;
    public:
    AWGN(double snr = -INFINITY, int len = 0) {
        SNR = snr;
    }
    virtual void process(const Symbols<T> &, Symbols<T> &) override;
};

template <> void AWGN<Complex>::process(const Symbols<Complex> &, Symbols<Complex> &);
template <> void AWGN<double>::process(const Symbols<double> &, Symbols<double> &);