#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

long long a[MAXN], b[MAXN], num[MAXN];

int main()
{
	int T = gi;
	std :: string s;
	while (T--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		std :: map<long long, int> bb;
		int n = gi;
		for (int i = 1; i <= n; i++) {
			char ch;
			std :: cin >> ch;
			if (ch == 'L') num[i] = 1;
			if (ch == 'R') num[i] = -1;
			if (ch == 'U') num[i] = 1000000000;
			if (ch == 'D') num[i] = -1000000000;
		}
		for (int i = 1; i <= n; i++) std :: cout << "!!!!" << num[i] << ' ';
		std :: cout << std :: endl;
		for (int i = 1; i <= n; i++) {
			a[i] = a[i - 1] + num[i];
			//std :: cout << a[i] << ' ';
		}
		for (int i = n; i >= 1; i--) {
			b[i] = num[i];
			std :: cout << b[i] << ' ';
		}
		std :: cout << std :: endl;
		for (int i = n; i >= 1; i--) {
			bb[b[i]] = i;
		}
		int ansL = -1, ansR = -1;
		for (int i = 1; i <= n; i++) {
			if (bb[b[i]] == i) 
				bb[b[i]] = 1000000000;
			if (bb.count(a[i]) == 0) continue;
			int r = bb[a[i]];
			if (ansL == -1) {
				ansL = i;
				ansR = r;
			} else {
				if (ansR - ansL > r - i) {
					ansL = i;
					ansR = r;
				}
			}
		}
		printf("%d %d\n", std :: min(ansL, ansR), std :: max(ansL, ansR));
	}

	return 0;
}
