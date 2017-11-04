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

int Ans = 0,Len = 0,d;
int Num[101];

void Get_ans(int Now){
	if(Now==Len){
		int a = 0,b = 0;
		for(int i = 0;i<Len;i++)a = a*10+Num[i],b = b*10+Num[Len-i-1];
//		std::cout<<a<<" "<<b<<std::endl;
		if(b-a==d)Ans++;
		return;
	}
	for(int i = 1;i<=9;i++){
		Num[Now] = i;
		Get_ans(Now+1);
	}
}

int main(){
	freopen("terr.in","r",stdin);
	freopen("terr.out","w",stdout);
	int m,len = 0;
	d = gi;m = d;
	if(d%3!=0){
		std::cout<<0;
		return 0;
	}
	while(m!=0){
		len++;
		m/=10;
	}
	for(int i = 1;i<=len;i++){
		Len = i;
		Get_ans(0);
	}
	std::cout<<Ans;
	return 0;
}

