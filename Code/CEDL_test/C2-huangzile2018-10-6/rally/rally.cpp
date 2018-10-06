/***************************
  * Writer : Leo101
  * Problem : Test10-6 rally
  * Tags : 前缀和
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 500
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

long long Num[_][_], Sum[_][_];
int Count[2000000];

long long Get(int x1, int x2, int y)
{
	return Sum[x2][y] - Sum[x1 - 1][y];
}

int main()
{
	File(rally);

	long long n = gi, m = gi, k = gi;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			Num[i][j] = gi,
			Sum[i][j] = Sum[i - 1][j] + Sum[i][j - 1] - Sum[i - 1][j - 1] + Num[i][j];

	long long Ans = 0;
	for (int x1 = 1; x1 <= n; x1++)
		for (int x2 = x1; x2 <= n; x2++) {
			for (int i = 0; i <= m; i++) {
				int Temp = Get(x1, x2, i) % k;
				Ans += Count[Temp];
				Count[Temp]++;
			}
			for (int i = 0; i <= m; i++)
				Count[Get(x1, x2, i) % k] = 0;
		}

	std::cout << Ans;

	return 0;
}

