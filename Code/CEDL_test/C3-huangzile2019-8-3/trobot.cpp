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

int main()
{
	_FILE(trobot);

	int n = gi, S = gi, k = gi;
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int x = gi, y = gi, v = gi;
		ans += v;
	}

	std :: cout << ans;

	return 0;
}
