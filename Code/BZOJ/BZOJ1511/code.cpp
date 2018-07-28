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

char Str[1000005];
int Shift[1000005];

int main()
{
	File(code);
	int Len = gi;
	scanf("%s",Str);
	Shift[0] = -1;
	int j = -1;
	for(int i = 1;i<Len;i++)
	{
		while(j>-1&&Str[i]!=Str[j+1])j = Shift[j];
		if(Str[i]==Str[j+1])j++;
		Shift[i] = j;
	}
	for(int i = 1;i<Len;i++)
		if(Shift[i]==-1)continue;
		else if(Shift[Shift[i]]!=-1)Shift[i] = Shift[Shift[i]];
	long long Ans = 0;
	for(int i = 0;i<Len;i++)
		if(Shift[i]!=-1)Ans+=(i-Shift[i]);
	std::cout<<Ans;
	return 0;
}
