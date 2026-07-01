There is a QPSK/BPSK Modem and Hamming(7,4) codec simulator with posibilities to add a real channel model that is with AWG noise in. You can configure personnaly it. In main.cpp presented one of several 
variations of project's cpnfiguration. 
Bits.h(cpp) - class to create a bitstream.
SYmbolc.h(cpp) - create a symbol's stream.
Modem.h(cpp) - create a modulator. CLass modem is abstract cause there are many posibilities to improve it in future, also this is rely on class Codec. 
Class AWGN - you may assing your channel with needed SNR.
Statistics - caltculate BER for session
Complex - class of complex number with minimal requireties to project.
