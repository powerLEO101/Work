#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

class node
{
public:
	int a,b,x,y;
}nodes[10001];

int main()
{
	int n,x,y,ans = -1;
	std::cin>>n;
	for(int i = 0;i<n;i++)
		std::cin>>nodes[i].a>>nodes[i].b>>nodes[i].x>>nodes[i].y;
	std::cin>>x>>y;
	for(int i = 0;i<n;i++)
	{
		int tempx = nodes[i].a+nodes[i].x;
		int tempy = nodes[i].b+nodes[i].y;
		if(x<=tempx&&x>=nodes[i].a&&y<=tempy&&y>=nodes[i].b)
			ans = i+1;
	}
	std::cout<<ans;
	return 0;
}
