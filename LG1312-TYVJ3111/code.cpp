#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>

int Step,map[100][100],output[100][10];

void clear()
{
loop:
	for(int i = 1;i<7;i++)
	for(int j = 0;j<5;j++)
	{
		if(map[i][j]!=0&&map[i-1][j]==0)
		{
			int k = i;
			while(k>=1&&map[i-1][j]==0)
			{
				std::swap(map[k][j],map[k-1][j]);
				k--;
			}
		}
	}
	bool cls[100][100],can = false;
	for(int i = 0;i<5;i++)
	for(int j = 0;j<7;j++)
	{
		if(map[i][j]!=0&&map[i][j+1]==map[i][j]&&map[i][j+2]==map[i][j])
		{
			can = true;
			cls[i][j] = cls[i][j+1] = cls[i][j+2] = true;
		}
		if(map[i][j]!=0&&map[i+1][j]==map[i][j]&&map[i+2][j]==map[i][i])
		{
			can = true;
			cls[i][j] = cls[i+1][j] = cls[i+2][j] = true;
		}
	}
	if(can=false)return;
	for(int i = 0;i<7;i++)
	for(int j = 0;j<5;j++)
		if(cls[i][j]==true)
			map[i][j] = 0;
	goto loop;
}

void get_ans(int step)
{
	if(step==Step)
	{
		bool flag = false;
		for(int i = 0;i<7;i++)
		for(int j = 0;j<5;j++)
			if(map[i][j]!=0)flag = true;
		if(flag==false)
		{
			for(int i = 0;i<step;i++)std::cout<<output[i][0]<<" "<<output[i][1]<<" "<<output[i][2]<<std::endl;
			
		}
		exit(0);
	}
	int color[11];
	memset(color,0,sizeof(color));
	for(int i = 0;i<7;i++)
		for(int j = 0;j<5;j++)
			color[map[i][j]]++;
	for(int i = 0;i<11;i++)
		if(color[i]==1||color[i]==2)
			return;
	int now_map[100][100];
	memcpy(now_map,map,sizeof(map));
	for(int j = 0;j<5;j++)
		for(int i = 0;i<7;i++)
		{
			if(map[i][j]==0)continue;
			if(j!=4&&now_map[i][j]!=now_map[i][j+1])
			{
				memcpy(map,now_map,sizeof(now_map));
				std::swap(map[i][j],map[i][j+1]);
				clear();
				output[step][0] = i;
				output[step][1] = j;
				output[step][2] = 1;
				get_ans(step+1);
			}
			if(j!=0&&map[i][j-1]==0&&map[i][j]!=map[i][j-1])
			{
				memcpy(map,now_map,sizeof(now_map));
				std::swap(map[i][j],map[i][j-1]);
				clear();
				output[step][0] = i;
				output[step][1] = j;
				output[step][2] = -1;
				get_ans(step-1);
			}
		}
}

int main()
{
	std::cin>>Step;
	for(int i = 0;i<5;i++)
	{
		int temp,j = 0;
		std::cin>>temp;
		while(temp!=0)
		{
			map[j++][i] = temp;
			std::cin>>temp;
		}
	}
	std::cout<<123;
	get_ans(0);
	std::cout<<-1;
	return 0;
}
