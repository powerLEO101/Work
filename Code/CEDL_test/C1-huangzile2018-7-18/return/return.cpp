#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 200001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int v,w,a;
};
std::vector<Node> Map[_];
int n,m,Dis[_];
bool inq[_];

void CASE1()
{
	memset(Dis,0x3f,sizeof(Dis));
	Dis[1] = 0;
	std::queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int Now = Q.front();
		Q.pop();inq[Now] = false;
		for(std::vector<Node>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		{
			int v = it->v,w = it->w;
			if(Dis[Now]+w>=Dis[v])continue;
			Dis[v] = Dis[Now]+w;
			if(inq[v]==false)
			{
				inq[v] = true;
				Q.push(v);
			}
		}
	}
	int q = gi,K = gi,S = gi,LastAns = 0;
	while(q--)
	{
		int v = (gi+K*LastAns-1)%n+1;
		int p = (gi+K*LastAns)%(S+1);
		if(p==0)std::cout<<0<<std::endl;
		else std::cout<<Dis[v]<<std::endl;
	}
}
void CASE2()
{
	memset(Dis,0x3f,sizeof(Dis));
	Dis[1] = 0;
	std::queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int Now = Q.front();
		Q.pop();inq[Now] = false;
		for(std::vector<Node>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
		{
			int v = it->v,w = it->w;
			if(Dis[Now]+w>=Dis[v])continue;
			Dis[v] = Dis[Now]+w;
			if(inq[v]==false)
			{
				inq[v] = true;
				Q.push(v);
			}
		}
	}
	int q = gi,K = gi,S = gi,LastAns = 0;
	while(q--)
	{
		int v = (gi+K*LastAns-1)%n+1;
		int p = (gi+K*LastAns)%(S+1);
		if(p==0)std::cout<<0;
		else
		{
			int Now = v;
			while(Now!=1)
			{
				bool f = false;
				for(std::vector<Node>::iterator it = Map[Now].begin();it!=Map[Now].end();it++)
				{
					if(it->v==Now-1)
					{
						if(it->a<=p)
						{
							f = true;
							break;
						}
					}
				}
				if(f==true)break;
				Now--;
			}
			std::cout<<Dis[Now]<<std::endl;
		}
	}
}

int main()
{
	File(return);
	int T = gi;
	while(T--)
	{
		n = gi,m = gi;
		bool Flag1 = true,Flag2 = true;
		for(int i = 0;i<m;i++)
		{
			int u = gi,v = gi,l = gi,a = gi;
			if(a!=1)Flag1 = false;
			if(u+1!=v)Flag2 = false;
			Map[u].push_back((Node){v,l,a});
			Map[v].push_back((Node){u,l,a});
		}
		if(Flag1==true)CASE1();
		if(Flag2==true)CASE2();
	}
	return 0;
}
