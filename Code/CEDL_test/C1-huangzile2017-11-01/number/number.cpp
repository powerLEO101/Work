#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define MOD 1000000007
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int n,m,k;
long long Ans;
int Num[1001][1001];

void Get_ans(int Now,int S){
	if(Now==m){
		Ans = (Ans+S)%MOD;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(Num[Now][i]==1)continue;
		Get_ans(Now+1,S*i);
	}
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n = gi,m = gi,k = gi;
	for(int i = 0;i<k;i++){
		int x = gi,y = gi;
		Num[x-1][y] = 1;
	}
	Get_ans(0,1);
	std::cout<<Ans;
	return 0;
}

