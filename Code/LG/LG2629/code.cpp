#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[1000001 << 1],Min1[1000001 << 1],Min2[1000001 << 1];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	memset(Min1,0x3f,sizeof(Min1));
	memset(Min2,0x3f,sizeof(Min2));
	Min1[0] = Num[0];
	Min2[n-1] = Num[n-1];
	for(int i = 1;i<n;i++)
		Num[i] += Num[i-1],
		Min1[i] = std::min(Min1[i-1],Num[i]);
	for(int i = n-1;i>=0;i--)
		Min2[i] = std::min(Min2[i+1],Num[i]);
	int Ans = 0;
	for(int i = 0;i<n;i++)
		if((Min2[i]-Num[i-1]>=0)&&((Min1[i]+(Num[n-1]-Num[i-1]))>=0))
			Ans++;
	std::cout<<Ans;
	return 0;
}
