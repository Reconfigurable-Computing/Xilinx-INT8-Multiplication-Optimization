#include"int8_mult.h"

ap_int<32> MUL_MAC(ap_int<8> A, ap_int<8> W0, ap_int<8> W1)
{
    ap_int<24> W;
    W = (W0, ap_uint<16>(0)) + ap_int<24>(W1);

    ap_int<16> r0;
    ap_int<16> r1;

    (r0, r1) = A*W;

    r0 = r0+r1[16-1];

    return (r0,r1);
}
