#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<queue>
#include<cstring>

int num[1001][1001],gox[4] = {0,0,1,-1},goy[4] = {1,-1,0,0},n,m,f[1001];
bool state[1001][1001],water[1001];

class node
{
public:
	int l,r;
}nodes[1001];
int nodes_len;

void get_ans(int now)
{
	for(int i = 0;i<1001;i++)
		for(int j = 0;j<1001;j++)
			state[i][j] = false;
	std::queue<int> x,y;
	x.push(0);
	y.push(now);
	state[0][now] = true;
	while(!x.empty())
	{
		int temp1 = x.front(),temp2 = y.front();
		x.pop();y.pop();
		for(int i = 0;i<4;i++)
		{
			int tempx = temp1+gox[i],tempy = temp2+goy[i];
			if(state[tempx][tempy]==true||tempx==-1||tempy==-1||tempx==n||tempy==m||num[tempx][tempy]>=num[temp1][temp2])
				continue;
			state[tempx][tempy] = true;
			x.push(tempx);y.push(tempy);
		}
	}
//	for(int i = 0;i<m;i++)std::cout<<state[n-1][i]<<" ";
//	std::cout<<std::endl;
	int l = -1,r = -1;
	for(int i = 0;i<m;i++)
	{
		if(state[0][i]==true&&l==-1)l = i;
		if(state[0][i]==false &&l!=-1&&r==-1)r = i-1;
		if(state[0][i]==true)water[i] = true;
	}
	if(l==-1)return ;
	if(r==-1)r = m-1;
	nodes[nodes_len++].l = l;
	nodes[nodes_len-1].r = r;
}

int main()
{
	std::cin>>n>>m;
	for(int i = 0;i<n;i++)
		for(int j = 0;j<m;j++)
			std::cin>>num[i][j];
	for(int i = 0;i<m;i++)
	{
		if(i==0&&num[0][i]<num[0][i+1])continue;
		if(i==m-1&&num[0][i]<num[0][i-1])continue;
		if(i!=0&&i!=m-1&&(num[0][i]<num[0][i-1]||num[0][i]<num[0][i+1]))
		continue;
		get_ans(i);
	}
	int sum = 0;
	for(int i = 0;i<m;i++)sum += water[i];
//	for(int i = 0;i<m;i++)std::cout<<water[i]<<" ";
//	std::cout<<std::endl;
	for(int i = 0;i<nodes_len;i++)
		std::cout<<nodes[i].l<<" "<<nodes[i].r<<std::endl;
	std::cout<<std::endl;
	if(sum<m)
	{
		std::cout<<"0"<<std::endl<<m-sum;
		return 0;
	}
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	for(int i = 0;i<nodes_len;i++)
		for(int j = nodes[i].l+1;j<=nodes[i].r+1;j++)
			f[j] = std::min(f[j],f[nodes[i].l]+1);
	std::cout<<1<<std::endl<<f[m]<<std::endl;
//	for(int i = 0;i<=m;i++)std::cout<<f[i]<<" ";
	return 0;
}
