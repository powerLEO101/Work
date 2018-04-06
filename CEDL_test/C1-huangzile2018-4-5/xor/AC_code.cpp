#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define rg register
const int _=1e6+5;
inline int read()
{
	rg char ch='!';rg int z=1,num=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')z=-1,ch=getchar();
	while(ch<='9'&&ch>='0')num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return z*num;
}
int N,Q,s[_],ans[_],a[35];
int lst[_],head[_],l[_],tim[_];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	N=read();
	for(rg int i=1;i<=N;++i)s[i]=read();
	Q=read();
	for(rg int i=1;i<=Q;++i)
	{
		l[i]=read();rg int r=read();ans[i]=read();
		lst[i]=head[r];head[r]=i;
	}
	for(rg int i=1;i<=N;++i)
	{
		rg int now=i,x=s[i];
		for(rg int j=30;j>=0;--j)
		{
			if(x&(1<<j))
			{
				if(!a[j])
				{
					a[j]=x;
					tim[j]=now;
					break;
				}
				else if(now>tim[j]){swap(now,tim[j]);swap(x,a[j]);}
				x^=a[j];
			}
		}
		for(rg int j=head[i];j;j=lst[j])
		{
			for(rg int k=30;k>=0;--k)
			{
				if(tim[k]>=l[j])
					ans[j]=max(ans[j],ans[j]^a[k]);
			}
		}
	}
	for(rg int i=1;i<=Q;++i)
		printf("%d\n",ans[i]);
	return 0;
}
