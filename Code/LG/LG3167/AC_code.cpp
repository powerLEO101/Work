#include <iostream>
#include <cstdio>
#include <cstring>

typedef unsigned long long ULL;

const int MAXN = 100005;
const ULL BASE = 998244353; 

int n, m, t, tot;
int dp[12][MAXN + 2], pos[12];
char a[MAXN + 2], b[MAXN + 2];
ULL pw[MAXN + 2], hasha[MAXN + 2], hashb[MAXN + 2];

inline ULL getHash(int id, int l, int r) {
	int t = 0;
	if(id == 1) t = hasha[r] - hasha[l - 1] * pw[r - l + 1];
	else t = hashb[r] - hashb[l - 1] * pw[r - l + 1];
	return t;
}

int main() {
	scanf("%s", a + 1);
	scanf("%d", &t);
	n = strlen(a + 1) + 1;
	a[n] = '?';
	pw[0] = 1;
	for(int i = 1; i <= MAXN + 1; ++i) pw[i] = pw[i - 1] * BASE;
	for(int i = 1; i <= n; ++i) {
		hasha[i] = hasha[i - 1] * BASE + a[i];
		if(a[i] == '?' || a[i] == '*') pos[++tot] = i; 
	}
	while(t--) {
		memset(dp, 0, sizeof(dp));
		scanf("%s", b + 1);
		m = strlen(b + 1) + 1;
		b[m] = '$';
		dp[0][0] = 1;
		for(int i = 1; i <= m; ++i) hashb[i] = hashb[i - 1] * BASE + b[i];
		for(int i = 0; i <= tot; ++i) {
			if(a[pos[i]] == '*') for(int j = 1; j <= m; ++j) dp[i][j] |= dp[i][j - 1];
			for(int j = 0; j <= m; ++j) {
				if(dp[i][j] == 0) continue;
				int len = pos[i + 1] - pos[i] - 1;
				if(getHash(1, pos[i] + 1, pos[i + 1] - 1) == getHash(2, j + 1, j + len)) {
					if(a[pos[i + 1]] == '*') dp[i + 1][j + len] = 1;
					else dp[i + 1][j + len + 1] = 1;
				}
			}
		}
		puts(dp[tot][m] == 1 ? "YES" : "NO");
	}
	return 0;
}
