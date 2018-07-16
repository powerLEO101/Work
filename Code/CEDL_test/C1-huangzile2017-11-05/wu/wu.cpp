#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<deque>
#define MOD 1000000009
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int main()
{
	freopen("wu.in","r",stdin);
	freopen("wu.out","w",stdout);
	int n,A,B,C,x,a,b,Mod;
	std::cin>>n>>A>>B>>C>>x>>a>>b>>Mod;
	long long Val = -MOD-1,Num = 0,Ans = 0;
	std::deque<int> Q;
	for(int i = 0;i<n;i++)
	{
		x = (x*a+b)%Mod;
		if(Q.size()<=1||x%(A+B+C)<A)Q.push_front(x);
		else if((x%(A+B+C))<(A+B))Q.push_back(x);
		else if(A+B<=(x%(A+B+C)))
		{
			int val = Q.front();
			if(val==Val)Num--;
			Q.pop_front();
			if(Num==0)
			{
				Val = -MOD-1;
				Num = 0;
				for(int j = 0;j<Q.size();j++)
					if(Val<Q[j])Val = Q[j],Num = 1;
					else if(Val==Q[j])Num++;
			}
		}
		if(!(A+B<=(x%(A+B+C))))
		{
			if(x>Val)
			{
				Val = x;
				Val %= Mod;
				Num = 1;
			}
			if(x==Val)Num++;
		}
		Ans = (Ans+Val)%MOD;
	}
	std::cout<<Ans;
	return 0;
}

