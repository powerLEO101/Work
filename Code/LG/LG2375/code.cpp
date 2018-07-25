#include<iostream>
#include<cstdio>
#include<algorithm>
#define _ 1000000+1
#define MOD 1000000007
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

int Shift[_],Num[_];

int main()
{
	File(code);
	std::string s;
	int n = gi;
	while(n--)
	{
		std::cin>>s;
		Shift[0] = -1;
		Num[1] = 1;
		int j = 0;
		for(int i = 1;i<s.size();i++)
		{
			while(j>-1&&s[i]!=s[j])j = Shift[j];
			j++;
			Shift[i+1] = j;
			Num[i+1] = Num[j]+1;
		}
		j = 0;
		long long Ans = 1;
		for(int i = 1;i<s.size();i++)
		{
			while(j>-1&&s[i]!=s[j])j = Shift[j];
			j++;
			while((j<<1)>(i+1))j = Shift[j];
			Ans*=(Num[j]+1);
			Ans%=MOD;
		}
		std::cout<<Ans<<std::endl;
	}
	return 0;
}
