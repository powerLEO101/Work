#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
const int MAXN = 2000;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int f[MAXN][MAXN], num[MAXN], path[MAXN][MAXN][3];

void outPath(int x, int y)
{
	
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	int n = gi;
	for (int i = 1; i <= n; i++)
		num[i] = gi;
	n++;
	memset(f, 0x3f, sizeof(f));
	f[0][1] = 0;
	for (int i = 1; i <= n / 2; i++) {
		int a = i * 2, b = i * 2 + 1;
		for (int j = 1; j < a; j++) {
			if (f[i - 1][j] + std::max(num[a], num[b]) < f[i][j]) {
				f[i][j] = f[i - 1][j] + std::max(num[a], num[b]);
				path[i][j] = {a, b, j};
			}
			if (f[i - 1][j] + std::max(num[a], num[j]) < f[i][b]) {
				f[i][b] = f[i - 1][j] + std::max(num[a], num[j]);
				path[i][b] = {a, j, j};
			}
			if (f[i - 1][j] + std::max(num[b], num[j]) < f[i][a]) {
				f[i][a] = f[i - 1][j] + std::max(num[b], num[j]);
				path[i][a] = {b, j, j};
			}
		}
	}
	
	std::cout << f[n / 2][n];
	outPath(n / 2, n);

	return 0;
}
