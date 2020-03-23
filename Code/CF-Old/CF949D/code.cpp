/**************************
  * Writer : Leo101
  * Problem : CF949D Curfew
  * Tags : 贪心, (或者二分答案)
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100100
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

long long s[_];

int main()
{
	File(code);

	long long n = gi, D = gi, B = gi, X, Ans1 = 0, Ans2 = 0;
	s[1] = gi;
	for (int i = 2; i <= n; i++) s[i] = s[i - 1] + gi;

	for (int i = 1; i <= n / 2; i++) {
		X = s[std::min(n, i * (D + 1))] - B * Ans1;
		if (X >= B) Ans1++;

		X = s[n] - s[std::max(0ll, n - i * (D + 1))] - B * Ans2;
		if (X >= B) Ans2++;
	}

	std::cout<<n / 2 - std::min(Ans1, Ans2);
	return 0;
}
