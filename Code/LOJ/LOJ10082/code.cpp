#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 200005
#define for_edge(i,x) for(int i = Head[x];i!=-1;i = Edges[i].Next)
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

char Str[1001];

class Edge
{
public:
	int Next,To;
	double Value;
}Edges[_];
int Head[_],E_num,n;
double Max_edge = 0;
void Add_edge(int From,int To,double Value)
{
	Edges[E_num] = (Edge){Head[From],To,Value};
	Head[From] = E_num++;
}

bool Flag = false;
int Vis[_];
double Dist[_];
void SPFA(int Now,int Start,double x)
{
	if(Flag==true)return;
	Vis[Now] = Start;
	for_edge(i,Now)
	{
		int To = Edges[i].To;
		double Value = Edges[i].Value;
		if((Dist[To]-(Dist[Now]+Value-x))>=0.001)continue;
		Dist[To] = Dist[Now]+Value-x;
		if(Dist[To]>Max_edge)
		{
			Flag = true;
			return;
		}
		if(Vis[To]==-1)
			SPFA(To,Start,x);
		if(Flag==true)return;
		if(Vis[To]==Start)
		{
			Flag = true;
			return;
		}
	}
	Vis[Now] = -1;
}
bool Judge(double x)
{
	memset(Dist,0,sizeof(Dist));
	memset(Vis,-1,sizeof(Vis));
	for(int i = 0;i<800;i++)
	{
		if(Head[i]==-1)continue;
		SPFA(i,i,x);
		if(Flag==true)break;
	}
	if(Flag==true)
	{
		Flag = false;
		return true;
	}
	return false;
}

int main()
{
	File(code);
	n = gi;
	memset(Head,-1,sizeof(Head));
	for(int i = 0;i<n;i++)
	{
		scanf("%s",Str);
		int Len = strlen(Str);
		int From = (Str[0]-'a')+(Str[1]-'a')*26;
		int To = (Str[Len-2]-'a')+(Str[Len-1]-'a')*26;
		Max_edge = std::max(Max_edge,Len*1.0);
		Add_edge(From,To,Len);
	}
	Max_edge*=n;
	double l = 0,r = 10000,Ans = -1;
	while(r-l>=0.001)
	{
		double Mid = (l+r)/2;
		if(Judge(Mid)==true)
		{
			Ans = Mid;
			l = Mid;
		}
		else r = Mid;
	}
	if(Ans==-1)std::cout<<"No solution";
	else
		printf("%0.3lf",Ans);
	return 0;
}
