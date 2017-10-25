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

class Node
{
public:
	int Val[32],size;
}x[100001];
int Num[100001][32],size[100001];
bool p[100001],c[32];
int cmp(const Node& a,const Node& b)
{	
	return a.size>b.size;
}
bool Judge()
{
	for(int i = 0;i<32;i++)if(c[i]==true)return false;
	return true;
}
int main()
{
	freopen("chorus.in","r",stdin);
	freopen("chorus.out","w",stdout);
	int n = gi,Ans = 0;
	for(int i = 0;i<n;i++)
	{
		int Temp = gi,Index = 0;
		while(Temp!=0)
		{
			if(Temp&1==1)
			{
				Num[i][Index]++;
				size[i]++;
				c[Index] = true;
			}
			Index++;Temp>>=1;
		}
	}
//	for(int i = 0;i<n;i++)
//	{
//		for(int j = 0;j<32;j++)
//			std::cout<<Num[i][j]<<" ";
//		std::cout<<std::endl;
//	}
	for(int i = 0;i<32;i++)
	{
		int s = 0,Index;
		for(int j = 0;j<n;j++)
			if(Num[j][i]==1)s++,Index = j;
		if(s==1)
		{
//			stdi::cout<<i<<" "<<Index<<std::endl;
			if(p[Index]!=true)Ans++;
			p[Index] = true;
			for(int i = 0;i<32;i++)
				if(Num[Index][i]!=0)
					c[i] = false;
		}
	}
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<32;j++)
			std::cout<<Num[i][j]<<" ";
		std::cout<<std::endl;
	}
	int Index = 0,len = 0;
	for(int i = 0;i<n;i++)
	{
		if(p[i]==true)continue;
		for(int j = 0;j<32;j++)
		{
			x[Index].Val[j] = Num[i][j];
			x[Index].size = size[i];
		}
		Index++;
		len++;
	}
	std::sort(x,x+len,cmp);
	for(int i = 0;i<len&&Judge()==false;i++)
	{
		for(int j = 0;i<32;i++)
			if(c[j]==true&&x[i].Val[j]==true)c[j] = false;
		Ans++;
	}
	std::cout<<Ans;
	return 0;
}
