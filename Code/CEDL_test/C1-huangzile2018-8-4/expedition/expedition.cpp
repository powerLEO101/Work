#include<iostream>
#include<cstdio>
#include<algorithm>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 100005
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	int a,b;
}Nodes[_];
bool operator< (const Node& a,const Node& b)
{
	return a.b<b.b;
}

int main()
{
	File(expedition);
	int n = gi;
	for(int i = 0;i<n;i++)
		Nodes[i].a = gi,Nodes[i].b = gi;
	std::sort(Nodes,Nodes+n);
	long long Ans = 0,Temp = Nodes[0].a;
	for(int i = 1;i<n;i++)
	{
		if(Nodes[i].b==Nodes[i-1].b)Temp+=Nodes[i].a;
		else Ans+=Temp*Temp,Temp = Nodes[i].a;
	}
	Ans+=Temp*Temp;
	std::cout<<Ans;
	return 0;
}
