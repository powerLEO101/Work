#include<iostream>
#include<cstdio>
using namespace std;
int n,m,k,d[1002],tim[10002],st[10003],ed[10003],car[1002],g[1002],t[1002],sum[1002];
int ans,fast,maxnn;
int main(){
	scanf("%d%d%d",&n,&m,&k);//jingdian 乘客 氮气
	for(int i=1;i<n;i++)scanf("%d",&d[i]);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&tim[i],&st[i],&ed[i]);
		t[st[i]]=max(t[st[i]],tim[i]);
		sum[ed[i]]++;
	} 
	for(int i=2;i<=n;i++)sum[i]+=sum[i-1];
	car[1]=t[1];
	for(int i=2;i<=n;i++){car[i]=max(car[i-1],t[i-1])+d[i-1];}
	for(int i=1;i<=m;i++)ans+=(car[ed[i]]-tim[i]);
	std::cout<<ans;
	while(k--){
		g[n]=g[n-1]=n;maxnn=0;
		for(int i=n-2;i>=1;i--)
			g[i]=car[i+1]<=t[i+1]?i+1:g[i+1];
		for(int i=1;i<n;i++)
			if(sum[g[i]]-sum[i]>maxnn&&d[i]){
				maxnn=sum[g[i]]-sum[i];fast=i;
			}
		ans-=maxnn;d[fast]--;
		for(int i=2;i<=n;i++)car[i]=max(car[i-1],t[i-1])+d[i-1];
	}
	printf("%d\n",ans);
	return 0;
}
