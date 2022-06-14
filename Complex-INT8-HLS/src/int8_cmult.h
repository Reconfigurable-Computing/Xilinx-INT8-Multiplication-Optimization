#include <hls_half.h>
#include <ap_fixed.h>
#include <iostream>
#include<complex>
using namespace std;

typedef ap_int<8> idata_t;
typedef ap_int<32> odata_t;
typedef complex<idata_t> cidata_t;
typedef complex<odata_t> codata_t;

ap_int<36> MUL_MAC(ap_int<9> A, ap_int<9> W0, ap_int<9> W1);

void cmult(cidata_t a,cidata_t b,cidata_t c,codata_t & ac,codata_t & bc);
