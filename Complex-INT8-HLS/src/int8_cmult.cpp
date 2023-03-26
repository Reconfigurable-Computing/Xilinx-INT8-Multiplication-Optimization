#include"int8_cmult.h"

ap_int<36> MUL_MAC(ap_int<9> A, ap_int<9> W0, ap_int<9> W1)
{
    //若INT9可以取到-256，则W会发生溢出，导致计算结果错误。
    ap_int<27> W;
    W = (W0, ap_uint<18>(0)) + ap_int<27>(W1);

    ap_int<18> r0;
    ap_int<18> r1;

    (r0, r1) = A*W;

    r0 = r0+r1[18-1];

    return (r0,r1);
}

void cmult(cidata_t a,cidata_t b,cidata_t c,codata_t & ac,codata_t & bc){
    ap_int<9> ar=(ap_int<9>)a.real();
    ap_int<9> ai=(ap_int<9>)a.imag();
    ap_int<9> br=(ap_int<9>)b.real();
    ap_int<9> bi=(ap_int<9>)b.imag();
    ap_int<9> cr=(ap_int<9>)c.real();
    ap_int<9> ci=(ap_int<9>)c.imag();
    ap_int<18> r0,r1;
    //
    ap_int<9> arai=ar+ai;               //ar+ai
    ap_int<9> brbi=br+bi;
    ap_int<9> cicr=ci-cr;               //ci-cr
    ap_int<9> crci=cr+ci;               //cr+ci
    //
    (r0,r1)=MUL_MAC(cr,arai,brbi);
    ap_int<32> k11=(ap_int<32>)r0;
    ap_int<32> k21=(ap_int<32>)r1;
    (r0,r1)=MUL_MAC(cicr,ar,br);
    ap_int<32> k12=(ap_int<32>)r0;
    ap_int<32> k22=(ap_int<32>)r1;
    (r0,r1)=MUL_MAC(crci,ai,bi);
    ap_int<32> k13=(ap_int<32>)r0;
    ap_int<32> k23=(ap_int<32>)r1;
    //
    ac.real(k11-k13);
    ac.imag(k11+k12);
    bc.real(k21-k23);
    bc.imag(k21+k22);
}


