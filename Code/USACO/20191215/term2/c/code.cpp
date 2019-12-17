/**************************
  * Author : Zile Huang
  * Problem : 20191215Problem 3. Milk Visits
  * Tags : 倍增
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2e5;
#define int long long
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

int up[MAXN][21], value[MAXN][21][2], deep[MAXN];

class Edge
{
public:
	int next, to;
} edges[MAXN];
int head[MAXN], edgesN;
void addEdge(int from, int to)
{
	edges[edgesN] = (Edge) {head[from], to};
	head[from] = edgesN++;
}

void dfs(int now)
{
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == up[now][0]) continue;
		up[to][0] = now;
		deep[to] = deep[now] + 1;
		dfs(to);
	}
}

int ret;

int getUp(int u, int v, int x)
{
	ret = 0;
	for (int i = 20; i >= 0; i--) {
		if (deep[up[u][i]] > deep[v]) {
			ret += value[u][i][x];
			u = up[u][i];
		}
	}
	if (deep[u] != deep[v]) {
		ret += value[u][0][x];
		u = up[u][0];
	}
	return u;
}
int lcaValue(int u, int v, int x)
{
	if (deep[v] > deep[u]) std :: swap(u, v);
	u = getUp(u, v, x);
	//std :: cout << std :: endl << "Ret : " << ret;
	for (int i = 20; i >= 0; i--) {
		if (up[u][i] != up[v][i]) {
			ret += value[u][i][x] + value[v][i][x];
			u = up[u][i];
			v = up[v][i];
		}
	}
	if (u != v) {
		ret += value[u][0][x] + value[v][0][x];
		u = up[u][0];
		v = up[v][0];
		return ret + value[u][0][x];
	}
	//std :: cout << std :: endl << u << std :: endl;
	return ret;
}

int getAns(int u, int v, int x)
{
	return lcaValue(u, v, x) > 0;
}

signed main()
{
	_FILE(milkvisits);

	memset(head, -1, sizeof(head));

	int n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		char ch;
		std :: cin >> ch;
		if (ch == 'H') value[i][0][0] = 1;
		if (ch == 'G') value[i][0][1] = 1;
	}

	for (int i = 1; i < n; i++) {
		int u = gi - 1, v = gi - 1;
		addEdge(u, v); addEdge(v, u);
	}

	dfs(0);
	for (int j = 1; j <= 20; j++) {
		for (int i = 0; i < n; i++) {
			up[i][j] = up[up[i][j - 1]][j - 1];
			value[i][j][0] = value[i][j - 1][0] + value[up[i][j - 1]][j - 1][0];
			value[i][j][1] = value[i][j - 1][1] + value[up[i][j - 1]][j - 1][1];
			//std :: cout << value[i][j][0] << ' ';
		}
		//std :: cout << std :: endl;
	}

	for (int i = 0; i < m; i++) {
		int u = gi - 1, v = gi - 1;
		char ch;
		std :: cin >> ch;
		if (ch == 'H') std :: cout << getAns(u, v, 0);
		if (ch == 'G') std :: cout << getAns(u, v, 1);
		//std :: cout << std :: endl;
	}

	return 0;
}
