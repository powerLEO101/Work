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

int map[200][200];

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int n = gi, m = gi;
		std::cout << 'W';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				std::cout << 'B';
			}
			std::cout << std::endl;
		}
	}
	/*
	int T = gi;
	while (T--) {
		int n = gi, m = gi;
		if ((n * m) % 2 == 1) {
			char c = 'B';
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					std::cout << c;
					c = c == 'B' ? 'W' : 'B';
				}
				std::cout << std::endl;
			}
			continue;
		}
		char c = 'B';
		for (int i = 0; i < n; i++) {
			map[0][i] = c;
			c = c == 'B' ? 'W' : 'B';
		}
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c = map[i - 1][j] == 'B' ? 'W' : 'B';
				map[i][j] = c;
			}
		}
		if (map[0][0] == 'W') {
			map[0][0] = 'B';
		} else if (map[0][m - 1] == 'W') {
			map[0][m - 1] = 'B';
		} else if (map[n - 1][0] == 'W') {
			map[n - 1][0] = 'B';
		} else if (map[n - 1][m - 1] == 'W') {
			map[n - 1][m - 1] = 'B';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				std::cout << (char)map[i][j];
			}
			std::cout << std::endl;
		}
	}
	*/

	return 0;
}
