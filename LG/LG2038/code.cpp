#include<cstdio>
using namespace std;
const int maxn = 303;
int d,n,G[maxn][maxn],cnt,maxm=-1;
int main(){
	freopen("wireless.in","r",stdin);
	freopen("wireless.out","w",stdout);
    scanf("%d%d",&d,&n);
    for(int i=1,x,y;i<=n;i++){
        scanf("%d %d",&x,&y);
        scanf("%d",&G[x+20][y+20]);
    }
    for(int i=0+20;i<=128+20;i++)
        for(int j=0+20;j<=128+20;j++){
            int sum=0;
            for(int u=i-d;u<=i+d;u++)
                for(int v=j-d;v<=j+d;v++) 
                    sum+=G[u][v];
            if(sum==maxm)cnt++;
            if(sum>maxm){maxm=sum; cnt=1;}
        }
    printf("%d %d",cnt,maxm);
    return 0;
}
