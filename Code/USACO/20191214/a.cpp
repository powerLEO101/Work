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

int data[1000][1000];

int main()
{
	int K = gi, N = gi;
	for (int i = 0; i < K; i++)
		for (int j = 0; j < N; j++) {
			data[i][gi - 1] = j;
		}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int flag = 0;
			for (int k = 0; k < K; k++) {
				if (data[k][j] < data[k][i]) flag = 1;
			}
			if (flag == 0) ans++; 
		}
	}

	std :: cout << ans;

	return 0;
}

