#include<iostream>
#include<cstdio>
#include<algorithm>
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

int Shift[1000005];

void Get_Shift(std::string b)
{
	int j = -1;
	Shift[0] = -1;
	for(int i = 1;i<b.size();i++)
	{
		while(j>-1&&b[i]!=b[j+1])j = Shift[j];
		if(b[i]==b[j+1])j++;
		Shift[i] = j;
	}
}
void Kmp(std::string a,std::string b)
{
	int j = -1,Ans = 0;
	for(int i = 0;i<a.size();i++)
	{
		while(j>-1&&a[i]!=b[j+1])j = Shift[j];
		if(a[i]==b[j+1])j++;
		if(j==b.size()-1)
		{
			Ans++;
			j = Shift[j];
		}
	}
	std::cout<<Ans<<std::endl;
}

int main()
{
	File(code);
	int T = gi;
	while(T--)
	{
		std::string a,b;
		std::cin>>b>>a;
		Get_Shift(b);
		Kmp(a,b);
	}
	return 0;
}

