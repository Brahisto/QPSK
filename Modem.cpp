//Modem.cpp
#include "Modem.h"


double Functor::operator()(int x) {
        double a;
        if (x == 1) a = 1.;
        else a = -1.;
        return a;
    }


void BPSK_Mod::set_modulation(Bits & bits, Symbols<double> & syms, Functor & f1) {
        std::transform(bits.bits_.begin(), bits.bits_.end(), syms.syms_.begin(), f1);
    }

Complex Functor::operator()(const std::vector<int> & v) {
        Complex x{0, 0};
        if ((v[0] == 1) && (v[1] == 1)) x = {std::sqrt(0.5), std::sqrt(0.5)};
        else if ((v[0] == 0) && (v[1] == 1)) x = {-std::sqrt(0.5), std::sqrt(0.5)};
        else if ((v[0] == 0) && (v[1] == 0)) x = {-std::sqrt(0.5), -std::sqrt(0.5)};
        else if ((v[0] == 1) && (v[1] == 0)) x = {std::sqrt(0.5), -std::sqrt(0.5)};
        return x;
    }

void QPSK_Mod::set_modulation(Bits & bits, Symbols<Complex> & syms, Functor & f2) {
        std::vector<std::vector<int>> vec_(bits.bits_.size() / 2, std::vector<int>(2, 0));   //вектор векторов длины 2 (группируем отсчеты)

        int u = 0;
        for (auto i = vec_.begin();i != vec_.end();i++) {
            for (auto j = (*i).begin(); j != (*i).end();j++) {
                *j = bits.bits_[u++]; //заполняем отсчеты исходным битовым потоком
            }
        }
        std::transform(vec_.begin(),vec_.end(), syms.syms_.begin(), f2);

    }

int Functor::operator()(double x) {
    if (x >= 0) return 1;
    else return 0;
}

void BPSK_Demod::demodulate(Symbols<double> & syms, Bits & bits, Functor & f1) {
    std::transform(syms.syms_.begin(), syms.syms_.end(), bits.bits_.begin(), f1);
}

std::vector<int> Functor::operator()(const Complex & num) {
    std::vector<int> vec(2, 0);
    if (num.real >= 0 and num.imag >= 0) {vec[0] = 1;vec[1] = 1;}
    else if (num.real >= 0 and num.imag <= 0) {vec[0] = 1;vec[1] = 0;}
    else if (num.real <= 0 and num.imag <= 0) {vec[0] = 0;vec[1] = 0;}
    else if (num.real <= 0 and num.imag >= 0) {vec[0] = 0;vec[1] = 1;}
    return vec;
}

void QPSK_Demod::demodulate(Symbols<Complex> & syms, Bits & bits, Functor & f2) {
    std::vector<std::vector<int>> vec_(syms.syms_.size(), std::vector<int>(2, 0));
    std::transform(syms.syms_.begin(), syms.syms_.end(), vec_.begin(), f2);

    int u{};
    for (auto i = vec_.begin(); i != vec_.end();i++) {
        bits.bits_[u++] = (*i)[0];
        bits.bits_[u++] = (*i)[1];
    }
}