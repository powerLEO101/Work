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

int Shift[101],Ans = 0,Num[101],n,S;
std::string s;
bool check()
{
	for(int i = 0;i<n/2;i++)
		if(Num[i]!=Num[n-i-1])return false;
	int Count = 0;
	int j = -1;
	for(int i = 0;i<n;i++)
	{
		while(j>-1&&Num[i]!=(s[j+1]-'0'))j = Shift[j];
		if(Num[i]==(s[j+1]-'0'))j++;
		if(j==s.size()-1)
		{
			j = -1;
			Count++;
		}
	}
	if(Count>=2)return false;
	return true;
}
void Get_ans(int Now)
{
	if(Now==0)
	{
		if(check()==true)Ans++;
		return;
	}
	Get_ans(Now-1);
	Num[Now-1] = 1;
	Get_ans(Now-1);
	Num[Now-1] = 0;
}
void Get_Shift(std::string s)
{
	int j = -1;
	Shift[0] = -1;
	for(int i = 1;i<s.size();i++)
	{
		while(j>-1&&s[i]!=s[j+1])j = Shift[j];
		if(s[i]==s[j+1])j++;
		Shift[i] = j;
	}
}

int main()
{
	File(str);
	n = gi,S = gi;
	std::cin>>s;
	Get_Shift(s);
	Get_ans(n);
	std::cout<<Ans;
	return 0;
}
