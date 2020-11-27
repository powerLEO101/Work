#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define int long long
const int MAXN = 2e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, sum;

int gen(int now, int round)
{
	int ret = 1 + n - now;
	(ret += round * 2) %= n;
	if (ret == 0) return n;
	return ret;
}

int remain[2][MAXN], len[2], num[MAXN];

signed main()
{
	freopen("what.in", "r", stdin);
	freopen("what.out", "w", stdout);

	n = gi, sum = 0;
	for (int i = 1; i <= n; i++) {
		num[i] = gi;
		sum += num[i]; 
	}
	sum /= n / 2;
	for (int i = 1; i <= n; i++) {
		if (sum - num[i] < 0) {
			std::cout << "IMPOSSIBLE";
			return 0;
		}
	}
	int pos = 1;
	for (int i = 0; i < n / 2; i++)
		remain[pos][len[pos]++] = i;
	for (int i = 1; i <= n; i++) {
		pos ^= 1;
		len[pos] = 0;
		for (int j = 0; j < len[pos ^ 1]; j++) {
			if (num[i] + num[gen(i, remain[pos ^ 1][j])] == sum) {
				remain[pos][len[pos]++] = remain[pos ^ 1][j];
			}
		}
	}
	if (len[pos] == 0) {
		std::cout << "IMPOSSIBLE";
		return 0;
	}
	int ans = remain[pos][0];
	for (int i = 1; i < len[pos]; i++)
		ans = std::min(ans, remain[pos][i]);
	std::cout << ans;


	return 0;
}
