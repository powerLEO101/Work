#define A __b&1
#define B __b>>=1
#include "message.h"
#include <cstdlib>
#include <cstdio>
long long _n_,_e_; long long _c_ (long long __a, long long __b, long long _o) 
{
	long long __ = 0; 
	while(__b)
	{ 
		if(A) __ = (__ + __a) %_o; __a = (__a + __a) %_o;
		B; 
	} 
	return __;
}
long long _ (long long a, long long b, long long mo) //将信息加密
{ 
	long long ret = 1; 
	while(b) 
	{
		if(b&1) ret = _c_(ret,a,mo);							        
		a = _c_(a,a,mo); b>>=1;
	}
	return ret;
}
void _Wrong_(int x) 
{
	printf("Wrong answer at line %d\n",x);
	exit(0);
}

void _Accept_ () 
{ 
	printf("Accepted ! Token = E4OWLD3\n"); 
	exit(0); 
}
int main () 
{
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	int tot; 
	scanf("%d",&tot);
	init(_n_,_e_);
	for(int i=1;i<=tot;i+=1)
	{
		long long m;
		scanf("%lld",&m);
		if(decrypt(_(m,_e_,_n_))!=m)
			_Wrong_(i);
	}
	_Accept_();
	return 0;
}

