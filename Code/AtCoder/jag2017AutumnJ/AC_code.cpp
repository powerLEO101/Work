#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
typedef long long ll;
const int N=200010;
ll s[N];
priority_queue <ll,vector<ll>,greater<ll> > P,Q;
inline int gi() {
	int x=0,o=1;
	char ch=getchar();
	while(ch!='-'&&(ch<'0'||ch>'9')) ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*o;
}
int main() {
	freopen("code.in", "r", stdin);
	freopen("AC_code.out", "w", stdout);
	int n;
	ll ans=0;
	cin>>n;   
	for(int i=2;i<=n;i++) s[i]=s[i-1]+gi();
	for(int i=1;i<=n;i++) {
		int c=gi();
		ll k;
		for(int j=0;j<2;j++) {
			if(Q.size()&&(k=Q.top()+s[i]+c)<0) {
				Q.pop(),ans+=k;
				Q.push(-s[i]-c),P.push(-k-s[i]+c);
			}
			else P.push(-s[i]+c);
		}
		ans+=(k=s[i]+P.top());
		P.pop(),Q.push(-k-s[i]);
	}
	cout<<ans<<endl;
	return 0;
}
