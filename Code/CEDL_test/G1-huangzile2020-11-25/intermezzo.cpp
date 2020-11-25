#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int main()
{
	freopen("intermezzo.in", "r", stdin);
	freopen("intermezzo.out", "w", stdout);

	int n = gi;
	if (n < 20) puts("1");
	else puts("0");

	return 0;
}
