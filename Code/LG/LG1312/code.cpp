#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[10][10],n;
bool State[10][10];

void Copy(int a[10][10],int b[10][10])
{
	for(int i = 0;i<10;i++)
	for(int j = 0;j<10;j++)
		a[i][j] = b[i][j];
}
bool Clear(int map[10][10])
{
	for(int i = 0;i<5;i++)
		for(int j = 0;j<7;j++)
		{
			if(map[i][j]==0)continue;
			if(map[i][j]!=-1)continue;
			map[i][j] = map[i][j+1];
			map[i][j+1] = -1;
		}
	for(int i = 0;i<5;i++)
	for(int j = 0;j<7;j++)
		if(map[i][j]==-1)map[i][j] = 0;
	memset(State,0,sizeof(State));
	for(int i = 0;i<5;i++)
	for(int j = 1;j<6;j++)
		if(map[i][j]==map[i][j-1]&&map[i][j]==map[i][j+1]&&map[i][j]!=0)
			State[i][j] = State[i][j+1] = State[i][j-1] = true;
	for(int j = 0;j<7;j++)
	for(int i = 1;i<4;i++)
		if(map[i][j]==map[i-1][j]&&map[i][j]==map[i+1][j]&&map[i][j]!=0)
			State[i][j] = State[i+1][j] = State[i-1][j] = true;
	bool Ret = false;
	for(int i = 0;i<5;i++)
	for(int j = 0;j<7;j++)
	{
		if(State[i][j]==true)
		{
			map[i][j] = -1,
			Ret = true;
			std::cout<<"#"<<i<<" "<<j;
		}
	}
	for(int i = 0;i<5;i++)
	{
		for(int j = 0;j<7;j++)
			std::cout<<map[i][j]<<" ";
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
	std::cout<<Ret<<std::endl;
	return Ret;
}
bool Judge(int map[10][10])
{
	for(int i = 0;i<5;i++)
	for(int j = 0;j<7;j++)
		if(map[i][j]!=0)return false;
	return true;
}
class Node
{
public:
	int x,y,Mode;
};
std::vector<Node> Steps;
bool Get_ans(int Step)
{
	if(Judge(Map)==true)return true;
	if(Step==n)return false;
	int Map1[10][10];Copy(Map1,Map);
	while(Clear(Map)==true);
	for(int i = 0;i<5;i++)
	for(int j = 0;j<7;j++)
	{
		if(Map[i][j]==0)continue;
		if(i!=0)
		{
			std::swap(Map[i][j],Map[i-1][j]);
			if(Get_ans(Step+1)==true)
			{
				Steps.push_back((Node){i+1,j+1,-1});
				return true;
			}
		}
		Copy(Map,Map1);
		if(i!=4)
		{
			std::swap(Map[i][j],Map[i+1][j]);
			if(Get_ans(Step-1)==true)
			{
				Steps.push_back((Node){i+1,j+1,1});
				return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	n = gi;
	for(int i = 0;i<5;i++)
	{
		int Num = gi,Index = 0;
		while(Num!=0)
		{
			Map[i][Index++] = Num;
			Num = gi;
		}
	}
	if(Get_ans(0)==false)std::cout<<-1;
	else
	{
		for(int i = Steps.size()-1;i>=0;i--)
			std::cout<<Steps[i].x<<" "<<Steps[i].y<<" "<<Steps[i].Mode<<std::endl;
	}
	return 0;
}
