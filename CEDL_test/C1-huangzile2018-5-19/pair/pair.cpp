#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[10001],Left[10001];
std::vector<int> Ans;
int Answer[10001],n,Max;

int Get(int Index)
{
	int l,r;
	for(l = Index-1;l>=0;l--)
		if(Num[l]%Num[Index]!=0)
		{
			l++;
			break;
		}
	if(l==-1)l = 0;
	for(r = Index+1;r<n;r++)
		if(Num[r]%Num[Index]!=0)
		{
			r--;
			break;
		}
	if(r==n)r--;
/*
	std::cout<<l<<" "<<r<<std::endl;
*/
	Left[Index] = l;
	return r-l;
}

int main()
{
	File(pair);
	n = gi,Max = -0x3f3f3f3f;
	for(int i = 0;i<n;i++)Num[i] = gi;
	for(int i = 0;i<n;i++)
	{
		int Len = Get(i);
		if(Len>Max)
		{
			Max = Len;
			Ans.clear();
			Ans.push_back(i);
		}
		else if(Len==Max)Ans.push_back(i);
	}
	int Index = 0;
	for(std::vector<int>::iterator it = Ans.begin();it!=Ans.end();it++)
		Answer[Index++] = Left[*it];
	std::sort(Answer,Answer+Index);
	std::cout<<Ans.size()<<" "<<Max<<std::endl;
	for(int i = 0;i<Index;i++)
	{
		if(Answer[i]==Answer[i-1])continue;
		std::cout<<Answer[i]+1<<" ";
	}
/*
	std::cout<<std::endl<<std::endl;
	std::cout<<Get(0);
*/
	return 0;
}

