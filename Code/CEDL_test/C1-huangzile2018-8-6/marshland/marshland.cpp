#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 1001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[_][_],n,m,k,Map[_][_],Ans;

int Calc()
{
	int Count = 0;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			Count+=Num[i][j];
	return Count;
}
bool Judge(int x,int y)
{
	if(x<=0||y<=0||x>n||y>n)return false;
	if(Map[x][y]==-1)return false;
	return true;
}
void Get_ans(int Nowx,int Nowy,int Now = m)
{
	if(Nowy==n+1||Now==0)
	{
		Nowy = 1;
		Nowx++;
	}
	if(Nowx==n+1&&Nowy==1)
	{
		Ans = std::min(Ans,Calc());
		return;
	}
	if(Num[Nowx][Nowy]==0||Map[Nowx][Nowy]==-1)
	{
		Get_ans(Nowx,Nowy+1);
		return;
	}
	int Temp = Num[Nowx][Nowy];
	if(Judge(Nowx+1,Nowy)==true&&Judge(Nowx,Nowy+1)==true)
	{
		Num[Nowx][Nowy] = 0;
		Map[Nowx+1][Nowy] = -1;
		Map[Nowx][Nowy+1] = -1;
		Get_ans(Nowx,Nowy+1,Now-1);
		Num[Nowx][Nowy] = Temp;	
		Map[Nowx+1][Nowy] = 0;
		Map[Nowx][Nowy+1] = 0;
	}
	if(Judge(Nowx+1,Nowy)==true&&Judge(Nowx,Nowy-1)==true)
	{
		Num[Nowx][Nowy] = 0;
		Map[Nowx+1][Nowy] = -1;
		Map[Nowx][Nowy-1] = -1;
		Get_ans(Nowx,Nowy+1,Now-1);
		Num[Nowx][Nowy] = Temp;
		Map[Nowx+1][Nowy] = 0;
		Map[Nowx][Nowy-1] = 0;
	}
	if(Judge(Nowx-1,Nowy)==true&&Judge(Nowx,Nowy+1)==true)
	{
		Num[Nowx][Nowy] = 0;
		Map[Nowx-1][Nowy] = -1;
		Map[Nowx][Nowy+1] = -1;
		Get_ans(Nowx,Nowy+1,Now-1);
		Num[Nowx][Nowy] = Temp;
		Map[Nowx-1][Nowy] = 0;
		Map[Nowx][Nowy+1] = 0;
	}
	if(Judge(Nowx-1,Nowy)==true&&Judge(Nowx,Nowy-1)==true)
	{
		Num[Nowx][Nowy] = 0;
		Map[Nowx-1][Nowy] = -1;
		Map[Nowx][Nowy-1] = -1;
		Get_ans(Nowx,Nowy+1,Now-1);
		Num[Nowx][Nowy] = Temp;
		Map[Nowx-1][Nowy] = 0;
		Map[Nowx][Nowy-1] = 0;
	}
	Get_ans(Nowx,Nowy+1,Now);
}

int main()
{
	File(marshland);
	Ans = 0x3f3f3f3f;
	n = gi,m = gi,k = gi;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			Num[i][j] = gi;
	for(int i = 0;i<k;i++)
	{
		int x = gi,y = gi;
		Map[x][y] = -1;
	}
	Get_ans(1,1);
	std::cout<<Ans;
	return 0;
}
