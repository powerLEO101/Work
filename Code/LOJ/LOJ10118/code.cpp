#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 2048
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

int c[_][_], n, Mod;
int Lowbit(int u) {return u & (-u);}
void Add(int x, int y, int v)
{
	int i = x;
	while (i <= n) {
		int j = y;
		while (j <= n) {
			c[i][j] += v;
			j += Lowbit(j);
		}
		i += Lowbit(i);
	}
}
int Sum(int x, int y)
{
	int i = x, Ans = 0;
	while (i != 0) {
		int j = y;
		while (j != 0) {
			Ans += c[i][j];
			j -= Lowbit(j);
		}
		i -= Lowbit(i);
	}
	return Ans;
}

int main()
{
	File(code);
	n = gi, Mod = gi;
	while (Mod != 3)
	{
		if (Mod == 1) {
			int x = gi + 1, y = gi + 1, v = gi;
			Add(x, y, v);
		} else {
			int x1 = gi + 1, y1 = gi + 1, x2 = gi + 1, y2 = gi + 1;
			printf("%d\n", Sum(x2, y2) + Sum(x1 - 1, y1 - 1) - Sum(x1 - 1, y2) - Sum(x2, y1 - 1));
		}
		Mod = gi;
	}
	return 0;
}
