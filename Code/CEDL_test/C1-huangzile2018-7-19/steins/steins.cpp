#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10000001
#define MOD 1000000007
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Father[10000000];
void init(){for(int i = 0;i<_;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}
bool Query(int u,int v){return Get_father(u)==Get_father(v);}

int main()
{
	File(steins);
	int T = gi;
	while(T--)
	{
		int n = gi,m = gi;
		init();
		long long Ans = 1;
		for(int i = 0;i<m;i++)
		{
			int l = gi,r = gi+1;
			if(Query(l,r)==false)
			{
				Merge(l,r);
				Ans = (Ans<<1)%MOD;
			}
		}
		std::cout<<Ans<<std::endl;
	}
	return 0;
}

