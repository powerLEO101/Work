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

int n, f[MAXN][MAXN], num[MAXN], path[MAXN][MAXN][3];

void outPath(int x, int y)
{
	if (x != 1) outPath(x - 1, path[x][y][2]);
	if (path[x][y][0] > n) std::cout << path[x][y][1] << std::endl;
	else if (path[x][y][1] > n) std::cout << path[x][y][0] << std::endl;
	else std::cout << path[x][y][0] << ' ' << path[x][y][1] << std::endl;
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	n = gi;
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
				path[i][j][0] = a;
				path[i][j][1] = b;
				path[i][j][2] = j;
			}
			if (f[i - 1][j] + std::max(num[a], num[j]) < f[i][b]) {
				f[i][b] = f[i - 1][j] + std::max(num[a], num[j]);
				path[i][b][0] = a;
				path[i][b][1] = j;
				path[i][b][2] = j;
			}
			if (f[i - 1][j] + std::max(num[b], num[j]) < f[i][a]) {
				f[i][a] = f[i - 1][j] + std::max(num[b], num[j]);
				path[i][a][0] = b;
				path[i][a][1] = j;
				path[i][a][2] = j;
			}
		}
	}
	
	std::cout << f[n / 2][n] << std::endl;
	outPath(n / 2, n);

	return 0;
}
