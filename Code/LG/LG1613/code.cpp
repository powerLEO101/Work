/**************************
  * Writer : Leo101
  * Problem : Luogu P1613 跑路
  * Tags : 最短路，倍增
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 100;
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

int n, m;
int Dist[Max_N][Max_N], Sp[Max_N][Max_N][21];

int main()
{
	File(code);

	memset(Dist, 0x3f, sizeof(Dist));

	n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1;
		Dist[From][To] = 1;
		Sp[From][To][0] = true;
	}

	for (int k = 1; k < 21; k++)
	for (int t = 0; t < n; t++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) {
		if (Sp[i][t][k - 1] & Sp[t][j][k - 1]) {
			Sp[i][j][k] = true;
			Dist[i][j] = 1;
		}
	}

	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++) 
	for (int j = 0; j < n; j++)
		Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);

	printf("%d", Dist[0][n - 1]);

	return 0;
}
