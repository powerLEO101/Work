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
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 10000;
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

int X1[MAXN], X2[MAXN], Y1[MAXN], Y2[MAXN];
double k[MAXN], b[MAXN];

int main()
{
	_FILE(cake);

	int R = gi, n = gi, ans = 0;
	for (int i = 0; i < n; i++) {
		X1[i] = gi, Y1[i] = gi, X2[i] = gi, Y2[i] = gi;
		k[i] = 1.0 * (Y2[i] - Y1[i]) / (X2[i] - X1[i]);
		b[i] = -k[i] * X1[i] + Y1[i];
	}

	R *= R;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			double x = 1.0 * (b[j] - b[i]) / (k[i] - k[j]);
			double y = 1.0 * k[i] * x + b[i];
			if (x * x + y * y <= R) ans++;
		}
		ans++;
	}

	std :: cout << ans + 2;

	return 0;
}
