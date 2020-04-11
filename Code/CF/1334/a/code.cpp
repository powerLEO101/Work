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
	_FILE(code);

	int T = gi;
	while (T--) {
		int n = gi;
		int preX = gi, preY = gi;
		if (preY > preX) {
			flag = 1;
		}
		int flag = 0;
		for (int i = 1; i < n; i++) {
			int x = gi, y = gi;
			if (preY > preX || (x - preX) < (y - preY) || y < preY || x < preX) {
				flag = 1;
			}
			preX = x; preY = y;
		}
		if (flag == 0)
			std::cout << "YES" << std::endl;
		else 
			std::cout << "NO" << std::endl;
	}

	return 0;
}
