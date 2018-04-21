#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define gi get_int()
#define INF 0x3f3f3f3f
#define File(name) freopen(#name".in","r",stdin);freopen(#name".out","w",stdout)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[101][101],Skip[101][101][4][4];
int n,m,q;
Pos F[4],FF[4];

struct Pos
{
	int x,y;
	Pos(int a,int b):x(a), y(b) {}
	Pos operator+ (const Pos& a,const Pos& b)const
	{
		a.x+=b.x;
		a.y+=b.y;
	}
	bool operator== (const Pos& a,const Pos& b)const
	{
		if(a.x==b.x&&a.y==b.y)return true;
		return false;
	}
};
struct Data
{
	int x,y,f;
};

bool Vis[101][101];
int Bfs(Pos S,Pos T)
{
	if(Map[S.x][S.y]==0||Map[T.x][T.y]==0)return INF;
	std::queue<Pos> Q;
	std::queue<int> Dist;
	Q.push(S);
	Q.push(0);
	Vis[S.x][S.y] = true;
	while(!Q.empty())
	{
		Pos Now = Q.front();Q.pop();
		int D = Dist.front();Dist.pop();
		for(int i = 0;i<4;i++)
		{
			Pos Temp = Now+F[i];
			if(Map[Temp.x][Temp.y]==0||Vis[Temp.x][Temp.y]==true)continue;
			Vis[Temp.x][Temp.y] = true;
			if(Temp==T)return D+1;
			Q.push(Temp);
			Dist.push(D+1);
		}
		Vis[Now.x][Now.y] = true;
	}
	return INF;
}
void Init()
{
	F[0] = F[1] = (Pos){-1,0};
	F[1] = F[0] = (Pos){1,0};
	F[2] = F[3] = (Pos){0,-1};
	F[3] = F[2] = (Pos){0,1};
	memset(Skip,0x3f,sizeof(Skip));
	for(int i = 0;i<n;i++)
	for(int j = 0;j<m;j++)
	{
		if(Map[i][j]==0)continue;
		Map[i][j] = 0;
		Pos Now(i,j);
		for(int a = 0;a<4;a++)
		for(int b = 0;b<4;b++)
		{
			if(a>b)
				Skip[i][j][a][b] = Skip[i][j][b][a];
			else Skip[i][j][a][b] = Bfs(Now+F[a],Now+F[b])+1;
		}
		Map[i][j] = 1;
	}
}

int main()
{
	File(code);
	n = gi,m = gi,q = gi;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
		Map[i][j] = gi;
	Init();
	std::queue<Data> Q;
	while(q--)
	{
		int Ex = gi,Ey = gi,Sx = gi,Sy = gi,Tx = gi,Ty = gi;
		if(Map[Sx][Sy]==0||Map[Tx][Ty]==0)
		{
			std::cout<<-1<<std::endl;
			continue;
		}
		if(Sx==Tx&&Sy==Ty)
		{
			std::cout<<0<<std::endl;
			continue;
		}
		std::cout<<SPFA();
	}
	return 0;
}

