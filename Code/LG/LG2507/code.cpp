#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long 
const int INF = 0x3f3f3f3f3f3f3f3f;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-')
		y = -1, ch = getchar(); 
	while (isdigit(ch))
		x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int f[1000000], numA[1000000], numB[1000000];

int judge(int value)
{ return value < 0 ? 0 : f[value]; }
int ABS(int value)
{ return value < 0 ? -value : value; }
int value(int i, int j)
{
	if (numA[i] == numB[j]) return INF;
	return ABS(numA[i] - numB[j]);
}

signed main()
{
	_FILE(code);

	int n = gi;
	for (int i = 1; i <= n; i++) numA[i] = gi, numB[i] = gi;
	std :: sort(numA + 1, numA + n + 1);
	std :: sort(numB + 1, numB + n + 1);

	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = INF;
		if (i >= 1) f[i] = std :: min(f[i], f[i - 1] + value(i, i));
		if (i >= 2) f[i] = std :: min(f[i], f[i - 2] + value(i, i - 1) + value(i - 1, i));
		if (i >= 3) {
			f[i] = std :: min(f[i], f[i - 3] + value(i - 2, i - 1) + value(i - 1, i) + value(i, i - 2));
			f[i] = std :: min(f[i], f[i - 3] + value(i - 2, i) + value(i - 1, i - 2) + value(i, i - 1));
		}
	}

	std :: cout << f[n];

	return 0;
}
