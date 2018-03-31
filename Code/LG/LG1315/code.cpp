#include<iostream>
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

class P
{
public:
	int t,a,b;
}People[10001];
int LeavePeople[1001],LastTime[1001],ArriveTime[1001],Dist[1001],Interval[1001];

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,k = gi,Ans = 0;
	for(int i = 0;i<n-1;i++)Dist[i] = gi;
	for(int i = 0;i<m;i++)
	{
		People[i].t = gi;
		People[i].a = gi-1;
		People[i].b = gi-1;
		LastTime[People[i].a] = std::max(LastTime[People[i].a],People[i].t);
		LeavePeople[People[i].b]++;
	}
	for(int i = 1;i<n;i++)
		LeavePeople[i] += LeavePeople[i-1];
	ArriveTime[0] = LastTime[0];
	for(int i = 1;i<n;i++)
		ArriveTime[i] = std::max(ArriveTime[i-1],LastTime[i-1])+Dist[i-1];
	for(int i = 0;i<m;i++)Ans += (ArriveTime[People[i].b]-People[i].t);
	while(k--)
	{
		int Max = 0;
		Interval[n-1] = Interval[n-2] = n-1;
		for(int i = n-3;i>=0;i--)
			 Interval[i] = ArriveTime[i+1]<=LastTime[i+1]?i+1:Interval[i+1];
		int Val = 1000;
		for(int i = 0;i<n;i++)
			if((LeavePeople[Interval[i]]-LeavePeople[i])>Max&&Dist[i]>0)
			{
				Val = i;
				Max = LeavePeople[Interval[i]]-LeavePeople[i];
			}
		Dist[Val]--;
		Ans-=Max;
		for(int i = 1;i<n;i++)
			ArriveTime[i] = std::max(ArriveTime[i-1],LastTime[i-1])+Dist[i-1];
	}
	std::cout<<Ans;
	return 0;
}
