#include<bits/stdc++.h>
using namespace std;

const int M = 1e6 + 10;
int a[M],num[M],vis[M],block,ans = 0,n,m;
struct node{
	int l,r,id;
	bool operator < (const node &cmp) const{
		if(l/block == cmp.l/block)  return r < cmp.r;
		return l/block < cmp.l/block;
	}
}q[M];

void add(int x){
	vis[a[x]]++;
	if(vis[a[x]] == 1) ans++;
}

void del(int x){
	vis[a[x]]--;
	if(vis[a[x]] == 0) ans--;
}

int main()
{
	scanf("%d",&n);
	block = sqrt(n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i = 1;i <= m;i ++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id = i;
	}
	sort(q+1,q+m+1);

	for (int i = 1; i <= m; i++)
		printf("%d %d\n", q[i].l, q[i].r);

	int l = 1,r = 0;
	for(int i = 1;i <= m;i ++){
		while(l < q[i].l) del(l),l++;
		while(l > q[i].l) l--,add(l);
		while(r < q[i].r) r++,add(r);
		while(r > q[i].r) del(r),r--;
		num[q[i].id] = ans;
	}
	for(int i = 1;i <= m;i ++)
		printf("%d\n",num[i]);
	return 0;

}
