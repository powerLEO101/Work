#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int a[200000],s[30];
int n;
bool P[200000];

void CASE1()
{
	memset(s,0,sizeof(s));
	memset(P,0,sizeof(P));
	for(int i = 0;i<n;i++)a[i] = gi;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<21;j++)
		{
			if(a[i]&(1<<j))
				s[j]++;
		}
	}
	int Ans = 0;
	for(int i = 20;i>=0;i--)
	{
		if(s[i]>=2)
		{
			int t = 1<<i;
			Ans|=t;
			for(int j = 0;j<n;j++)
			{
				if(!(a[j]&t)&&!P[j])
				{
					P[j] = true;
					for(int k = 0;k<=20;k++)
						if(a[j]&(1<<k))
							s[k]--;
				}
			}
		}
	}
	std::cout<<Ans<<std::endl;
}

int trie[25*100000][2],tot;
void CASE2()
{
	for(int i = 0;i<n;i++)a[i] = gi;
	for(int i = 0;i<n;i++)
	{
		int Now = 0;
		for(int j = 20;j>=0;j--)
		{
			int t = 1<<j;
			bool k = a[i]&t;
			if(!trie[Now][k])trie[Now][k] = ++tot;
			Now = trie[Now][k];
		}
	}
	int Ans  = 0;
	for(int i = 0;i<n;i++)
	{
		int Now = 0,s = 0;
		for(int j = 20;j>=0;j--)
		{
			int t = 1<<j;
			bool k = a[i]&t;
			if(trie[Now][k^1])Now = trie[Now][k^1],s|=t;
			else Now = trie[Now][k];
		}
		Ans = std::max(Ans,s);
	}
	std::cout<<Ans<<std::endl;
	memset(trie,0,sizeof(trie));
	tot = 0;
}

bool c[1050600];
void CASE3()
{
	memset(c,0,sizeof(c));
	for(int i = 0;i<n;i++)a[i] = gi,c[a[i]] = true;
	for(int i = 0;i<=20;i++)
	{
		for(int j = (1<<20);j>=0;j--)
		{
			if(j&(1<<i)&&c[j])
				c[j^(1<<i)] = 1;
		}
	}
	int Ans = 0;
	for(int i = 0;i<n;i++)
	{
		int s = 0;
		for(int j = 20;j>=0;j--)
		{
			if(a[i]&(1<<j))continue;
			if(c[s|(1<<j)])s|=(1<<j);
		}
		Ans = std::max(Ans,a[i]|s);
	}
	std::cout<<Ans<<std::endl;
}

int main()
{
	File(maximum);
	int T = gi;
	while(T--)
	{
		int c;
		n = gi,c = gi;
		if(c==1)CASE1();
		if(c==2)CASE2();
		if(c==3)CASE3();
	}
	return 0;
}
