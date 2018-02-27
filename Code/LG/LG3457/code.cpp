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
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Father[1001];
int Get_father(int u){return father[u]==u?u:father[u] = Get_father(father[u]);}

class Node
{
public:
	int x,y,Val;
}Num[1000*1000];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
		Num[i][j] = gi;
	
	return 0;
}
