/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2e5;
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

int num[MAXN];
long long sum[MAXN];
std::map<long long, int> map;

int main()
{
	_FILE(code);

	long long ans = 0;
	int n = gi;
	for (int i = 1; i <= n; i++) {
		num[i] = gi;
		sum[i] = sum[i - 1] + num[i];
	}

	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		if (map.count(sum[i]) == 1) {
			tmp = std::max(tmp, map[sum[i]] + 1);
		}
		map[sum[i]] = i; ans += i - tmp;
	}

	std::cout << ans;

	return 0;
}
