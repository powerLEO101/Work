#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

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

void dfs(int now = 0)
{
	size[now] = 1;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (to == fa[now]) continue;
		fa[to] = now;
		depth[to] = depth[now] + 1;
		dfs(to);
		size[now] += size[to];
		if (son[now] == -1) 
			son[now] = to;
		else
			son[now] = size[son[now]] > size[to] ? son[now] : to;
	}
}
void dfs1(int now = 0, int pre = 0)
{
	top[now] = pre;
	dfn[now] = cnt++;
	rnk[dfn[now]] = now;
	if (son[now] == -1) return ;
	dfs1(son[now], pre);
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (to == fa[now] || to == son[now]) continue;
		dfs1(to, to);
	}
}

int node[MAXN];

void buildTree(int now = 0, int lRange = 0, int rRange = n)
{
	if (lRange == rRange - 1) {
		node[now] = nodeValue[dfn[lRange]];
		return ;
	}
	int mid = (lRange + rRange) / 2;
	buildTree(now << 1, lRange, mid);
	buildTree(now << 1 | 1, mid, rRange);
	node[now] = std::max(node[now << 1], node[now << 1 | 1]);
}

void modifyNode(int now = 0, int mL, int mR, int lRange = 0, int rRange = n)
{
	if ( //TODO
	if (lRnage
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	int n = gi;
	for (int i = 1; i < n; i++) {
		int from = gi - 1, to = gi - 1, value = gi;
		addEdge(from, to, value);
		addEdge(to, from, value);
	}

	dfs1();

	return 0;
}
