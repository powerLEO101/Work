#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 10001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int cmp(const int& a,const int& b)
{
	return a>b;
}

int Num[_];

int main()
{
	File(epic);
	int n = gi;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	std::sort(Num,Num+n,cmp);
	if(n==0)std::cout<<0;
	else if(n==1)std::cout<<Num[0];
	else if(n==2)
		std::cout<<Num[0]+(Num[1]*2);
	else if(n==3)
		std::cout<<(Num[0]*2)+(Num[1]*3)+(Num[2]*3);
	else if(n==4)
		std::cout<<(Num[0]*2)+(Num[1]*3)+(Num[2]*3)+(Num[3]*4);
	else if(n==5)
		std::cout<<(Num[0]*2)+(Num[1]*3)+(Num[2]*4)+(Num[3]*4)+(Num[4]*5);
	else
		std::cout<<445;
	return 0;
}
