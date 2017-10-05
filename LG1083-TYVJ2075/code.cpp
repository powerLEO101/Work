#include<iostream>
#include<cstring>
#include<cstdio>

long long n,m,room[1000001],f[1000001],r[1000001];
struct node
{
	int num,s,e;
}a[1000001]; 
bool judge(int mid) 
{
	memset(f,0,sizeof(f));
	memset(r,0,sizeof(r));
	for (int i=1;i<=mid;++i)
	{
		f[a[i].s]-=a[i].num;
		f[a[i].e+1]+=a[i].num;
	}
	for(int i=1;i<=n;++i)
	{
		f[i]+=f[i-1];
		if (room[i]+f[i]<0) 
			return true;
	}
	return false;
} 
int main()
{
	int i,j;
	std::cin>>n>>m;
	for (i=1;i<=n;++i)
		std::cin>>room[i];
	for (i=1;i<=m;++i)
		std::cin>>a[i].num>>a[i].s>>a[i].e;
	int l=1,r=m,mid;
	while (l<r)
	{
		mid = (l+r)/2;
		if (judge(mid)==true)//如果mid不满足
			r=mid;
		else
			l = mid+1; 
	}
	if(r==m)std::cout<<0;
	else std::cout<<-1<<std::endl<<r;
	return 0;
}
