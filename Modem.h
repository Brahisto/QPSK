//Modem.h
#pragma once

#include "Complex.h"
#include <vector>
#include <algorithm>
#include "Bits.h"

class Functor {
    public:
    double operator()(int x);
    int operator()(double x);

    Complex operator()(const std::vector<int> & );
    std::vector<int> operator()(const Complex &);
};



template <typename T>
class Modulator {
    public:
    virtual void set_modulation(Bits & bits, Symbols<T> & syms, Functor &) = 0;
};
class BPSK_Mod : public Modulator<double> {
    public:
    virtual void set_modulation(Bits & , Symbols<double> &, Functor &) override; 
};


class QPSK_Mod : public Modulator<Complex> {
    public:
    virtual void set_modulation(Bits & bits, Symbols<Complex> & syms, Functor & f2) override;
};

template <typename T>
class Demodulator {
    public:
    virtual void demodulate(Symbols<T> &, Bits &, Functor &) = 0;
};
class BPSK_Demod : public Demodulator<double> {
    public:
    virtual void demodulate(Symbols<double> &, Bits &, Functor &);
};
class QPSK_Demod : public Demodulator<Complex> {
    public:
    virtual void demodulate(Symbols<Complex> &, Bits &, Functor &);
};
