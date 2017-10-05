#include<bits/stdc++.h>
#define RG register
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;

class quickIO
{
	private:
		inline int read()
		{
			int data=0,w=1; char ch=0;
			while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
			if(ch=='-') w=-1,ch=getchar();
			while(ch>='0' && ch<='9') data=data*10+ch-'0',ch=getchar();
			return data*w;
		}
		inline void print(const int &a, bool tag)
		{
			int x=a;
			if(x<0)
			{
				putchar('-');
				x=-x;
			}
			if(x==0&&tag) putchar('0');
			else if(x==0) return;
			else
			{
				print(x/10,false);
				putchar(x%10+'0');
			}
		}
	public:
		quickIO &operator>>(int &x)
		{
			x=read();
			return *this;
		}
		quickIO &operator<<(const int &x)
		{
			print(x,true);
			return *this;
		}
		quickIO &operator<<(const char &ch)
		{
			putchar(ch);
			return *this;
		}
}qio;

struct edge
{
	int next, to, dis;
};

const int I=2147483647;

struct graph
{
	int head[1010];
	int e_num;
	edge e[100010];
	int c[1010];
	bool b[1010];
	int point;
	graph(int p):point(p){}
	
	void add_edge(int from, int to, int dis)
	{
		e[++e_num]={head[from],to,dis};
		head[from]=e_num;
	}

	void dijkstra(int st=1)
	{
		for(RG int i=1;i<=point;i++) c[i]=I;
		c[st]=0;
		b[st]=true;
		for(RG int i=head[st];i!=0;i=e[i].next)
		{
			c[e[i].to]=e[i].dis;
		}
		while(1)
		{
			int _min=I,_min_i=0;
			for(RG int i=1;i<=point;i++)
			{
				if(c[i]<_min&&(!b[i])) _min=c[i],_min_i=i;
			}
			if(_min==I) return;
			b[_min_i]=true;
			for(RG int i=head[_min_i];i!=0;i=e[i].next)
			{
				if(!b[e[i].to])
					c[e[i].to]=min(c[e[i].to],c[_min_i]+e[i].dis);
			}
		}
	}

	int dijans(int i)
	{
		return c[i];
	}
};

int n,m,from,to,dis;

int main()
{
	qio>>n>>m;
	graph g(n),rg(n);
	for(int i=1;i<=m;i++)
	{
		qio>>from>>to>>dis;
		g.add_edge(from,to,dis);
		rg.add_edge(to,from,dis);
	}
	g.dijkstra();
	rg.dijkstra();
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		ans+=g.dijans(i)+rg.dijans(i);
	}
	qio<<ans;
	return 0;
}
