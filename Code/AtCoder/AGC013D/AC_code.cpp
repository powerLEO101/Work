#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const long long p=1000000007ll;
long long f[3001][3001];
int n,m;

long long dp(int n,int m){
	memset(f,0,sizeof(f));
	for(int i=0;i<=n;++i)f[0][i]=1ll;
	for(int i=1;i<=m;++i)for(int j=0;j<=n;++j){if(j)(f[i][j]+=f[i-1][j]+f[i-1][j-1])%=p;if(j<n)(f[i][j]+=f[i-1][j]+f[i-1][j+1])%=p;}
	long long res=0ll;for(int i=0;i<=n;++i)(res+=f[m][i])%=p;return res;
}

int main(){
	scanf("%d%d",&n,&m);
	printf("%lld %lld",dp(n,m), dp(n-1,m));
	return 0;
}
