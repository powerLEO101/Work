#include<iostream>
#include<iomanip>
#include<fstream>
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

int w[300001];
int Dist[300001],Father[300001],Ans[300001];

void Get_ans(int Now,int dist,int t)
{
	if(dist>t)return;
	Ans[Now]++;
	if(Now==0)return;
	Get_ans(Father[Now],dist+Dist[Now],t);
}

int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)w[i] = gi;
	for(int i = 1;i<n;i++)
	{
		Father[i] = gi-1;
		Dist[i] = gi;
	}
	for(int i = 1;i<n;i++)
	{
		Ans[i] = -1;
		Get_ans(i,0,w[i]);
	}
	for(int i = 0;i<n;i++)
		std::cout<<Ans[i]<<" ";
	return 0;
}
