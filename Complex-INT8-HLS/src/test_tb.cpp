#include"int8_cmult.h"

void baseline(cidata_t a,cidata_t b,cidata_t c,codata_t & ac,codata_t & bc){
	int ar=a.real();
	int ai=a.imag();
	int br=b.real();
	int bi=b.imag();
	int cr=c.real();
	int ci=c.imag();
	//
	ac.real(ar*cr-ai*ci);
	ac.imag(ar*ci+ai*cr);
	bc.real(br*cr-bi*ci);
	bc.imag(br*ci+bi*cr);
	//cout<<ac<<endl;
	//cout<<bc<<endl;
}

int main(void)
{
	cidata_t a;
	cidata_t b;
	cidata_t c;
	codata_t ac,bc,ac_ref,bc_ref;
	for(int i=0;i<100000;i++){
		ap_int<8> ar=rand()%255-127;
		ap_int<8> ai=rand()%255-127;
		ap_int<8> br=rand()%255-127;
		ap_int<8> bi=rand()%255-127;
		ap_int<8> cr=rand()%255-127;
		ap_int<8> ci=rand()%255-127;
		a.real(ar);
		a.imag(ai);
		b.real(br);
		b.imag(bi);
		c.real(cr);
		c.imag(ci);
		cout<<"**************************************************************"<<endl;
		cout<<"a="<<a<<endl;
	    cout<<"b="<<b<<endl;
		cout<<"c="<<c<<endl;
		cmult(a,b,c,ac,bc);
		cout<<ac<<endl;
		cout<<bc<<endl;
		baseline(a,b,c,ac_ref,bc_ref);
		cout<<ac_ref<<endl;
		cout<<bc_ref<<endl;
		if(ac.real()!=ac_ref.real()||ac.imag()!=ac_ref.imag()||
		   bc.real()!=bc_ref.real()||bc.imag()!=bc_ref.imag()){
			cout<<"test failed"<<endl;
			return -1;
		}
	}
	cout<<"test pass"<<endl;
    return 0;
}
