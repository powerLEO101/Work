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
const int MAXN = 2e5;
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

char ch[MAXN], ans[MAXN];
int vis[MAXN], inTree[MAXN], connect[MAXN], b[MAXN], rootN, root[MAXN], cnt;
class Edge
{
public:
	int next, to, value;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to, int value)
{
	edges[eNum] = (Edge) {head[from], to, value};
	head[from] = eNum++;
}

void tarjan(int now, int pre = -2)
{
	vis[now] = ++cnt;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (i == (pre ^ 1)) continue;
		if (vis[to] == 0)	{
			inTree[i] = true;
			tarjan(to, i);
		} else if (vis[to] < vis[now]) {
			ans[i >> 1] = 'B';
			b[now]++;
			b[to]--;
		}
	}
}
void dfs(int now, int pre = -1)
{
	for (int i = head[now]; i != -1; i = edges[i].next) {
		if (inTree[i] == false) continue;
		int to = edges[i].to;
		dfs(to, i);
		connect[now] += connect[to];
		b[now] += b[to];
	}
	if (pre == -1) return ;
	if (b[now] != 0) 
		ans[pre >> 1] = 'B';
	else if (connect[now] != 0) 
		ans[pre >> 1] = (connect[now] * edges[pre].value) < 0 ? 'L' : 'R';
	else
		ans[pre >> 1] = 'B';
}

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));
	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int from = gi - 1, to = gi - 1;
		addEdge(from, to, -1);
		addEdge(to, from, 1);
	}
	int p = gi;
	for (int i = 0; i < p; i++) {
		int from = gi - 1, to = gi - 1;
		connect[from]++;
		connect[to]--;
	}
	for (int i = 0; i < n; i++)
		if (vis[i] == false) {
			root[rootN++] = i;
			tarjan(i);
		}
	for (int i = 0; i < rootN; i++)
		dfs(root[i]);
	for (int i = 0; i < m; i++) {
		if (ans[i] != 'L' && ans[i] != 'R' && ans[i] != 'B')
			ans[i] = 'B';
		std::cout << ans[i];
	}

	return 0;
}
