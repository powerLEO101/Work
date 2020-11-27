#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define gi get_int()
#define int long long 
const int MAXN = 2e6, S = MAXN - 1, T = MAXN - 2;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int depth[MAXN], head1[MAXN];

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
	std::queue<int> q;
	q.push(S);
	memset(depth, -1, sizeof(depth));
	depth[S] = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to, value = edges[i].value;
			if (depth[to] != -1 || value <= 0) continue;
			depth[to] = depth[now] + 1;
			q.push(to);
		}
	}
	return depth[T] != -1;
}

int dfs(int now = S, int in = 0x3f3f3f3f3f3f3f3f)
{
	if (now == T) 
		return in;
	int out = 0;
	for (int &i = head[now]; i != -1 & in != 0; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (depth[to] != depth[now] + 1 || value <= 0) continue;
		int tmp = dfs(to, std::min(in, value));
		edges[i].value -= tmp;
		edges[i ^ 1].value += tmp;
		in -= tmp;
		out += tmp;
	}
	if (out == 0)
		depth[now] = -1;
	return out;
}

signed main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	memset(head, -1, sizeof(head));

	int n = gi, m = gi, sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int v = gi;
			sum += v;
			addEdge(S, i * m + j, v);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int v = gi;
			sum += v;
			addEdge(i * m + j, T, v);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int v = gi;
			sum += v;
			addEdge(S, n * m + i * m + j, v);
			addEdge(n * m + i * m + j, i * m + j, 0x3f3f3f3f3f3f3f3f);
			if (i - 1 != -1)
				addEdge(n * m + i * m + j, (i - 1) * m + j, 0x3f3f3f3f3f3f3f3f);
			if (i + 1 != n)
				addEdge(n * m + i * m + j, (i + 1) * m + j, 0x3f3f3f3f3f3f3f3f);
			if (j - 1 != -1)
				addEdge(n * m + i * m + j, i * m + j - 1, 0x3f3f3f3f3f3f3f3f);
			if (j + 1 != m)
				addEdge(n * m + i * m + j, i * m + j + 1, 0x3f3f3f3f3f3f3f3f);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int v = gi;
			sum += v;
			addEdge(n * m * 2 + i * m + j, T, v);
			addEdge(i * m + j, n * m * 2 + i * m + j, 0x3f3f3f3f3f3f3f3f);
			if (i - 1 != -1)
				addEdge((i - 1) * m + j, n * m * 2 + i * m + j, 0x3f3f3f3f3f3f3f3f);
			if (i + 1 != n)
				addEdge((i + 1) * m + j, n * m * 2 + i * m + j, 0x3f3f3f3f3f3f3f3f);
			if (j - 1 != -1)
				addEdge(i * m + j - 1, n * m * 2 + i * m + j, 0x3f3f3f3f3f3f3f3f);
			if (j + 1 != m)
				addEdge(i * m + j + 1, n * m * 2 + i * m + j, 0x3f3f3f3f3f3f3f3f);
		}
	int ans = 0;
	for (int i = 0; i < n * m * 3; i++) 
		head1[i] = head[i];
	head1[S] = head[S];
	head1[T] = head[T];
	while (bfs()) {
		ans += dfs();
		for (int i = 0; i < n * m * 3; i++) 
			head[i] = head1[i];
		head[S] = head1[S];
		head[T] = head1[T];
	}
	std::cout << sum - ans;

	return 0;
}
