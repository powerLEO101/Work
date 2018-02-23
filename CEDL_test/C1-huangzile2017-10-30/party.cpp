#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Edge{
public:	int u,v;
};
int Father[1001];
void Init(){for(int i = 0;i<1001;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}
bool Query(int u,int v){return Get_father(u)==Get_father(v);}
std::vector<Edge> Edges;
std::vector<int> Map[3003];

void Kruskal(){
	Init();
	for(int i = 0;i<Edges.size();i++){
		if(Query(Edges[i].u,Edges[i].v)==false){
			Merge(Edges[i].u,Edges[i].v);
			Map[Edges[i].u].push_back(Edges[i].v);
			Map[Edges[i].v].push_back(Edges[i].u);
		}
	}
}
void Get_dist(int v,int now,int dist,int& ans,int pre){
	if(now==v){
		ans = std::min(ans,dist);
		return;
	}
	for(std::vector<int>::iterator it = Map[now].begin();it!=Map[now].end();it++){
		if(*it==pre)continue;
		Get_dist(v,*it,dist+1,ans,now);
	}
}
bool G[10001];
bool Get(int v,int Now,int Dist,int Pre,int Ans){
	if(Now==v){
		if(Dist==Ans)return true;
		else return false;
	}
	for(std::vector<int>::iterator it = Map[Now].begin();it!=Map[Now].end();it++){
		if(*it==Pre)continue;
		if(Get(v,*it,Dist+1,Now,Ans)==true)
		{
			G[*it] = true;
			return true;
		}
	}
	return false;
}


int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++){
		int u = gi-1,v = gi-1;
		Edges.push_back((Edge){u,v});
	}
	int s1 = gi-1,t1 = gi-1,l1 = gi;
	int s2 = gi-1,t2 = gi-1,l2 = gi;
	Kruskal();
	int Ans1,Ans2,Ans = 0;
	Ans1 = Ans2 = 0x3f3f3f3f;
	Get_dist(t1,s1,0,Ans1,-1);
	Get_dist(t2,s2,0,Ans2,-1);
	if(Ans1>l1||Ans2>l2){
		std::cout<<"That's all trouble!";
		return 0;
	}
	Get(t1,s1,0,-1,Ans1);
	Get(t2,s2,0,-1,Ans2);
	for(int i = 0;i<n;i++)
		if(G[i]==false)Ans++;
	std::cout<<Ans-1;
	return 0;
}
