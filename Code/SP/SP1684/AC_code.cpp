#include<cstdio>
#include<cmath>
#include<iostream>

#define N 100001
#define K 17
#define Log2(n) (int)(log((double)(n))/log(2.0))

using namespace std;

int n,q,a[N],dp[N],p[N][K];

void RMQ()//RMQ模板
{
	for(int i=1;i<=n;i++)p[i][0]=dp[i];//RMQ初始化
	for(int j=1;j<=Log2(n+1);j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			p[i][j]=max(p[i][j-1],p[i+(1<<(j-1))][j-1]);//RMQ合并
		}
	}
}

int ask(int l,int r)//询问
{
	if(l>r)return 0;
	int k=Log2(r-l+1);
	return max(p[l][k],p[r-(1<<k)+1][k]);
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("AC_code.out", "w", stdout);
	while(~scanf("%d%d",&n,&q)&&n)
	{
		dp[1]=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i>1) dp[i]=(a[i]==a[i-1]?dp[i-1]+1:1);//如果这个数和上一个数一样，那么dp[i]=dp[i-1]+1，否则为1
		}
		RMQ();
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int now=l;
			while(now<=r&&a[now]==a[now-1])now++;//这里有一个小细节，就是我们先求出以l开头的最长符合题意的序列
			printf("%d\n",max(now-l,ask(now,r)));
		}
	}
}
