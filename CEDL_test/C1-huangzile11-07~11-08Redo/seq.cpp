#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while ((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if (ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[1001];

int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int n = gi,Ans = 0;
	for(int i = 0;i<n;i++)
		std::cin>>Num[i];
	for(int a = 0;a<n;a++)
	for(int b = a+1;b<n;b++)
	for(int c = b+1;c<n;c++)
		if(Num[a]<Num[c]&&Num[c]<Num[b])Ans++;
	std::cout<<Ans;
	return 0;
}
