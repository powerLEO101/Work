#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f

int Ans;
void Get_ans(int Now,int p,int step,int m)
{
	if(Now==m){Ans = std::min(Ans,step);return;}
	if(step>=Ans)return;
	if(p!=-1)Get_ans(Now+p,p,step+1,m);
	if(Now!=1)Get_ans(Now-1,p,step+1,m);
	Get_ans(Now,Now,step+1,m);
}

int main()
{
//	freopen("greed.in","r",stdin);
//	freopen("greed.out","w",stdout);
	int n = 1,m;
	scanf("%d",&m);
	std::cout<<m;
	Ans = m;
	std::cout<<233;
	Get_ans(n,-1,0,m);
	std::cout<<Ans;
	return 0;
}

