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

int num[1000000];

int cmp(const int& a, const int& b)
{
	return b < a;
}

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int n = gi, m = gi;
		for (int i = 0; i < n; i++) num[i] = gi;
		std::sort(num, num + n, cmp);
		long long tmp = 0;
		int ans = n;
		for (int i = 0; i < n; i++) {
			tmp += num[i];
			if (tmp / (i + 1) < m) {
				ans = i;
				break;
			}
		}
		std::cout << ans << std::endl;
	}
	
	return 0;
}

