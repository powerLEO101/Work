#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}


int Temp[10001];
std::queue<int> q1,q2,q3;

int Front(std::queue<int>& a){return a.empty()?-INF:a.front();}
int Get()
{
	int Max = std::max(Front(q1),std::max(Front(q2),Front(q3)));
	if(Max==q1.front())q1.pop();
	else if(Max==q2.front())q2.pop();
	else if(Max==q3.front())q3.pop();
	return Max;
}

int cmp(int& aa,int& bb){return aa>bb;}

int main()
{
	int n = gi,m = gi,q = gi,u = gi,v = gi,t = gi;
	for(int i = 0;i<n;i++)Temp[i] = gi;
	std::sort(a,a+n,cmp);
	for(int i = 0;i<n;i++)q1.push(a[i]);
	for(int i = 0;i<m;i++)
	{
		int k = Get();
		
	}
	return 0;
}
