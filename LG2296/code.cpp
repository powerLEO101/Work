#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>

std::vector<int> Map[10001];
std::vector<int> map[10001];

bool Can[10001];
void Bfs(int End)
{
	Can[End] = true;
	std::queue<int> Now;
	Now.push_back(End);
	while(!Now.empty())
	{
		int temp1 = Now.front();
		Now.pop();
		for(std::vector<int>::iterator it = Map[temp1].begin();it!=Map[temp1].end();it++)
		{
			if(Can[*it]==true)continue;
			Can[*it] = true;
			Now.push(*it);
		}
	}
}

void Get_ans(int S,int E)
{
	
}

int main()
{
	int n,m,s,t;
	std::cin>>n>>m>>s>>t;
	for(int i = 0;i<m;i++)
	{
		int u,v;
		std::cin>>u>>v;
		map[u].push_back(v);
		Map[v].push_back(u);
	}
	
	return 0;
}
