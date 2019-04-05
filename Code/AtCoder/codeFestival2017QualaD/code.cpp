/**************************
  * Author : Leo101
  * Problem : Four Coloring
  * Tags : 贪心，找规律
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

char ch[4] = {'R', 'G', 'B', 'Y'};

int main()
{
	_FILE(code);

	int n = gi, m = gi, k = gi;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = (i + j + m) / k % 2, y = (i - j + m) / k % 2;
			printf("%c", ch[x * 2 + y]);
		}
		printf("\n");
	}

	return 0;
}
