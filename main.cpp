
#include "Modem.h"


int main() {
    

    Bits tx_bits{1000000};
    tx_bits.random_bits();

    Bits rx_bits{1000000};
    rx_bits.show();

    BPSK_Mod bpsk_mod{};
    Symbols<double> sym1{1000000};
    Functor f1;
    bpsk_mod.set_modulation(tx_bits, sym1, f1);
    tx_bits.show();
    sym1.show_bpsk();

    BPSK_Demod bpsk_demod{};
    bpsk_demod.demodulate(sym1, rx_bits, f1);
    rx_bits.show();





    Symbols<Complex> sym2{500000};
    QPSK_Mod qpsk_mod{};
    qpsk_mod.set_modulation(tx_bits, sym2, f1);
    sym2.show_qpsk();
    QPSK_Demod qpsk_demod{};
    qpsk_demod.demodulate(sym2, rx_bits, f1);
    rx_bits.show();

    return 0;
}