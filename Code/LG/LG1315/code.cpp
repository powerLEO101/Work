#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f

int Peoplel[10001],Peopler[10001];
int Dist[10001];
int LastTime[10001],LeaveTime[10001],LastTime[10001];
int Time[10001],MaxInterval[10001],Sum[10001];

void Init(int n)
{
	LeaveTime[0] = LastTime[0];
	for(int i = 1;i<n;i++)
		LeaveTime[i] = std::max(LeaveTime[i-1],LastTime[i-1])+Dist[i-1];
}

int main()
{
	int n,m,k;
	std::cin>>n>>m>>K;
	for(int i = 1;i<n;i++)
		std::cin>>Dist[i-1];
	for(int i = 0;i<m;i++)
	{
		std::cin>>Time[i]>>Peoplel[i]>>Peopler[i];
		LastTime[Peoplel[i]] = std::max(LastTime[Peoplel[i]],Time[i]);
		Sum[i]++;
	}
	for(int i = 1;i<n;i++)Sum[i]+=Sum[i-1];
	Init();int Ans = 0;
	for(int i = 0;i<m;i++)Ans+=LeaveTime[PeopleTime[i]]-Time[i];
	while(k--)
	{
		MaxInterval[n] = MaxInterval[n-1] = n;
		for(int i = n-2;i>=0;i--)
			MaxInterval[i] = LeaveTime[i]<LastTime[i]?i:MaxInterval[i+1];
		int Max = -INF,Index;
		for(int i = 0;i<n;i++)
		{
			if(Sum[Peoplel[i]]-Sum[])
		}
	}
	return 0;
}
