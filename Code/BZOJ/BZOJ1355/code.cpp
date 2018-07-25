#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
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

int main()
{
	File(code);
	int n = gi;
	std::string s;
	std::cin>>s;
	int j = -1;
	Shift[0] = -1;
	for(int i = 1;i<n;i++)
	{
		while(j>-1&&s[i]!=s[j+1])j = Shift[j];
		if(s[i]==s[j+1])j++;
		Shift[i] = j;
	}
	std::cout<<n-(Shift[n-1]+1);
	return 0;
}

