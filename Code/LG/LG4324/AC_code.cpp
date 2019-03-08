#include <iostream>
#include <cstdio>
#include <cstring>

typedef unsigned long long ULL;

const int MAXN = 1e6;
const ULL BASE = 1e9 + 7;

int n, ans;
int p[2][MAXN | 1];
char a[MAXN + 2], b[MAXN + 2];
ULL hasha[MAXN * 2 + 10], hashb[MAXN * 2 + 10], pw[MAXN * 2 + 10];

void manacher(char *str, int *p) {
	char s[MAXN * 2 + 5];
	int len = 0, pos = 0, maxp = 0;
	s[0] = '$';
	s[++len] = '#';
	for(int i = 1; i <= n; ++i) {
		s[++len] = str[i];
		s[++len] = '#';
	}
	for(int i = 1; i <= len; ++i) {
		if(i <= maxp) p[i] = std::min(p[pos * 2 - i], maxp - i + 1);
		else p[i] = 1;
		while(s[i - p[i]] == s[i + p[i]]) ++p[i];
		if(i + p[i] - 1 > maxp) {
			maxp = i + p[i] - 1;
			pos = i;
		}
		ans = std::max(ans, p[i] - 1);
	}
	for(int i = 1; i <= len; ++i) --p[i];
}

int getHash(int id, int l, int r) {
	return id == 1 ? hasha[r] - hasha[l - 1] * pw[r - l + 1] : hashb[l] - hashb[r + 1] * pw[r - l + 1];
}

bool check(int len, int l, int r) {
	return l - len + 1 >= 1 && r + len - 1 <= n && getHash(1, l - len + 1, l) == getHash(2, r, r + len - 1); 
}

void solve1() {
	for(int i = 2; i <= 2 * n; ++i) {
		int ll, rr;
		if(i % 2 == 0) {
			ll = (i / 2) - p[0][i] / 2 - 1;
			rr = (i / 2) + p[0][i] / 2;
		} else {
			ll = (i + 1) / 2 - p[0][i] / 2 - 1;
			rr = i / 2 + p[0][i] / 2;
		}
		int l = 0, r = n, mid, res = 0;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(check(mid, ll, rr)) {
				l = mid + 1;
				res = mid;
			} else r = mid - 1;
		}
		ans = std::max(ans, p[0][i] + 2 * res);
	}
}

void solve2() {
	for(int i = 2; i <= 2 * n; ++i) {
		int ll, rr;
		if(i % 2 == 0) {
			ll = (i / 2) - p[1][i] / 2;
			rr = (i / 2) + p[1][i] / 2 + 1;
		} else {
			ll = (i + 1) / 2 - p[1][i] / 2;
			rr = i / 2 + p[1][i] / 2 + 1;
		}
		int l = 0, r = n, mid, res = 0;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(check(mid, ll, rr)) {
				l = mid + 1;
				res = mid;
			} else r = mid - 1;
		}
		ans = std::max(ans, p[1][i] + 2 * res);
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s %s", a + 1, b + 1);
	manacher(a, p[0]);
	manacher(b, p[1]);
	for (int i = 1; i <= 2 * n; i++) printf("%d ", p[0][i]);
	printf("\n");
	for (int i = 1; i <= 2 * n; i++) printf("%d ", p[1][i]);
	printf("\n");
	for(int i = 1; i <= n; ++i) hasha[i] = hasha[i - 1] * BASE + a[i];
	for(int i = n; i >= 1; --i) hashb[i] = hashb[i + 1] * BASE + b[i];
	pw[0] = 1;
	for(int i = 1; i <= n * 2 + 1; ++i) pw[i] = pw[i - 1] * BASE;
	solve1();
	solve2();
	printf("%d\n", ans);
	return 0;
}
