/**************************
  * Author : Leo101
  * Problem : SP3267 DQUERY - D-query
  * Tags : 莫队
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int LIMIT = 1e6 + 10;
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

int num[LIMIT], answer[LIMIT];
int block, ans;

class data
{
public:
	int l, r, id;
} q[LIMIT];
bool operator< (const data& a, const data& b)
{
	 if (a.l / block == b.l / block) return a.r < b.r;
	 return (a.l / block) < (b.l / block);
}

int vis[LIMIT];
void del(int x)
{
	vis[x]--;
	if (vis[x] == 0) ans--;
}
void add(int x)
{
	vis[x]++;
	if (vis[x] == 1) ans++;
}

int main()
{
	_FILE(code);

	int n = gi;
	block = sqrt(n);
	for (int i = 1; i <= n; i++) num[i] = gi;
	int m = gi;
	for (int i = 0; i < m; i++) {
		q[i].l = gi, q[i].r = gi;
		q[i].id = i;
	}

	std :: sort(q, q + m);

	int l = 1, r = 0;
	for (int i = 0; i < m; i++) {
		while (l < q[i].l) del(num[l]), l++;
		while (l > q[i].l) l--, add(num[l]);
		while (r < q[i].r) r++, add(num[r]);
		while (r > q[i].r) del(num[r]), r--;
		answer[q[i].id] = ans;
	}
	
	for (int i = 0; i < m; i++) printf("%d\n", answer[i]);

	return 0;
}
