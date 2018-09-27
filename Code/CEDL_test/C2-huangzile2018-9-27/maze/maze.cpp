/***************************
  * Writer : Leo101
  * Problem : Test9-27 maze
  * Tags : 二分答案, 最短路
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define eps 1e-5
#define INF 0x3f3f3f3f
#define _ 1001
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Map[_][_];
int Gox[4] = {1, -1, 0, 0}, Goy[4] = {0, 0, 1, -1};
int sx, sy, ex, ey, n, m;
double s, Dist[_][_];
bool Vis[_][_];

double Check(double Mid)
{
	std::queue<int> Qx, Qy;
	Qx.push(sx);
	Qy.push(sy);
	Vis[sx][sy] = true;
	Dist[sx][sy] = 0;
	while (!Qx.empty()) {
		int Nowx = Qx.front(), Nowy = Qy.front();
		Qx.pop(); Qy.pop();
		Vis[Nowx][Nowy] = false;
		for (int i = 0; i < 4; i++) {
			int x = Nowx + Gox[i], y = Nowy + Goy[i];
			double Value = i < 2 ? Mid : 1;
			if (x == -1 || x == n || y == -1 || y == m) continue;
			if (Map[x][y] == 1 || Dist[x][y] - (Dist[Nowx][Nowy] + Value) < eps) continue;
			Dist[x][y] = Dist[Nowx][Nowy] + Value;
			if (Vis[x][y] == false) {
				Vis[x][y] = true;
				Qx.push(x);
				Qy.push(y);
			}
		}
	}
	return Dist[ex][ey];
}

int main()
{
	File(maze);

	n = gi, m = gi;
	sx = gi - 1, sy = gi - 1, ex = gi - 1, ey = gi - 1;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			Map[i][j] = gi;
	std::cin >> s;

	double l = 0, r = 1000000;
	while (r - l > eps) {
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				Dist[i][j] = 1000000000;
		double Mid = (l + r) / 2;
		if (Check(Mid) - s < eps)
			l = Mid;
		else r = Mid;
	}
	
	printf("%.3f", l);

	return 0;
}
