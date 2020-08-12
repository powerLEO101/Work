#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstdlib>
#include<ctime>
#define int long long
#define reg register
#define N 50003
using namespace std;

struct query{
	int l,r,id,type;
	query(int l=0,int r=0,int id=0,int type=0):l(l),r(r),id(id),type(type){}
	//这里的l,r表示的并不是区间,只是为了方便才这么写的 
	//id表示属于哪个询问,type表示其正负 
};

int a[N],be[N],ans[N];
int cntl[N],cntr[N];
query q[N<<2];
int n,m,unit,res,qc,l,r;

inline void read(int &x);
void print(int x);
inline bool cmp(query x,query y);
inline void movel(int t);
inline void mover(int t);

signed main(){
  freopen("code.in", "r", stdin);
  freopen("AC_code.out", "w", stdout);
	int l1,r1,l2,r2,t = 0;
	read(n);
	unit = sqrt(n);
	for(reg int i=1;i<=n;++i){
		read(a[i]);
		be[i] = i/unit+1;
	}
	read(m);
	for(reg int i=1;i<=m;++i){
		read(l1),read(r1),read(l2),read(r2);
		q[++qc] = query(r1,r2,i,1); //强拆成4个询问 
		q[++qc] = query(r1,l2-1,i,-1);
		q[++qc] = query(l1-1,r2,i,-1);
		q[++qc] = query(l1-1,l2-1,i,1);
	}
	for(reg int i=1;i<=qc;++i){
		if(q[i].l<=q[i].r) continue;
		swap(q[i].l,q[i].r);
	}
  for (int i = 1; i <= qc; i++) {
    std::cout << q[i].l << ' ' << q[i].r << std::endl;
  }
	sort(q+1,q+1+qc,cmp);
	l = 0,r = 0;
	for(reg int i=1;i<=qc;++i){
		while(l<q[i].l) movel(1);
		while(l>q[i].l) movel(-1);
		while(r<q[i].r) mover(1);
		while(r>q[i].r) mover(-1);
		if(q[i].type==1) ans[q[i].id] += res;
		else ans[q[i].id] -= res;
	}
	for(reg int i=1;i<=m;++i){
		print(ans[i]);
		putchar('\n');
	}
	return 0;
}

inline void movel(int t){
	if(t==1){
		++cntl[a[l+1]];
		res += cntr[a[l+1]];  //计算移动端点对答案的贡献。这里可以自己思考一下 
		++l;
	}else{
		--cntl[a[l]];
		res -= cntr[a[l]];
		--l;	
	}
}

inline void mover(int t){
	if(t==1){
		++cntr[a[r+1]];
		res += cntl[a[r+1]];
		++r;
	}else{
		--cntr[a[r]];
		res -= cntl[a[r]];
		--r;
	}
}

inline bool cmp(query x,query y){
	if(be[x.l]==be[y.l]) return x.r < y.r;
	return x.l < y.l;
}

inline void read(int &x){
	x = 0;
	char c = getchar();
	while(c<'0'||c>'9') c = getchar();
	while(c>='0'&&c<='9'){
		x = (x<<3)+(x<<1)+(c^48);
		c = getchar();
	}
}

void print(int x){
	if(x>9) print(x/10);
	putchar(x%10+'0');
}
