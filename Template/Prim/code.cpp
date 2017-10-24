#include<cstdio>  
using namespace std;  
const int maxn=30;  
const int INF=1000000;  
int graph[maxn][maxn];  
int lowcost[maxn],closet[maxn];/*lowcost表示每个点的最小花费;closet表示最小花费对应相连的点*/  
int visited[maxn];/*visited区分两个集合*/  
int n;/*n个点*/  
  
void createGraph(){  
	memset(graph,0,sizeof(graph));  
	memset(lowcost,0,sizeof(lowcost));  
	memset(closet,0,sizeof(closet));  
	memset(visited,0,sizeof(visited));  
	int a;  
	for(int i=0;i<n;i++)  
	for(int j=0;j<n;j++){  
		scanf("%d",&a);  
		if(a==0)  
			graph[i][j]=graph[j][i]=INF;  
		else  
			graph[i][j]=graph[j][i]=a;  
	}  
}  
  
void prim(){  
	int sum=0;  
	visited[0]=1;/*选中第一个点*/  
	for(int i=0;i<n;i++){  
		lowcost[i]=graph[i][0];/*每个点与第一个点的权值*/  
		closet[i]=0;/*与i点相连的是第一个点*/  
	}  
	for(int i=1;i<n;i++){  /*剩下n-1个点*/  
		int minn=lowcost[0],k=0;  
		for(int j=0;j<n;j++){  
			if(!visited[j] && lowcost[j]<minn){  
				minn=lowcost[j];  
				k=j;  
			}  
		}  
		sum+=minn;  
		visited[k]=1;  
		for(int t=0;t<n;t++){  /*松弛操作*/  
			if(!visited[t] && lowcost[t]>graph[t][k]){  
				lowcost[t]=graph[t][k];  
				closet[t]=k;  
			}  
	   }  
	}  
	printf("%d\n",sum);  
}  
  
int main()  
{  
   // freopen("input.txt","r",stdin);  
	while(~scanf("%d",&n)){  
		if(!n) break;  
		createGraph();  
		prim();  
	}  
}  
