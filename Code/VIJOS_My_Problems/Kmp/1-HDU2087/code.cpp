#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 1000005
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Shift[_];

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
			j = -1;
		}
	}
	std::cout<<Ans<<std::endl;
}

int main()
{
	File(code);
	std::string a,b;
	std::cin>>a;
	while(a!="#")
	{
		std::cin>>b;
		Get_Shift(b);
		Kmp(a,b);
		std::cin>>a;
		memset(Shift,0,sizeof(Shift));
	}
	return 0;
}

