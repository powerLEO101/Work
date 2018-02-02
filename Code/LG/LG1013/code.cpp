#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
	int n,num[10],b,tmp;	char c,wd[10];	string sum[10][10];
int jc(int bit,int a){
	int x=1;
	while(a>0){
		a--; x*=bit;
	}
	return x;
}

int main(){
	memset(num,0,sizeof(num));
	scanf("%d\n",&n);
	scanf("%c",&c);	

	for(int i=1;i<n;i++){
		scanf("%c",&c);
		scanf("%c",&c);
		wd[i]=c;	
	}
	for(int i=1;i<n;i++){
		scanf("%c",&c);
		scanf("%c",&c);

		for(int j=1;j<n;j++){
			scanf("%c",&c);
			cin>>sum[i][j];
			if(sum[i][j].size()==1){	
				for(int k=1;k<n;k++){
					if(wd[k] == sum[i][j][0]){
						num[k]++;
						break;
					}
				}
			}	
		}
	}

	for(int i=1;i<n;i++){			
		if(num[i]==0){	
			printf("ERROR!");
			std::cout<<"ERROR!";
			return 0;
		}
	}

	b=n-1;			
	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){			

			tmp=0;
			for(int k=0;k<sum[i][j].size();k++){
				for(int p=1;p<n;p++){
					if(sum[i][j][k]==wd[p]){
						tmp+=(num[p]-1)*jc(b,sum[i][j].size()-k-1);
						break;
					}
				}	
			}
			if(tmp!=(num[i]+num[j]-2)){
				printf("ERROR!");
				return 0;
			}
		}		
	}

	for(int i=1;i<n;i++){
		printf("%c=%d ",wd[i],num[i]-1);
	}
	printf("\n%d",b);		

	return 0;
}
