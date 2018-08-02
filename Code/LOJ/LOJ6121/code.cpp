#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[1001][1001],Keys[1001];
int n,m,k;

class Edge
{
public:
	int Next,To,Value;
}Edges[1000005];
int E_num,Head[1000005];
void Add_edge(int From,int To,int Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}
bool Can(int x,int q){return x&(1<<(q-1));}
bool Judge(int x,int y,int Num)
{
	if(x<0||y<0||x>=n*m||y>=n*m)return false;
	if(Map[x][y]==-1)return true;
	if(Map[x][y]==0)return false;
	if(Map[x][y]>=1&&Can(Num,Map[x][y]))return true;
	return false;
}
void Build_Inside(int x,int Num)
{
	for(int i = 0;i<n*m;i++)
	{
		if(Judge(i,i+m,x)==true)
			Add_edge(i+Num*n*m,(i+m)+Num*n*m,1);
		if(Judge(i,i-m,x)==true)
			Add_edge(i+Num*n*m,(i-m)+Num*n*m,1);
		if(((i+1)%m)!=0&&Judge(i,i+1,x)==true)
			Add_edge(i+Num*n*m,(i+1)+Num*n*m,1);
		if(((i+1)%m)!=1&&Judge(i,i-1,x)==true)
			Add_edge(i+Num*n*m,(i-1)+Num*n*m,1);
	}
}

void Build_Outside(int Key_num)
{
	for(int i = 0;i<Key_num;i++)
		for(int j = i*n*m;j<(i+1)*n*m;j++)
			if(Keys[j-(i*n*m)]!=0&&(i&Keys[j-(i*n*m)])==0)Add_edge(j,(j+(n*m*Keys[j-(i*n*m)])),0);
}

int Dist[120000],Queue[1000000];
bool Vis[120000];

void SPFA()
{
	std::queue<int> Q;
	memset(Dist,0x3f,sizeof(Dist));
	Dist[0] = 0;
	Vis[0] = true;
	Q.push(0);
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		Vis[Now] = false;
		for_edge(i,Now)
		{
			int v = Edges[i].To,w =Edges[i].Value;
			if(Dist[Now]+w>=Dist[v])continue;
			Dist[v] = Dist[Now]+w;
			if(Vis[v]==false)
			{
				Vis[v] = true;
				Q.push(v);
			}
		}
	}
}

int main()
{
	File(code);
	n = gi,m = gi;
	int p = gi;
	k = gi;
	memset(Map,-1,sizeof(Map));
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<k;i++)
	{
		int x1 = gi-1,y1 = gi-1,x2 = gi-1,y2 = gi-1,G = gi;
		Map[x1*m+y1][x2*m+y2] = Map[x2*m+y2][x1*m+y1] = G;
	}
	int s = gi;
	for(int i = 0;i<s;i++)
	{
		int x = gi-1,y = gi-1,q = gi;
		Keys[x*m+y] |= 1<<(q-1);
	}
	int Key_num = 1<<p;
	for(int i = 0;i<Key_num;i++)Build_Inside(i,i);
	Build_Outside(Key_num);
	SPFA();
	int Ans = INF;
	for(int i = 0;i<Key_num;i++)
		Ans = std::min(Ans,Dist[((i+1)*n*m)-1]);
	if(Ans==INF)std::cout<<-1;
	else std::cout<<Ans;
	return 0;
}
