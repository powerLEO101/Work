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
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int main()
{
	int T = gi;
	while (T--) {
		int n = gi;
		int count = 0;
		for (int i = 0; i < n; i++) {
			int num = gi;
			if ((num % 2) == 1) count++;
		}
		if (n == 1) {
			if (count == 1) printf("YES");
			else printf("NO");
		} else if (count == n && ((n % 2) == 0) ) printf("NO");
		else if (count == 0) printf("NO");
		else printf("YES");
		printf("\n");
	}

	return 0;
}
