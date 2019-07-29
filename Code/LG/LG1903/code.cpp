/**************************
  * Author : Leo101
  * Problem : Luogu1903 [国家集训队]数颜色 / 维护队列
  * Tags : 莫队
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
	_FILE(code);

	int n = gi, T = gi;
	for (int i = 0; i < n; i++) num[i] = gi;
	int indexQuery, indexModify;
	while (T--) {
		char type;
		std :: cin >> type;
		if (type == 'Q') {
			Q[i]
		} else {
		}
	}

	return 0;
}
