#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MOD 924844033
#define gi get_int()
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

long long Ans = 0;
int n,m;
bool state[1001];
int ss[1001];

int ABS(int n){return n<0?-n:n;}
void Get_ans(int Now){
	if(Now==n){
		Ans = (Ans+1)%MOD;
//		for(int i = 0;i<n;i++)std::cout<<ss[i]<<" ";
//		std::cout<<std::endl;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(state[i]==true||ABS(Now+1-i)==m)continue;
		state[i] = true;
		ss[Now] = i;
		Get_ans(Now+1);
		state[i] = false;
	}
}

int main(){
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	n = gi,m = gi;
	Get_ans(0);
	std::cout<<Ans;
	return 0;
}
