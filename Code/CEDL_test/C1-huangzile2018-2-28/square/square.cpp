#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define gi get_int()
#define INF 0x3f3f3f3f
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Map[1001][1001];

bool Judge(int x,int y)
{
	int State = -1;
	for(int i = 1;i<=100;i++)
	{
		int ax = x+i,ay = y+i;
		int bx = x+i,by = y-i;
		int cx = x-i,cy = y+i;
		int dx = x-i,dy = y-i;
		for(int j = by;j<=ay;j++)
		{
			if(Map[ax][j]!=State&&Map[ax][j]!=0)return false;
			if(Map[cx][j]!=State&&Map[cx][j]!=0)return false;
			
		}
		for(int j = cx;j<=ax;j++)
		{
			if(Map[j][ay]!=State&&Map[j][ay]!=0)return false;
			if(Map[j][by]!=State&&Map[j][by]!=0)return false;
		}
		State = -State;
	}
	return true;
}

int main()
{
	//freopen("square.in","r",stdin);
	//freopen("square.out","w",stdout);
	int T = gi,Count = 0;
	while(T--)
	{
		for(int i = 0;i<1001;i++)
		for(int j = 0;j<1001;j++)
			Map[i][j] = 0;
		int n = gi;
		std::cout<<n<<std::endl;
		for(int i = 0;i<n;i++)
		{
			int x = gi+300,y = gi+300;
			std::cout<<x<<" "<<y<<std::endl;
			char c;
			std::cin>>c;
			Map[x][y] = c;
		}
		std::cout<<233;
		int Ansx = -INF,Ansy = -INF;
		for(int i = -100;i<=100;i++)
		for(int j = -100;j<=100;j++)
		{
			if(Map[i+300][j+300]==-1)continue;
			if(Judge(i+300,j+300)==true)
			{
				if((i*i+j*j)<(Ansx*Ansx+Ansy*Ansy))Ansx = i,Ansy = j;
				else if((i*i+j*j)==(Ansx*Ansx+Ansy*Ansy)&&i>Ansx)Ansx = i,Ansy = j;
				else if((i*i+j*j)==(Ansx*Ansx+Ansy*Ansy)&&i==Ansx&&j>Ansy)Ansx = i,Ansy = j;
			}
		}
		std::cout<<"Case #"<<++Count<<":"<<Ansx-300<<" "<<Ansy-300<<std::endl;
	}
	return 0;
}
