#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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
} num[1000000];
bool operator< (const data& a, const data& b)
{ return a.b > b.b; }

int sum[1000000], dp[300][120000];

int main()
{
	_FILE(code);

	int n = gi;
	for (int i = 1; i <= n; i++) {
		num[i].a = gi;
		num[i].b = gi;
	}
	std :: sort(num + 1, num + n + 1);

	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + num[i].a;
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= sum[i]; j++) {
			if (j >= num[i].a)
				dp[i][j] = std :: min(dp[i][j], std :: max(dp[i - 1][j - num[i].a], j + num[i].b));
			dp[i][j] = std :: min(dp[i][j], std :: max(dp[i - 1][j], sum[i] - j + num[i].b));
		}
	}

	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= sum[n]; i++) {
		ans = std :: min(ans, dp[n][i]);
	}

	std :: cout << ans;

	return 0;
}
