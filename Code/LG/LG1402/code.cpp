#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define gi get_int()
const int MAXN = 2e6, S = MAXN - 1, T = MAXN - 2;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int depth[MAXN];

class Edge
{
public:
	int next, to, value;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge_(int from, int to, int value)
{
	edges[eNum] = (Edge) {head[from], to, value};
	head[from] = eNum++;
}
void addEdge(int from, int to, int value)
{
	addEdge_(from, to, value);
	addEdge_(to, from, 0);
}

int bfs()
{
	std::queue<int> Q;
	Q.push(S);
	memset(depth, -1, sizeof(depth));
	depth[S] = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to, value = edges[i].value;
			if (depth[to] != -1 || value <= 0) continue;
			depth[to] = depth[now] + 1;
			Q.push(to);
		}
	}
	return depth[T] != -1;
}

int dfs(int now = S, int in = 0x3f3f3f3f)
{
	if (now == T)
		return in;
	int out = 0;
	for (int i = head[now]; i != -1 && in > 0; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (depth[to] != depth[now] + 1 || value <= 0) continue;
		int tmp = dfs(to, std::min(in, value));
		edges[i].value -= tmp;
		edges[i ^ 1].value += tmp;
		in -= tmp;
		out += tmp;
	}
	if (out == 0) {
		depth[now] = 0;
	}
	return out;
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	memset(head, -1, sizeof(head));

	int n = gi, p = gi, q = gi;
	for (int i = 0; i < p; i++)
		addEdge(S, n * 2 + i, 1);
	for (int i = 0; i < q; i++)
		addEdge(n * 2 + p + i, T, 1);
	for (int i = 0; i < n; i++)
		addEdge(i, n + i, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			int v = gi;
			if (v == 0) continue;
			addEdge(j + n * 2, i, 1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < q; j++) {
			int v = gi;
			if (v == 0) continue;
			addEdge(i + n, n * 2 + p + j, 1);
		}
	}

	int maxCut = 0;
	while (bfs()) {
		maxCut += dfs();
	}

	std::cout << maxCut;

	return 0;
}
