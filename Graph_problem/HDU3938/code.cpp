#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<vector>

int father[50005],rank[50005];
void init()
{
	for(int i = 0;i<50005;i++)
	{
		father[i] = i;
		rank[i] = 1;
	}
}
int get_father(int u){return father[u]==u?u:father[u] = get_father(father[u]);}
void merge(int u,int v)
{
	a = get_father(a);b = get_father(b);
	if(a==b)return 0;
	father[a] = b;
	int ret = rank[a]*rank[b];
	rank[a] += rank[b];
	return ret;
}

class edge
{
public:
	int u,v,weight;
};
std::vector<edge> edges;
bool operator<(const edge& a,const edge& b){return a.weight<b.weight;}

class query
{
public:
	int l,id,ans;
};
std::vector<query> Query;
bool operator< (const query& a,const query& b){return a.l<b.l;}

int main()
{
	//std::ios::sync_with_stdio(false);
	int n,m,q;
	while(std::cin>>n>>m>>q)
	{
		init();
		edges.clear();
		Query.clear();
		for(int i = 0;i<m;i++)
		{
			int a,b,c;
			std::cin>>a>>b>>c;
			edges.push_back((edge){a,b,c});
		}
		for(int i = 1;i<=q;i++)
		{
			int l;
			std::cin>>l;
			Query.push_back((query){l,i,0});
		}
		std::sort(edges.begin(),edges.end());
		std::sort(Query.begin(),Query.end());
		int index = 0;
		for(int i = 0;i<q;i++)
		{
			 if()Query[i].ans =
		}
	}
	return 0;
}
