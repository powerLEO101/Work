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
const int MAXCOL = 51, MAXN = 2e5 + 10;
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

int col[MAXN], cof[MAXN], cofPos[MAXN], colCnt[MAXN][MAXCOL];

int main()
{
	_FILE(code);

	int n = gi, k = gi, p = gi;
	for (int i = 0; i < n; i++) {
		col[i] = gi;
		colCnt[i][col[i]]++;
		cof[i] = gi <= p;
		for (int j = 0; j <= 50; j++)
			colCnt[i + 1][j] = colCnt[i][j];
	}
	cofPos[0] = cof[0] == 1 ? 0 : -1;
	for (int i = 1; i < n; i++) {
		if (cof[i] == 1) 
			cofPos[i] = i;
		else
			cofPos[i] = cofPos[i - 1];
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 50; j++)
			std::cout << colCnt[i][j] << ' ';
		std::cout << std::endl;
	}
	*/
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int lastCof = cofPos[i];
		if (lastCof == i)
			ans += colCnt[lastCof - 1][col[i]];
		else 
			ans += colCnt[lastCof][col[i]];
	}
	std::cout << ans;

	return 0;
}
