#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
class Node
{
public:
	int v,w;
};
std::vector<Node> Map[30001];
int w[30001];

int Deep[30001];
void Dfs(int Now)
{
	for(std::vector<Node>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
	{
       	    Deep[it->v] = Deep[Now]+it->w;
	        Dfs(it->v);
		std::cout<<"$"<<Now<<" "<<Deep[Now]<<std::endl;
	}
}

int get_ans(int Now,int root,int Dist)
{
    for(std::vector<Node>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
	{
	    if(Deep[it->v])
	}
}

int father[300001];
int main()
{
	int n;
	std::cin>>n;
	for(int i = 0;i<n;i++)std::cin>>w[i];
	for(int i = 1;i<n;i++)
	{
	    int v,w;
	    std::cin>>v>>w;
	    v--;
	    Map[v].push_back((Node){i,w});
	    father[i] = v;
	}
        Dfs(0);
	for(int i = 0;i<n;i++)
	    {
		
	    }
	return 0;
}
