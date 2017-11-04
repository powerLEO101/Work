#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#define INF 0x3f3f3f3f

namespace file
{
	std::ifstream cin("2015message.in");
	std::ofstream cout("2015message.out");
}

int father[200001],pre[200001];
void init(){for(int i = 0;i<200001;i++)father[i] = pre[i] = i;}
int get_father1(int u){return father[u]==u?u:father[u] = get_father1(father[u]);}
bool merge(int u,int v)
{
	int x = get_father1(u),y = get_father1(v);
	if(x==y)return true;
	father[x] = y;
	pre[u] = v;
	return false;
}

int main()
{
	//std::ios::sync_with_stdio(false);
	int n,Min = INF;
	file::cin>>n;
	init();
	for(int i = 0;i<n;i++)
	{
		int Temp,Ans = 1;
		file::cin>>Temp;Temp--;
		if(merge(i,Temp)==false)continue;
		for(int j = Temp;j!=i;j = pre[j])
			Ans++;
		Min = std::min(Min,Ans);
	}
	file::cout<<Min;
	return 0;
}
