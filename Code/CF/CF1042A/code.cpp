/**************************
  * Writer : Leo101
  * Problem : CF1042A Benches
  * Tags : 暴力
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 10000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int s[_];

int main()
{
	File(code);
	int n = gi, m = gi;
	for (int i = 0; i < n; i++)
		s[i] = gi;
	std::sort(s, s + n);
	int Ans1 = s[n - 1] + m;
	for (int i = 0; i < n - 1; i++) {
		m -= s[n - 1] - s[i];
		s[i] = s[n - 1];
		if (m < 0) {
			printf("%d", s[n - 1]);
			return 0;
		}
	}
	int Ans = s[n - 1];
	Ans += m / n;
	if (m % n != 0) Ans++;
	printf("%d %d", Ans, Ans1);
	return 0;
}
