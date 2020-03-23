#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define int long long
int vis[1000100],a[1000100],b[1000100],p1[1000100],p2[1000100];
signed main(){
	int n,m,i,j,k=0,l1,l2,r1,r2;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n;i++)scanf("%lld",&b[i]),b[i]+=b[i-1];
	if(a[n]>b[n]){
		k=1;
		for(i=1;i<=n;i++)swap(a[i],b[i]);
	}
	int L=0;
	for(i=0;i<=n;i++){
		while(L<n&&b[L+1]<=a[i])L++;
		int sum=a[i]-b[L];
		if(vis[sum]){
			l1=p1[sum]+1,l2=p2[sum]+1;
			r1=i,r2=L;
			break;
		}else {
			vis[sum]=1;
			p1[sum]=i,p2[sum]=L;
		}
	}
	if(k)swap(l1,l2),swap(r1,r2);
	printf("%lld\n",r1-l1+1);
	for(i=l1;i<=r1;i++)printf("%lld ",i);
	puts("");
	printf("%lld\n",r2-l2+1);
	for(i=l2;i<=r2;i++)printf("%lld ",i);
	return 0;
}
