/**************************
 * Author : Leo101
 * Problem :
 * Tags :
 **************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
int get_int()
{
	int x;
	std::cin >> x;
	return x;
}
const int MAXN = 10000+10;
const int MAXM = 2000+10;
int x[MAXN], y[MAXN];
int low[MAXN], high[MAXN];
int f[MAXN][MAXM];
bool e[MAXN];
int main() {
	int n = gi, m = gi, p = gi;
	for (int i = 1; i <= n; i++)
		x[i] = gi, y[i] = gi;
	for (int i = 1; i <= n; i++) {
		low[i] = 1;
		high[i] = m;
	}
	for (int i = 1; i <= p; i++) {
		int pos = gi, lowPos = gi, highPos = gi;
		e[pos] = 1;
		low[pos] = lowPos + 1;
		high[pos] = highPos - 1;
	}
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= m; i++) 
		f[0][i] = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = x[i] + 1; j <= m + x[i]; j++)
			f[i][j] = std::min(f[i - 1][j - x[i]] + 1,f[i][j - x[i]] + 1);
		for(int j = m + 1; j <= m + x[i]; j++)
			f[i][m] = std::min(f[i][m], f[i][j]);
		for(int j = 1; j <= m - y[i]; j++)
			f[i][j] = std::min(f[i][j], f[i - 1][j + y[i]]);
		for(int j = 1; j < low[i]; j++)
			f[i][j] = 0x3f3f3f3f;
		for(int j = high[i] + 1; j <= m; j++)
			f[i][j] = 0x3f3f3f3f;
	}
	int ans = 0x3f3f3f3f;
	for(int j = 1; j <= m; j++)
		ans = std::min(ans, f[n][j]);
	if (ans < f[0][0])
		std::cout << 1 << std::endl << ans;
	else {
		int cnt;
		for(int i = n; i >= 1; i--) {
			for(int j = 1; j <= m; j++) {
				if (f[i][j] < 0x3f3f3f3f) {
					cnt = i;
					break;
				}
			}
			if(cnt == i) break;
		}
		ans = 0;
		for(int i = 1; i <= cnt; i++) {
			if (e[i]) ans++;
		}
		std::cout << 0 << std::endl << ans;
	}
	return 0;
}
