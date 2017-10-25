#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,a[N],xr,last[31];
int main() {
	freopen("chorus.in","r",stdin);
	freopen("chorus.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i+=1) cin>>a[i], xr|=a[i];
	int ans = 998244353;
	memset(last,-127/3,sizeof(last));
	for(int i=1;i<=n;i+=1) {
		int cmin = i;
		for(int j=0;j<=30;j+=1) {
			if(!((xr>>j)&1)) continue;
			if((a[i]>>j)&1) {
				last[j] = i;
			}
			cmin = min(cmin,last[j]);
		}
		cout << "i = " << i << " , min = " << cmin << endl;
		ans = min(ans,i-cmin+1);
	}
	cout << ans;
	return 0;
}

