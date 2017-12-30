#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y; 
}

int Vis[10001],Ans1,Ans2;
bool Color[10001];
std::vector<int> Map[10001];

bool Get_ans(int Now,bool C)
{
	if(Vis[Now]==true)
	{
		if(C==Color[Now])return true;
		else return false;
	}
	Vis[Now] = true;
	if(C==1)Ans1++;
	else Ans2++;
	Color[Now] = C;
	C = !C;
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		if(Get_ans(*it,C)==false)return false;
	return true;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,Ans = 0;
	for(int i = 0;i<m;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	for(int i = 0;i<n;i++)
	{
		if(Vis[i]==true)continue;
		Ans1 = Ans2 = 0;
		if(Get_ans(i,false)==false)
		{
			std::cout<<"Impossible";
			return 0;
		}
		Ans += std::min(Ans1,Ans2);
	}
	std::cout<<Ans;
	return 0;
}
