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

short Temp[3002],Id[3002];
class Edge{
public:
	short  u,v,w;
}Edges[16010000];
bool operator< (const Edge& a,const Edge& b){
	return a.w<b.w;
}
int Father[3002];
void Init(){for(int i = 0;i<3002;i++)Father[i] = i;}
int Get_father(int u){return Father[u]==u?u:Father[u] = Get_father(Father[u]);}
void Merge(int u,int v){Father[Get_father(u)] = Get_father(v);}
bool Query(int u,int v){return Get_father(u)==Get_father(v);}

int Kruskal(int len){
	std::sort(Edges,Edges+len);
	Init();
	int Ans = 0;
	for(int i = 0;i<len;i++){
		if(Query(Edges[i].u,Edges[i].v)==true)continue;
		Merge(Edges[i].u,Edges[i].v);
		Ans+=Edges[i].w;
	}
	return Ans;
}

int main(){
	freopen("resource.in","r",stdin);
	freopen("resource.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<m;i++)
		Temp[i] = gi,Id[i] = gi;
	int Index = 0;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<n;j++){
			int w = gi;
			Edges[Index++] = (Edge){i,j,w};
		}
	for(int i = 0;i<m;i++)
		Edges[Index++] = (Edge){Id[i],n+1,Temp[i]};
	std::cout<<Kruskal(Index);
	return 0;
}
