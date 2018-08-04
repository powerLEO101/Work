#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define _ 500101
#define INF 0x3f3f3f3f
#define gi get_int()
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}
int Sum[_],w[_];
bool Map[_];

int main()
{
	File(seq);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)w[i] = gi;
	for(int i = 0;i<m;i++)
	{
		memset(Map,0,sizeof(Map));
		int u = gi-1,v = gi-1,Mod = gi;
		Sum[u-1]=0,Map[0]=1;
		int Ans = INF;
		for(int j = u;j<=v;j++)
		{
			Sum[j] = (Sum[j-1]%Mod+w[j]%Mod)%Mod;
			for(int p = Sum[j];p>=0;p--)
				if(Map[p]){Ans = std::min(Ans,Sum[j]-p);break;}
			if(Ans==0)break;
			Map[Sum[j]] = true;
		}
		std::cout<<Ans<<std::endl;
	}
	return 0;
} 
