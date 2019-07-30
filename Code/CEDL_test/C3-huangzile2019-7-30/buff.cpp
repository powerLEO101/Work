#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define INF 10000000
const int MAXN = 3000, MAXM = 4000;
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

int s1, s2, t1, t2, p1, p2;

class Edge
{
public:
	int next, to;
} edges[MAXM * 2 + 1];
int head[MAXN + 1], edgesNum;
void addEdge(int from, int to)
{
	edges[edgesNum] = (Edge) {head[from], to};
	head[from] = edgesNum++;
}

class Queue
{
public:
	int num[MAXN << 2], l, r;
	void clear()
	{ l = r = 0; }
	void push(int value)
	{ num[r++] = value; }
	void pop()
	{ l++; }
	int front()
	{ return num[l]; }
	int empty()
	{ return l >= r; }
} Q;

int distS1[MAXN + 1], distS2[MAXN + 1], distT1[MAXN + 1], distT2[MAXN + 1];
void getDist(int s, int dist[])
{
	for (int i = 0; i <= MAXN; i++) dist[i] = INF;
	dist[s] = 0;
	Q.clear();
	Q.push(s);

	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to;
			if (dist[to] != INF) continue;
			dist[to] = dist[now] + 1;
			Q.push(to);
		}
	}
}

int vis[MAXN + 1], ans = INF;
void bfs(int now, int from)
{
	for (int i = 0; i <= MAXN; i++) vis[i] = INF;
	Q.clear();
	Q.push(now);
	vis[now] = 0;
	int dist;
	while (!Q.empty()) {
		now = Q.front();
		Q.pop();
		dist = vis[now];
		if (distS1[from] + dist + distT1[now] <= p1 &&\
		    distS2[from] + dist + distT2[now] <= p2)
			ans = std :: min(ans,\
			distS1[from] + distS2[from] + distT1[now] + distT2[now] + dist);
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to;
			if (vis[to] != INF) continue;
			vis[to] = vis[now] + 1;
			Q.push(to);
		}
	}
}

int main()
{
	_FILE(buff);

	memset(head, -1, sizeof(head));

	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int from = gi - 1, to = gi - 1;
		addEdge(from, to);
		addEdge(to, from);
	}

	s1 = gi - 1, t1 = gi - 1, p1 = gi;
	s2 = gi - 1, t2 = gi - 1, p2 = gi;

	getDist(s1, distS1); getDist(t1, distT1);
	getDist(s2, distS2); getDist(t2, distT2);

	/*
	for (int i = 0; i < n; i++) std :: cout << distS1[i] << ' ';
	std :: cout << std :: endl;
	for (int i = 0; i < n; i++) std :: cout << distS2[i] << ' ';
	std :: cout << std :: endl;
	*/

	ans = distS1[t1] + distS2[t2];
	if (distS1[t1] > p1 || distS2[t2] > p2) {
		std :: cout << -1;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		memset(vis, 0, sizeof(vis));
		bfs(i,i);
	}
	
	std :: cout << m - ans;

	return 0;
}
