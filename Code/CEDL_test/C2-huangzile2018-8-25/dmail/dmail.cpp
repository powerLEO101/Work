#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int Father[1000005];

int main()
{
	File(dmail);
	int n = gi, m = gi;
	if (m < n) {
		printf("No");
		return 0;
	}
	for (int i = 0; i < m; i++) {
		int From = gi, To = gi;
		if (Father[To] != 0) std::swap(From, To);
		Father[To] = From;
	}
	for (int i = 1; i <= n; i++)
		if (Father[i] == 0) {
			printf("No");
			return 0;
		}
	printf("Yes\n");
	for (int i = 1; i <= n; i++)
		printf("%d\n", Father[i]);
	return 0;
}
