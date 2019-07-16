#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 4000, INF = 0x3f3f3f3f;
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

class data
{
public:
	int a, b;
} w[MAXN];
bool operator< (const data& a, const data& b)
{ return a.a > b.a; }

int f[MAXN][MAXN];

int main()
{
	_FILE(code);

	int n = gi;
	for (int i = 1; i <= n; i++) {
		w[i].a = gi;
		w[i].b = gi;
	}

	std :: sort(w + 1, w + 1 + n);

	for (int i = 0; i <= n; i++) {
		f[0][i] = -INF;
		f[i][n + 1] = -INF;
	}
	f[0][1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= n; j++)
			f[i][j] = std :: max(f[i - 1][j], f[i - 1][std :: max(0, j - w[i].a) + 1] + w[i].b);

	int ans = -INF;
	for (int i = 0; i <= n; i++)
		ans = std :: max(ans, f[n][i]);

	printf("%d", ans);

	return 0;
}
