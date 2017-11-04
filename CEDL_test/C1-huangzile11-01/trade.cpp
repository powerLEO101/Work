#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define gi get_int()
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Dp[1001][1001];

int main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	int T = gi,Index = 1;
	while(T--){
		memset(Dp,-0x3f,sizeof(Dp));
		int n = gi;
		for(int i = 0;i<n;i++){
			int Temp = gi;
			if(i==0){
				Dp[i][0] = 0;
				Dp[i][1] = -Temp;
				continue;
			}
			Dp[i][0] = std::max(Dp[i-1][0],Dp[i-1][1]+Temp);
			for(int j = 1;j<=i+1;j++){
				Dp[i][j] = std::max(std::max(Dp[i-1][j]\
						,Dp[i-1][j+1]+Temp)\
						,Dp[i-1][j-1]-Temp);
			}
		}
		int Ans = -0x3f3f3f3f;
		for(int j = 0;j<n;j++){
			Ans = std::max(Dp[n-1][j],Ans);
		}
		//for(int i = 0;i<n;i++){
		//	for(int j = 0;j<=i+1;j++)
		//		std::cout<<Dp[i][j]<<" ";
		//	std::cout<<std::endl;
		//}
		std::cout<<"Case #"<<Index++<<": "<<Ans<<std::endl;
	}
	return 0;
}
