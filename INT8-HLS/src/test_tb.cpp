#include"int8_mult.h"

int main(void)
{
    ap_int<16> r0, r1;
    ap_int<8> w0, w1;
    ap_int<8> ax;
    for(int i=0;i<1000000;i++){
        ax=(ap_int<8>)(rand()%255-127);                 //-127,127
        w0=(ap_int<8>)(rand()%255-127);
        w1=(ap_int<8>)(rand()%255-127);
        cout<<"ax="<<ax<<endl;
        cout<<"w0="<<w0<<endl;
        cout<<"w1="<<w1<<endl;
    	(r0, r1) = MUL_MAC(ax, w0, w1);
    	cout<<r0<<","<<ax*w0<<endl;
    	cout<<r1<<","<<ax*w1<<endl;
    	if(r0.to_int()!=ax*w0||r1.to_int()!=ax*w1){
    		cout<<"test failed"<<endl;
    		return -1;
    	}

    }
    cout<<"test pass"<<endl;
    return 0;
}
