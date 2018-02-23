#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

bool Num[1001][1001];
int f[1001][1001];
int main()
{
	freopen("col.in","r",stdin);
	freopen("col.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
		Num[i][j] = gi;
	f[0][0] = Num[0][0];
	for(int i = 0;i<n;i++)f[0][i] = f[0][i-1]+Num[0][i];
	for(int i = 0;i<n;i++)f[i][0] = f[i-1][0]+Num[i][0];
	for(int i = 1;i<n;i++)
	for(int j = 1;j<m;j++)
		f[i][j] = f[i-1][j-1]+f[i-1][j]+f[i][j-1]-2*f[i-1][j-1]+Num[i][j];
	int k = gi;
	for(int pp = 0;pp<k;pp++)
	{
		int x1 = gi-1,y1 = gi-1,x2 = gi-1,y2 = gi-1;
		int temp = std::min(x2-x1,y2-y1);
		std::cout<<"& "<<temp<<std::endl;
		for(int i = x1;i<=x2;i++)
		for(int j = y1;j<=y2;j++)
		for(int k = 0;k<=temp;k++)
		{
			int a = i,b = j,c = a+k,d = b+k;
			if(c>=n||d>=m)continue;
			int Temp = f[i][j]+f[x1-1][y1-1]-f[x2][y1-1]-f[x1-1][y2];
			std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<" : "<<Temp<<std::endl;
		}
	}
	return 0;
}
