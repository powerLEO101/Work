#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int N = 2000005;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

struct node{int a,b,c;} s[N]={0};
LL seed;
LL n;
LL Rand() {
	return seed=((seed*19260817)^233333)&((1<<24)-1);
}
IL void build()
{
	for(RG int i=1;i<=n;++i) s[i].a=s[i].b=s[i].c=i;
	seed=gi(); for(RG int i=1;i<=n;++i) swap(s[i].a,s[Rand()%i+1].a);
	seed=gi(); for(RG int i=1;i<=n;++i) swap(s[i].b,s[Rand()%i+1].b);
	seed=gi(); for(RG int i=1;i<=n;++i) swap(s[i].c,s[Rand()%i+1].c);
}


int tree[N];

int main()
{
	_FILE(code);

	int n = gi;
	build();

	return 0;
}
