#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const ll mod=10007;
ll a,b,k,n,m,jie[1005],ans=1;
ll js(ll a,ll b)
{
    ll r=1,base=a;
    while(b)
    {
        if(b&1)r=r*base%mod;
        base=base*base%mod;
        b>>=1;
    }
    return r;
}
int main()
{
    scanf("%lld%lld%lld%lld%lld",&a,&b,&k,&n,&m);
    a%=mod;b%=mod;
    jie[0]=1;
    for(int i=1;i<=k;i++)
    {
        jie[i]=jie[i-1]*i%mod;
    }//先打个阶乘表用来计算
    ans=ans*js(a,n)%mod;
    ans=ans*js(b,m)%mod;
    //mod不能用除法,神奇
    ans=ans*(jie[k]*js((jie[n]*jie[k-n]%mod),mod-2))%mod;
    printf("%lld\n",ans);
    return 0;
}
