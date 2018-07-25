#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
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

int Shift[1000005];

void Get_Shift(std::string a)
{
	int j = -1;
	Shift[0] = -1;
	for(int i = 1;i<a.size();i++)
	{
		while(j>-1&&a[i]!=a[j+1])j = Shift[j];
		if(a[i]==a[j+1])j++;
		Shift[i] = j;
	}
}

int main()
{
	File(code);
	std::ios::sync_with_stdio(false);
	std::string s;
	std::cin>>s;
	while(s[0]!='.')
	{
		int n = s.size();
		Get_Shift(s);
		if((n%(n-(Shift[n-1]+1)))==0)std::cout<<n/(n-(Shift[n-1]+1))<<std::endl;
		else std::cout<<1<<std::endl;
		std::cin>>s;
	}
	return 0;
}
