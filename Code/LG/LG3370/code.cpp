#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)

unsigned long long base = 233,a[10010];
unsigned long long Hash(std::string s)
{
	unsigned long long Ans = 0;
	for(int i = 0;i<s.size();i++)
		Ans = Ans*base+(unsigned long long)s[i];
	return Ans;
}
int main()
{
	File(code);
	std::string s;
	int n;
	std::cin>>n;
	for(int i = 0;i<n;i++)
	{
		std::cin>>s;
		a[i] = Hash(s);
	}
	std::sort(a,a+n);
	int Ans = 1;
	for (int i = 1;i<n;i++)
		if (a[i]!=a[i-1])
			Ans++;
	std::cout<<Ans;
}
