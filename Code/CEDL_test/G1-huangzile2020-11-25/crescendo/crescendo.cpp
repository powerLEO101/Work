#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
const int MAXN = 1001, MAXL = 1001;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

double dp[MAXN][MAXL];
int t[1000010], v[1000010];

int main()
{
	freopen("crescendo.in", "r", stdin);
	freopen("crescendo.out", "w", stdout);

	int n = gi, L = gi;
	for (int i = 0; i < n; i++)
		t[i] = gi, v[i] = gi;
	if (n <= 100) {
		for (int i = 0; i <= 100; i++)
			for (int j = 0; j <= 100; j++)
				dp[i][j] = -0x3f3f3f3f;
		dp[0][L] = t[0];
		for (int i = 1; i < n; i++)
			for (int j = 0; j <= L; j++) {
				if (j - v[i] < 0) continue;
				for (int k = 0; k <= L; k++) {
					if (k + v[i] < j) continue;
					int sur = k + v[i] - j;
					dp[i][j] = std::max(dp[i][j], ((k - sur) * dp[i - 1][k] + v[i] * t[i] * 1.0) / j);
				}
			}
		for (int i = 0; i < n; i++)
			printf("%.8f\n", dp[i][L]);
		return 0;
	}

	bool flag1 = 1, flag2 = 1;
	for (int i = 0; i < n - 1; i++) {
		if (t[i] > t[i + 1]) flag1 = 0;
		if (t[i] < t[i + 1]) flag2 = 0;
	}
	if (flag1 == 1) {
		for (int i = 0; i < n; i++)
			std::cout << "nan" << std::endl;
	} else if (flag2 == 1) {
		long double nowT = t[0];
		printf("%.8Lf\n", nowT);
		for (int i = 1; i < n; i++) {
			nowT = (nowT * (L - v[i]) + 1ll * t[i] * v[i]) / L;
			printf("%.8Lf\n", nowT);
		}
	} else {
		for (int i = 0; i < n; i++)
			std::cout << "nan" << std::endl;
	}

	return 0;
}
