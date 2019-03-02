/**************************
  * Writer : Leo101
  * Problem : Luogu P3805 【模板】manacher算法
  * Tags : Manacher
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
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

int main()
{
	File(code);

	std :: string Str, Tmp;
	std :: cin >> Tmp;

	for (auto it = Tmp.begin(); it != Tmp.end(); it++) {
		Str += *it;
		Str += "#";
	}

	return 0;
}
