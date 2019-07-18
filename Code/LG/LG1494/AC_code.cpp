#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=50001;
int c[maxn];
int pos[maxn],bk;
int n,m;
int nl,nr;
long long cnt[maxn];
long long ncnt;
long long gcd(long long a,long long b){return b==0?a:gcd(b,a%b);}
struct qnode
{
	int l,r,id;
	long long cnt;
}q[maxn];
bool cmp_sp(qnode a,qnode b){return pos[a.l]<pos[b.l]||(pos[a.l]==pos[b.l]&&a.r<b.r);}
bool cmp_id(qnode a,qnode b){return a.id<b.id;}
inline void push(int x){ncnt+=cnt[c[x]]++;}
inline void pop(int x){ncnt-=--cnt[c[x]];}
void update(int l,int r)
{
	while(l<nl)push(--nl);
	while(r>nr)push(++nr);
	while(l>nl)pop(nl++);
	while(r<nr)pop(nr--);
	//printf("%d %d %lld\n",nl,nr,ncnt);
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		bk=ceil(sqrt(double(n)));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
			pos[i]=i/bk;
		}
		for(int j=0;j<m;j++)
		{
			scanf("%d%d",&q[j].l,&q[j].r);
			q[j].l--;q[j].r--;
			q[j].id=j;
			q[j].cnt=0;
		}
		sort(q,q+m,cmp_sp);
		nl=0,nr=-1,ncnt=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<m;i++)
		{
			update(q[i].l,q[i].r);
			q[i].cnt=ncnt;
		}
		sort(q,q+m,cmp_id);
		for(int i=0;i<m;i++)
		{
			//printf("%lld\n",q[i].cnt);
			long long aa=q[i].cnt,bb=(q[i].r-q[i].l+1)*(q[i].r-q[i].l)/2,cc=gcd(aa,bb);
			std :: cout << aa << ' ' << bb << std :: endl;
			aa/=cc,bb/=cc;
			if(aa)
				printf("%lld/%lld\n",aa,bb);
			else printf("0/1\n");
		}
	}
	return 0;
}
