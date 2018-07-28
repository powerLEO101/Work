#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

int Shift[15005];
char s[100001];

int main()
{
	File(code);
	scanf("%s",s);
	int Len = strlen(s);
	int Ans = 0;
	int k = gi;
	for(int x = 0;x<=Len;x++)
	{
		int j = x-1;
		Shift[x] = x-1;
		for(int i = x+1;i<Len;i++)
		{
			while(j>x-1&&s[i]!=s[j+1])j = Shift[j];
			if(s[i]==s[j+1])j++;
			Shift[i] = j;
		}
		j = x-1;
		for(int i = x+1;i<Len;i++)
		{
			while(j>x-1&&s[i]!=s[j+1])j = Shift[j];
			if(s[i]==s[j+1])j++;
			while(((j-x+1)<<1)>=(i-x+1))j = Shift[j];
			if((j-x+1)>=k)Ans++;
		}
	}
	std::cout<<Ans;
	return 0;
}
