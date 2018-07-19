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

int x[101],y[101],Num;
bool pd[10000];

void Get_ans(int Now,int Ans)
{
	if(Now==0)
		if(pd[Ans]==false)
		{
			pd[Ans] = true;
			Num++;
			return;
		}
		else return;
	int Temp = Ans;
	for(int i = x[Now];i<=y[Now];i++)
		Temp = Temp^(1<<i);
	Get_ans(Now-1,Temp);
	Get_ans(Now-1,Ans);
}

int main()
{
	File(steins);
	int T = gi;
	while(T--)
	{
		int n = gi,m = gi;
		for(int i = 0;i<m;i++)
			x[i] = gi,
			y[i] = gi;
		Get_ans(m,0);
		std::cout<<Num<<std::endl;
		Num = 0;
		memset(pd,0,sizeof(pd));
	}
	return 0;
}
