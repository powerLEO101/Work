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
const int MAXN = 60;
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

class Edge
{
public:
	int next, to;
} edges[MAXN * MAXN * 5];
int head[MAXN * MAXN], eNum;
void addEdge(int from, int to)
{
	edges[eNum] = (Edge){head[from], to};
	head[from] = eNum++;
}
int cnt, vis[MAXN * MAXN], belongX[MAXN][MAXN], belongY[MAXN][MAXN], con[MAXN * MAXN];
char map[MAXN][MAXN];

int dfs(int now)
{
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (vis[to] == true) continue;
		vis[to] = true;
		if (con[to] == -1) {
			con[to] = now;
			return 1;
		}
		if (dfs(con[to]) == 1) {
			con[to] = now;
			return 1;
		}
	}
	return 0;
}
int getAns(int n, int m)
{
	int ans = 0;
	for (int i = 0; i <= cnt; i++) {
		memset(vis, 0, sizeof(vis));
		ans += dfs(i);
	}
	return ans;
}

int main()
{
	_FILE(code);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> map[i][j];
	memset(head, -1, sizeof(head));
	memset(belongX, -1, sizeof(belongX));
	memset(belongY, -1, sizeof(belongY));
	memset(con, -1, sizeof(con));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '#') continue;
			if (j == 0 || map[i][j - 1] == '#') cnt++;
			belongX[i][j] = cnt;
		}
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++) {
			if (map[i][j] == '#') continue;
			if (i == 0 || map[i - 1][j] == '#') cnt++;
			belongY[i][j] = cnt;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] != '*') continue;
			addEdge(belongX[i][j], belongY[i][j]);
		}
	std::cout << getAns(n, m);

	return 0;
}
