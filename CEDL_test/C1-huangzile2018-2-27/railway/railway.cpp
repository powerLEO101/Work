#include<iostream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Father[20001];
void init(){for(int i = 0;i<20001;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}
bool Query(int u,int v){return Get_father(u)==Get_father(v);}
int L[20001],R[20001];
bool state[20001];

bool Judge(int x,int y)
{
	if(L[x]<L[y]&&L[y]<R[x]&&R[x]<R[y])return true;
	if(L[y]<L[x]&&L[x]<R[y]&&R[y]<R[x])return true;
	return false;
}

int main()
{
	freopen("railway.in","r",stdin);
	freopen("railway.out","w",stdout);
	init();
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
	{
		int l = gi,r = gi;
		L[i] = l;R[i] = r;
		for(int j = 0;j<i;j++)
		{
			if(Judge(i,j)==false)continue;
			if(Query(i,j)==true)
			{
				std::cout<<"No";
				return 0;				
			}
			Merge(i,j);
		}
	}
	for(int i = 0;i<m;i++)
	{
		int father = Get_father(i);
		state[father] = !state[father];
		if(state[father]==true)std::cout<<"N";
		else std::cout<<"S";
		std::cout<<std::endl;
	}
	return 0;
}
