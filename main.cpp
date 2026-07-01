
#include "Modem.h"
#include "AWGN.h"
#include "Hamming_codec_7_4.h"
#include "State.h"

int main() {
    Hamming_coder_7_4 coder{};
    Hamming_decoder_7_4 decoder{};
    Functor f1{};

    /*
    Bits bits1{20};
    bits1.random_bits();


    Bits bits1_tx{35};
    coder.NR_code(bits1, bits1_tx);

    Symbols<double> sym1{35};
    Symbols<double> sym1_noisy{35};
    BPSK_Mod bpsk_mod{};
    bpsk_mod.set_modulation(bits1_tx, sym1, f1);
    AWGN<double> AWGN_bpsk{0.};
    AWGN_bpsk.process(sym1, sym1_noisy);

    BPSK_Demod bpsk_demod{};
    Bits bits1_rx{35};
    bpsk_demod.demodulate(sym1_noisy, bits1_rx, f1);
    Bits bits1_end{20};
    decoder.NR_decode(bits1_rx, bits1_end);
    bits1.show();
    bits1_tx.show();
    sym1.show_bpsk();
    sym1_noisy.show_bpsk();
    bits1_rx.show();
    bits1_end.show();
    */
    std::cout << "---------------------\n";

    Bits bits2{19};
    bits2.random_bits();

    Bits bits2_tx{40};
    coder.NR_code(bits2, bits2_tx);

    Symbols<Complex> sym2{40};
    Symbols<Complex> sym2_noisy{40};
    QPSK_Mod qpsk_mod{};
    qpsk_mod.set_modulation(bits2_tx, sym2, f1);
    AWGN<Complex> AWGN_qpsk{0.};
    AWGN_qpsk.process(sym2, sym2_noisy);

    QPSK_Demod qpsk_demod{};
    Bits bits2_rx{100};
    qpsk_demod.demodulate(sym2_noisy, bits2_rx, f1);
    Bits bits2_end{100};
    decoder.NR_decode(bits2_rx, bits2_end);
    
    bits2.show();
    bits2_end.show();
    State(bits2, bits2_end);


    return 0;
}