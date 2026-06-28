#include "AWGN.h"

template <>
void AWGN<Complex>::process(const Symbols<Complex> & in, Symbols<Complex> & out) {
    double power = std::accumulate(in.syms_.begin(), in.syms_.end(), 0., [](double acc, Complex x) {return acc + x.module();});
    power /= in.syms_.size();

    double power_n = power / std::pow(10, SNR / 10);

    std::mt19937 genI(2);
    std::normal_distribution<double> distI(0, std::sqrt(power_n / 2));
    std::mt19937 genQ(200);
    std::normal_distribution<double> distQ(0, std::sqrt(power_n / 2));

    std::transform(in.syms_.begin(), in.syms_.end(), out.syms_.begin(), [& distI, & distQ, & genI, &genQ](Complex x) {return Complex{x.real + distI(genI), x.imag + distQ(genQ)};});

}
template <>
void AWGN<double>::process(const Symbols<double> & in, Symbols<double> & out) {
    double power = std::accumulate(in.syms_.begin(), in.syms_.end(), 0., [](double acc, double x) {return acc + std::pow(x, 2);});
    power /= in.syms_.size();

    double power_n = power / std::pow(10, SNR / 10);
    std::mt19937 gen(3);
    std::normal_distribution<double> dist(0, std::sqrt(power_n));

    std::transform(in.syms_.begin(), in.syms_.end(), out.syms_.begin(), [& dist,& gen](double x) {return x + dist(gen);});

}