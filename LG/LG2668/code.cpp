#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f

namespace file
{
	std::ifstream cin("landlords.in");
	std::ofstream cout("landlords.out");
}

int Card[100],Num[100],Ans = INF;

int Get()
{
	memset(Num,0,sizeof(Num));
	for(int i = 0;i<=13;i++)Num[Card[i]]++;
	int Temp_Ans = 0;
	while(Num[4]&&Num[2]>1)
	{
		Num[4]--;Num[2]-=2;
		Temp_Ans++;
	}
	while(Num[4]&&Num[1]>1)
	{
		Num[4]--;Num[1]-=2;
		Temp_Ans++;
	}
	while(Num[4]&&Num[2])
	{
		Num[4]--;Num[2]--;
		Temp_Ans++;
	}
	while(Num[3]&&Num[2])
	{
		Num[3]--;Num[2]--;
		Temp_Ans++;
	}
	while(Num[3]&&Num[1])
	{
		Num[3]--;Num[1]--;
		Temp_Ans++;
	}
	return Temp_Ans+Num[1]+Num[2]+Num[3]+Num[4];
}
void Get_ans(int Step)
{
	if(Step>=Ans)return;
	int Temp = Get();
	if(Temp+Step<Ans)Ans = Temp+Step;
	for(int i = 2;i<=13;i++)
	{
		int Count = i;
		while(Card[Count]>=3)Count++;
		if(Count-i>=2)
		{
			for(int j = i+1;j<Count;j++)
			{
				for(int k = i;k<=j;k++)Card[k]-=3;
				Get_ans(Step+1);
				for(int k = i;k<=j;k++)Card[k]+=3;
			}
		}
	}
	for(int i = 2;i<=13;i++)
	{
		int Count = i;
		while(Card[Count]>=2)Count++;
		if(Count-i>=3)
		{
			for(int j = i+2;j<Count;j++)
			{
				for(int k = i;k<=j;k++)Card[k]-=2;
				Get_ans(Step+1);
				for(int k = i;k<=j;k++)Card[k]+=2;
			}
		}
	}
	for(int i = 2;i<=13;i++)
	{
		int Count = i;
		while(Card[Count]>=1)Count++;
		if(Count-i>=5)
		{
			for(int j = i+4;j<Count;j++)
			{
				for(int k = i;k<=j;k++)Card[k]--;
				Get_ans(Step+1);
				for(int k = i;k<=j;k++)Card[k]++;
			}
		}
	}
}

int main()
{
	int T,n;
	file::cin>>T>>n;
	while(T--)
	{
		memset(Card,0,sizeof(Card));
		for(int i = 0;i<n;i++)
		{
			int Temp,x;
			file::cin>>x>>Temp;
			if(x==1)x = 13;
			else if(x!=0) x--;
			Card[x]++;
		}
		Ans = INF;
		Get_ans(0);
		file::cout<<Ans<<std::endl;
	}
	return 0;
}
