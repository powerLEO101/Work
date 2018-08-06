#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 300005
#define MOD 1000000009
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Father[_];
void Init(){for(int i = 0;i<_;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
bool Query(int u,int v){return Get_father(Father[u])==Get_father(Father[v]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}

int main()
{
	File(magician);
	int n = gi,m = gi;
	Init();
	int Ans = 0;
	for(int i = 0;i<m;i++)
	{
		int From = gi,To = gi;
		if(Query(From,To)==true)Ans = Ans*2+1;
		Merge(From,To);
		Ans%=MOD;
		std::cout<<Ans<<std::endl;
	}
	return 0;
}
