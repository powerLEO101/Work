#include"bits/stdc++.h"
using namespace std;

struct aa{
	int w[100];
	int len;
	aa() {
		len=0;memset(w,0,sizeof(w)); 
	}
	void set()
	{
		this->len=1;this->w[1]=1;

	}

	aa operator +(const aa b)
	{
		int c=max(len,b.len);
		aa ans; ans.len=c;

		for (int i=1;i<=c;i++) ans.w[i]=w[i]+b.w[i];
		for (int i=1;i<=c;i++) ans.w[i+1]+=ans.w[i]/100000000,ans.w[i]%=100000000;
		if (ans.w[ans.len+1]) ans.len++;

		return ans;

	}

	void print()
	{ cout<<this->w[len];
		for (int i=this->len-1;i>0;i--) printf("%08d",this->w[i]);
	}

}ans,f[520][520];

int main()
{
	int k,w;
	cin>>k>>w;
	int t=w/k;int tt=w%k;
	int jw;
	if (!tt) jw=t;//jw ：几位 
	else jw=t+1;   int temp=1<<k;

	jw=min(jw,temp-1);//比如说w=100，k=3，如果没有这一句的话那jw=33，可是右边的一位要比左边一位大
	//每一位的最大值是2的3次方减一，所以说最多也就是7位。即jw=7； 

	for  (int i=1;i<=temp-1;i++) f[1][i].set();

	for (int i=2;i<=jw;i++)
	{       int k;

		if (tt==0)k=0x7fffffff;
		else if (i==jw) k=(1<<tt)-1;
		else k=0x7fffffff;  

		for (int j=temp-i;j>0;j--)
		{
			f[i][j]=f[i][j+1]+f[i-1][j+1] ;

			if (j<=k) ans=ans+f[i][j];                                  
		} 

	}
	ans.print();
	return 0;

} 
