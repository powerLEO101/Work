#include<iostream>
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

int Num[1001];

int Judge(int x,int y){return y==0?x:Judge(y,x%y);}

int Phi(int Val)
{
	int Ans = 0;
	for(int i = 1;i<=Val;i++)
		Ans+=Judge(Val,i)==1;
	return Ans;
}

int main()
{
	freopen("phi.in","r",stdin);
	freopen("phi.out","w",stdout);
	int n = gi,q = gi;
	for(int i = 0;i<n;i++)Num[i] = gi;
	for(int i = 0;i<q;i++)
	{
		int Mode = gi;
		if(Mode==0)
		{
			int Index = gi-1,x = gi;
			Num[Index] = x;
		}
		if(Mode==1)
		{
			int l = gi-1,r = gi;
			int Ans = 0;
			for(int i = l;i<r;i++)Ans+=Num[i];
			std::cout<<Phi(Ans)<<std::endl;
		}
		if(Mode==2)
		{
			int l = gi-1,r = gi;	
			int Ans = 1;
			for(int i = l;i<r;i++)Ans*=Num[i];
			std::cout<<Phi(Ans)<<std::endl;
		}
	}
	return 0;
}
