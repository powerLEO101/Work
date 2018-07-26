#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Pos
{
public:
	int x1,x2,y1,y2;
	bool Flag;
}pos[10001];
bool operator< (const Pos& a,const Pos& b)
{
	if(a.x1<b.x1)return true;
	if(a.x2<b.x2)return true;
	if(a.y1<b.y1)return true;
	if(a.y2<b.y2)return true;
	return false;
}
int n,Num;

bool Judge(int i,int j)
{
	if(pos[i].x2<pos[j].x2&&pos[i].x2>pos[j].x1&&pos[i].y2<pos[j].y2&&pos[i].y2>pos[j].y1)return true;
	if(pos[i].x1<pos[j].x2&&pos[i].x1>pos[j].x1&&pos[i].y2<pos[j].y2&&pos[i].y2>pos[j].y1)return true;
	if(pos[i].x1<pos[j].x2&&pos[i].x1>=pos[j].x1&&pos[i].y2<=pos[j].y2&&pos[i].y2>pos[j].y1)return true;
	if(pos[i].x2<=pos[j].x2&&pos[i].x2>pos[j].x1&&pos[i].y1<pos[j].y2&&pos[i].y1>=pos[j].y1)return true;
	return false; 
}
void Merge(int i,int j)
{
	pos[j].Flag = true;
	pos[i] = (Pos){std::min(pos[i].x1,pos[j].x1),std::max(pos[i].x2,pos[j].x2),std::min(pos[i].y1,pos[j].y1),std::max(pos[i].y2,pos[j].y2),false};
	Num--;
}
bool Get()
{
	for(int i = 0;i<n;i++)
	{
		if(pos[i].Flag==true)continue;
		for(int j = i+1;j<n;j++)
		{
			if(pos[j].Flag==true)continue;
			if(Judge(i,j)==true||Judge(j,i)==true)Merge(i,j);
		}
	}
	return true;
}

int main()
{
	File(time);
	n = gi;
	Num = n;
	for(int i = 0;i<n;i++)
	{
		int x1 = gi,x2 = gi,y1 = gi,y2 = gi;
		pos[i] = (Pos){x1,x2,y1,y2,false};
	}
	for(int i = 0;i<n;i++)
		if(Get()==false)break;
	std::sort(pos,pos+n);
	std::cout<<Num<<std::endl;
	for(int i = 0;i<n;i++)
	{
		if(pos[i].Flag==false)
			//std::cout<<i;
			std::cout<<pos[i].x1<<" "<<pos[i].x2<<" "<<pos[i].y1<<" "<<pos[i].y2<<std::endl;
	}
	return 0;
}
