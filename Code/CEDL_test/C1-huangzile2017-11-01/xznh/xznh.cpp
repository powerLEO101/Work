#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define gi get_int()
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int x[1001],y[1001];

int main(){
//	freopen("xznh.in","r",stdin);
//	freopen("xznh.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++){
		x[i] = gi;
		y[i] = gi;
	}
	int sum = 0,s = 0;
	for(int i = 0;i<n;i++)
	for(int j = 0;j<n;j++)
	for(int k = 0;k<n;k++){
		if(i==j||j==k||k==i)continue;
		sum++;
		int a = sqrt(pow(x[i]-x[j],2)-pow(y[i]-y[j],2));
		int b = sqrt(pow(x[i]-x[k],2)-pow(y[i]-y[k],2));
		int c = sqrt(pow(x[j]-x[k],2)-pow(y[j]+y[k],2));
		int p = (a+b+c)/2;
		s += sqrt(p*(p-a)*(p-b)*(p-c));
	}
	std::cout<<s/sum;
	return 0;
}

