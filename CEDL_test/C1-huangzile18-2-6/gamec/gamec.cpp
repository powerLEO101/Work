#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<string>
#define gi get_int()

int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

bool state[5000001];

int main()
{
	freopen("gamec.in","r",stdin);
	freopen("gamec.out","w",stdout);
	std::string s;
	int n;
	std::cin>>s>>n;
	while(true)
	{
		int Pre = -1;
		for(int i = 0;i<s.size();i++)
		{
			if(state[i]==true)continue;
			int Num = s[i]-'0';
			int j = i+1;
			int Next;
			while(state[j]==true&&j<s.size())j++;
			if(j==s.size())Next = -1;
			else Next = s[j]-'0';
			if(Num>=Next&&Num>=Pre)state[i] = true,n--;
			Pre = Num;
			if(n==0)
			{
				bool flag = false;
				for(int i = 0;i<s.size();i++)
				{
					if(flag==false&&s[i]=='0')continue;
					if(state[i]==false)
					{
						flag = true;
						char c = s[i];
						putchar(c);
					}
				}
				return 0;
			}
		}
	}
	return 0;
}
