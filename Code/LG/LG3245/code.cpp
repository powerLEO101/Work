/**************************
  * Author : Leo101
  * Problem : LG3245 [HNOI2016]大数
  * Tags : 莫队
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long 
const int LIMIT = 500000;
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

int num[LIMIT], answer[LIMIT], sum[LIMIT], s[LIMIT], count[10];
int ans, block;

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

void add(int x)
{ 
	ans -= count[sum[x]] * (count[sum[x]] - 1) / 2;
	count[sum[x]]++;
	ans += count[sum[x]] * (count[sum[x]] - 1) / 2;

}
void del(int x)
{ 
	ans -= count[sum[x]] * (count[sum[x]] - 1) / 2;
	count[sum[x]]--;
	ans += count[sum[x]] * (count[sum[x]] - 1) / 2;
}

signed main()
{
	_FILE(code);

	int p = gi;
	std :: string str;
	std :: cin >> str;
	int n = str.size();
	block = sqrt(n);
	for (int i = 0; i < n; i++) 
		num[i] = str[i] - '0';
	sum[n - 1] = num[n - 1] % p;
	for (int i = n - 2, c = 10; i >= 0; i--, c = (c * 10) % p)
		sum[i] = (sum[i + 1] + num[i] * c) % p,
		s[i + 1] = sum[i];
	std :: sort(s + 1, s + n + 2);
	int t = std :: unique(s + 1, s + n + 2) - s - 1;
	for (int i = 1; i <= n + 1; i++)
		sum[i - 1] = std :: lower_bound(s + 1, s + t + 1, sum[i - 1]) - s;
	for (int i = n; i >= 0; i--)
		sum[i + 1] = sum[i];

	printf("%d\n", t);
	for (int i = 1; i <= n + 1; i++)
		printf("%d ", sum[i]);
	printf("\n");

	int m = gi;
	for (int i = 0; i < m; i++) {
		q[i].l = gi;
		q[i].r = gi + 1;
		q[i].id = i;
	}
	std :: sort(q, q + m);

	int l = 1, r = 0;
	for (int i = 0; i < m; i++) {
		while (l < q[i].l) del(l++);
		while (l > q[i].l) add(--l);
		while (r < q[i].r) add(++r);
		while (r > q[i].r) del(r--);
		answer[q[i].id] = ans;
		printf("%d %d\n", q[i].l, q[i].r);
		printf("%d\n", ans);
	}

	/*
	for (int i = 0; i < m; i++)
		printf("%lld\n", answer[i]);
		*/

	return 0;
}
