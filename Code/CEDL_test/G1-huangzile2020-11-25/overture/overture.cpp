#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int isDead[1001][1001], isWin[1001][1001];

int dfs(int n, int m)
{
	if (n > m) std::swap(n, m);
	if (isDead[n][m] == 1) return 0;
	if (isWin[n][m] == 1) return 1;
	if (n == 0 && m == 1) return 0;
	if (n == 0 && m == 0) return 0;
	if (n == 1 && m == 1) return 0;
	int toWin = 0;
	if (n != 0) {
		for (int i = 1; i <= n / 2; i++) {
			toWin |= 1 ^ dfs(n - 2 * i, m + i);
		}
	}
	if (m != 0) {
		for (int i = 1; i <= m / 2; i++) {
			toWin |= 1 ^ dfs(n + i, m - 2 * i);
		}
	}
	if (toWin == 1) {
		isWin[n][m] = 1;
		return 1;
	} else {
		isDead[n][m] = 1;
		return 0;
	}
}

int main()
{
	freopen("overture.in", "r", stdin);
	freopen("overture.out", "w", stdout);

	long long n, m;
	std::cin >> n >> m;
	if (n > m) std::swap(n, m);
	if (m - n <= 1) std::cout << "Tony";
	else std::cout << "Karry";

	/*
	for (int i = 0; i <= 21; i++) {
		for (int j = 0; j <= 21; j++)
			std::cout << dfs(i, j) << ' ';
		std::cout << std::endl;
	}
	*/

	return 0;
}
