/**************************
  * Author : Leo101
  * Problem : Luogu P1155 双栈排序
  * Tags : 模拟，栈
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int minValue[MAXN];

int main()
{
	_FILE(code);

	int n = gi;
	for (int i = 1; i <= n; i++) num[i] = gi;
	minValue[n] = num[n];
	for (int i = n - 1; i >= 1; i--) 
		minValue[i] = std :: min(minValue[i + 1], num[i]);
	for (int i = 1; i <= n; i++)

	return 0;
}
