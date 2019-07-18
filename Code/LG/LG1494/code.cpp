/**************************
  * Author : Leo101
  * Problem : LG1494 [国家集训队]小Z的袜子
  * Tags : 莫队
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int LIMIT = 1e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-')
		y = -1, ch = getchar(); 
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int num[LIMIT], answer[LIMIT], count[LIMIT], lL[LIMIT], rR[LIMIT];
int block, ans;

class data
{
public:
	int l, r, id;
	int belong() const
	{ return l / block; }
} q[LIMIT];
bool operator< (const data& a, const data& b)
{
	if (a.belong() == b.belong()) return a.r < b.r;
	return a.belong() < b.belong();
}

void del(int x)
{
	count[num[x]]--;
	ans -= count[num[x]];
}
void add(int x)
{
	ans += count[num[x]];
	count[num[x]]++;
}

int gcd(int a, long long b)
{ return b ? gcd(b, a % b) : a; }
void putAns(int a, int b)
{ 
	if (b * (b - 1) == 0) {
		printf("0/1\n");
		return ;
	}
	int c = gcd(a, 1ll * b * (b - 1) / 2);
	printf("%d/%lld\n", a / c, 1ll * (b * (b - 1)) / 2 / c); 
}

signed main()
{
	_FILE(code);

	int n = gi, m = gi;
	block = sqrt(n);
	for (int i = 0; i < n; i++) num[i] = gi;
	for (int i = 0; i < m; i++) {
		q[i].l = gi - 1, q[i].r = gi;
		lL[i] = q[i].l; rR[i] = q[i].r;
		q[i].id = i;
	}

	std :: sort(q, q + m);

	int l = 0, r = 0;
	for (int i = 0; i < m; i++) {
		while (l < q[i].l) del(l), l++;
		while (l > q[i].l) l--, add(l);
		while (r < q[i].r) add(r), r++;
		while (r > q[i].r) r--, del(r);
		answer[q[i].id] = ans;
	}

	for (int i = 0; i < m; i++) putAns(answer[i], rR[i] - lL[i]);

	return 0;
}
