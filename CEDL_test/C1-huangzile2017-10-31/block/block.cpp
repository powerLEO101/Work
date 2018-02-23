#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define gi get_int()
#define INF 0x3f3f3f3f
int get_int(){
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[1001];
class Node{
public:
	int Mode,Weight,Len;
};
std::vector<Node> Nodes;
int Ans = -INF;

void Get_ans(std::vector<Node> No,int w){
	std::vector<Node> Nodes = No;
	if(Nodes.size()==0){
		Ans = std::max(Ans,w);
		return;
	}
	std::vector<Node> Temp,x,temp;
	Temp.clear();
	for(int i = 0;i<Nodes.size();i++){
		int Len = Nodes[i].Len;
		while(i+1!=Nodes.size()&&Nodes[i].Mode==Nodes[i+1].Mode){
			Len+=Nodes[i+1].Len;i++;
		}
		Temp.push_back((Node){Nodes[i].Mode,Len*Len,Len});
	}
//	for(int i = 0;i<Temp.size();i++)
//		std::cout<<Temp[i].Mode<<" "<<Temp[i].Weight<<" "<<Temp[i].Len<<std::endl;
//	std::cout<<"-------"<<std::endl;
	for(int i = 0;i<Temp.size();i++){
		x.clear();
		for(int j = 0;j<Temp.size();j++){
			if(j==i)continue;
			x.push_back(Temp[j]);
		}
//		std::cout<<"-----o-"<<Temp.size()<<std::endl;
		Get_ans(x,w+Temp[i].Weight);
	}
//	std::cout<<"$$$$$$$\n";
}

int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int T = gi;
	while(T--){
		Nodes.clear();
		int n = gi;
		for(int i = 0;i<n;i++)Num[i] = gi;
		for(int i = 0;i<n;i++){
			int j = i;
			while(Num[i]==Num[j])j++;
			Nodes.push_back((Node){Num[i],(j-i)*(j-i),(j-i)});
			i = j-1;
		}
		Ans = -INF;
		Get_ans(Nodes,0);
		std::cout<<Ans<<std::endl;
	}
	return 0;
}
