#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
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

signed main()
{
	_FILE(game);

	int T = gi;
	while (T--) {
		int num;
		std :: cin >> num;
		int count = 0;
		for (int i = 2; i * i <= num; i++) {
			while ((num % i) == 0) {
				num /= i;
				count++;
			}
			if (count >= 3) break;
		}
		if (num != 1) count++;
		if (count >= 3 || count == 0) printf("Alice\n");
		else printf("Bob\n");
	}

	return 0;
}
