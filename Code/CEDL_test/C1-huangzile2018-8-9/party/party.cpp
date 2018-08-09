#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 1001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num1[_],Num2[_],n,k,Ans;
bool Vis[_];

void Get_ans(int Now = 0,int Count = 0)
{
	if(Count>k)return;
	if(Now==n)
	{
		Ans++;
		return;
	}
	for(int i = 0;i<n;i++)
	{
		if(Vis[i]==true)continue;
		Vis[i] = true;
		if(Num1[i]<Num2[Now])Get_ans(Now+1,Count+1);
		else Get_ans(Now+1,Count);
		Vis[i] = false;
	}
}

int main()
{
	File(party);
	n = gi,k = gi;
	for(int i = 0;i<n;i++)
		Num1[i] = gi;
	for(int i = 0;i<n;i++)
		Num2[i] = gi;
	if(k>n/2)
	{
		k = n-k;
		for(int i = 0;i<n;i++)std::swap(Num1[i],Num2[i]);
	}
	Get_ans();
	std::cout<<Ans;
	return 0;
}
