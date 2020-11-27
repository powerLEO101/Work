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

	int n = gi, sum = 0;
	for (int i = 0; i < n; i++) {
		int v = gi;
		sum += v;
		addEdge(S, i, v);
	}
	for (int i = 0; i < n; i++) {
		int v = gi;
		sum += v;
		addEdge(i, T, v);
	}
	int m = gi;
	for (int i = 0; i < m; i++) {
		int k = gi, av = gi, bv = gi;
		sum += av + bv;
		addEdge(S, n + i, av);
		addEdge(n + m + i, T, bv);
		for (int j = 0; j < k; j++) {
			int pos = gi - 1;
			addEdge(n + i, pos, 0x3f3f3f3f3f3f3f3f);
			addEdge(pos, n + m + i, 0x3f3f3f3f3f3f3f3f);
		}
	}

	int ans = 0;
	for (int i = 0; i < n + m * 2; i++) 
		head1[i] = head[i];
	head1[S] = head[S];
	head1[T] = head[T];
	while (bfs()) {
		ans += dfs();
		for (int i = 0; i < n + m * 2; i++) 
			head[i] = head1[i];
		head[S] = head1[S];
		head[T] = head1[T];
	}
	std::cout << sum - ans;

	return 0;
}
