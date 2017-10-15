#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

const int maxn = 100010;
const int maxm = 99999997;
struct node
{
	int data;
	int loc;
}a[maxn],b[maxn];
int cmp(const node& a,const node& b)
{
	return a.data<b.data;
}

int e[maxn], n, c[maxn];

int inline readint()
{
	int x = 0;
	char c = getchar();
	while (c<'0' || c>'9') c = getchar();
	while (c >= '0'&&c <= '9')
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

int lowbit(int x)
{
	return x&-x; 
}

void add(int x,int t)
{
	while (x <= n)
	{
		e[x] += t;
		e[x] %= maxm;
		x += lowbit(x); 
	}
}

int sum(int x)
{
	int s = 0;
	while(x)
	{
		s += e[x];
		s %= maxm;
		x -= lowbit(x); 
	}
	return s;
}

int main()
{
	n = readint();
	for (int i = 1; i <= n; i++)
	{
		std::cin>>a[i].data;
		a[i].loc = i;
	}
	for (int i = 1; i <= n; i++)
	{
		std::cin>>b[i].data;
		b[i].loc = i;
	}
	std::sort(a + 1, a + n + 1, cmp);
	std::sort(b + 1, b + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		c[a[i].loc] = b[i].loc; 
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		add(c[i], 1); 
		ans += i - sum(c[i]);  
		ans %= maxm;
	}
	std::cout<<ans;
	return 0;
}
