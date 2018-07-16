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
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

std::vector<int> Map[100];
class Pair
{
public:
	int u,v;
};
std::vector<Pair> Num;
bool Vis[100];

bool Get_ans(int Now,int Target,int Sum)
{
	if(Now==Target)
	{
		std::cout<<Sum<<std::endl;
		return true;
	}
	if(Vis[Now]==true)return false;
	Vis[Now] = true;
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
	{
		int A = 0;
		for(std::vector<Pair>::iterator it1 = Num.begin();it1!=Num.end();it1++)
			if((it1->u==Now&&it1->v==*it)||(it1->u==*it&&it1->v==Now))
			{
				A = 1;
				break;
			}
		if(Get_ans(*it,Target,Sum+1-A)==true)return true;
	}
	return false;
}

int main()
{
	freopen("meg.in","r",stdin);
	freopen("meg.out","w",stdout);
	int n = gi;
	for(int i = 1;i<n;i++)
	{
		int u = gi-1,v = gi-1;
		Map[u].push_back(v);
		Map[v].push_back(u);
	}
	int m = gi;
	for(int i = 0;i<m+n-1;i++)
	{
		for(int j = 0;j<100;j++)Vis[j] = false;
		char Mode = getchar();
		if(Mode=='W')
		{
			int a = gi;
			Get_ans(0,a-1,0);
		}
		else
		{
			int u = gi-1,v = gi-1;
			Num.push_back((Pair){u,v});
		}
	}
	return 0;
}
