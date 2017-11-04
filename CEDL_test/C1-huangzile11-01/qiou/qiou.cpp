#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node{
public:
	int m,s;
}Nodes[1000001];
int Num[1000001];
long long Sum[1000001];
bool operator<(const Node& a,const Node& b){
	return a.m<b.m;
}

int main(){
	freopen("qiou.in","r",stdin);
	freopen("qiou.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++){
		Nodes[i].m = gi;
		Nodes[i].s = gi;
	}
	std::sort(Nodes,Nodes+n);
	for(int i = 0;i<n;i++)Num[i] = Nodes[i].m;
	Sum[0] = Nodes[0].s;
	for(int i = 1;i<n;i++)Sum[i] = Sum[i-1]+Nodes[i].s;
	long long Ans = -1;
	for(int i = 0;i<n;i++)
	{
		int len = (std::lower_bound(Num,Num+n,Num[i]+m)-Num);
		if(i==0)Ans = std::max(Ans,Sum[len-1]);
		else Ans = std::max(Ans,Sum[len-1]-Sum[i-1]);
	}
	std::cout<<Ans;
	return 0;
}
