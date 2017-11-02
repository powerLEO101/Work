#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
#define gi get_int()
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[100001];
int n,m;

int calc(int a,int b,int x){
	if(a==b)return 0;
	if(x==b)return 1;
	int Ans = INF;
	if(b>a)Ans = std::min(Ans,b-a);
	else if(a>b)Ans = std::min(Ans,m-a+b);
	if(b>a){
		if(a<x&&b>=x)Ans = std::min(Ans,b-x+1);
	}
	else{
		if(a<x)
			Ans = std::min(Ans,m-x+b+1);
		else if(x<b)
			Ans = std::min(Ans,b-x+1);
	}
	return Ans;
}
int Check(int x){
	int Ans = 0;
	for(int i = 1;i<n;i++){
		int Temp = calc(Num[i-1],Num[i],x);
		Ans+=Temp;
	}
	return Ans;
}

int main(){
	freopen("void.in","r",stdin);
	freopen("void.out","w",stdout);
	n = gi;m = gi;
	int Ans = INF;
	for(int i = 0;i<n;i++)
		Num[i] = gi;
	int Ans1;
	for(int i = 1;i<=m;i++){
		int Temp = Check(i);
		if(Ans>Temp){
			Ans = Temp;
			Ans1 = i;
		}
	}
	std::cout<<Ans;
	return 0;
}

