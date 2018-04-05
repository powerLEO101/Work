#include<bits/stdc++.h>
#define RG register
#define file(x) freopen(#x".in", "r", stdin);freopen(#x".out", "w", stdout);
#define clear(x, y) memset(x, y, sizeof(x));
using namespace std;

inline long long read()
{
	long long data=0, w=1;
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') w=-1, ch=getchar();
	while(ch>='0'&&ch<='9') data=(data<<3)+(data<<1)+(ch^48), ch=getchar();
	return data*w;
}

const int maxn(60);
long long base[maxn], ans, x;
int n;

int main()
{
	n=read();
	for(RG int i=1;i<=n;i++)
	{
		x=read();
		for(RG int j=maxn-10;~j;j--)
			if(x & (1ll<<j))
			{
				if(!base[j]) { base[j]=x; break; }
				else x^=base[j];
			}
	}
	for(RG int j=maxn-10;~j;j--) if(ans < (ans ^ base[j])) ans^=base[j];
	printf("%lld\n", ans);
	return 0;
}
