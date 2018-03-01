#include<bits/stdc++.h>
#define RG register
#define file(x) freopen(#x".in", "rb", stdin);freopen(#x".out", "w+", stdout);
#define clear(x, y) memset(x, y, sizeof(x));
using namespace std;

namespace quickIO
{
	const int MAXS = (1<<23);
	char buf[MAXS], *p;
	int len;

	inline int read()
	{
		int data=0, w=1;
		char ch=*p++;
		while(ch!='-'&&(ch<'0'||ch>'9')&&p-buf<len&&(*p)) ch=*p++;
		if(ch=='-') w=-1, ch=*p++;
		while(ch>='0'&&ch<='9'&&p-buf<len&&(*p)) data=(data<<3)+(data<<1)+(ch^48), ch=*p++;
		return data*w;
	}

	inline void init()
	{
		len = fread(buf,1,MAXS,stdin);
		buf[len] = '\0';
		p=buf;
	}
}

using namespace quickIO;
const int maxn(100010);

struct node { int val, dis; node *son[2]; node(int v) { val=v; dis=1; son[0]=son[1]=NULL; } } *stk[maxn];
int tp, n, size[maxn], l[maxn], r[maxn], val[maxn];
inline int dis(node *x) { return x ? x->dis : 0; }
inline void update(node *x) { if(dis(x->son[0])< dis(x->son[1])) swap(x->son[0], x->son[1]); x->dis=dis(x->son[1])+1; }
inline node *merge(node *x, node *y)
{
	if(x==NULL) return y;
	if(y==NULL) return x;
	if(x->val < y->val) swap(x, y);
	x->son[1]=merge(x->son[1], y);
	update(x);
	return x;
}
inline int v(node *x) { return x ? x->val : 0; }

int main()
{
	init();
	n=read();
	for(RG int i=1;i<=n;i++)
	{
		val[i]=read();
		stk[++tp]=new node(val[i]);
		l[tp]=r[tp]=i; size[tp]=1;
		if(!(tp-1)) continue;
		while(v(stk[tp])<v(stk[tp-1]))
		{
			tp--; stk[tp]=merge(stk[tp], stk[tp+1]);
			r[tp]=r[tp+1]; size[tp]+=size[tp+1];
			while(size[tp]>((r[tp]-l[tp]+2)>>1)) stk[tp]=merge(stk[tp]->son[0], stk[tp]->son[1]), size[tp]--;
		}
	}
	long long ans=0;
	for(RG int i=1;i<=tp;i++)
		for(RG int j=l[i];j<=r[i];j++)
			ans+=abs(val[j]-v(stk[i]));
	printf("%lld\n", ans);
	return 0;
}
