/**************************
 * Writer : Leo101
 * Problem : Luogu P4149 [IOI2011]Race
 * Tags : 点分治
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
const int MAXN = 4e5;

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

class Edge
{
	public:
		int next, to, value;
} edges[MAXN];
int head[MAXN], edgesNum;
void addEdge(int from, int to, int value)
{
	edges[edgesNum] = (Edge) {head[from], to, value};
	head[from] = edgesNum++;
}

int size[MAXN];
int globalMin, fullSize, nextRoot, n, k, cnt, ans = INF;
bool vis[MAXN];
void getFocus(int now, int pre = -1)
{
	int maxSize = 0; size[now] = 1;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (to == pre || vis[to] == true) continue;
		getFocus(to, now);
		size[now] += size[to];
		maxSize = std :: max(maxSize, size[to]);
	}

	maxSize = std :: max(maxSize, fullSize - size[now]);
	if (maxSize < globalMin) {
		globalMin = maxSize;
		nextRoot = now;
	}
}
std :: set< std :: pair<int, int> > set;
std :: pair<int, int> dis[MAXN];
void dfs(int now, int pre, int dist, int depth)
{
	if (depth > ans || dist > k) return ;
	dis[cnt++] = std :: make_pair(dist, depth);
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (to == pre || vis[to] == true) continue;
		dfs(to, now, dist + value, depth + 1);
	}
}
void getAns(int now)
{
	set.clear();
	set.insert(std :: make_pair(0, 0));
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (vis[to]) continue;
		cnt = 0; dfs(to, now, value, 1);
		for (int j = 0; j < cnt; j++) {
			auto it = set.lower_bound(std :: make_pair(k - dis[j].first, 0));
			if (it == set.end()) 
				continue;
			if (it -> first + dis[j].first != k) 
				continue;
			ans = std :: min(ans, it -> second + dis[j].second);
		}
		for (int j = 0; j < cnt; j++) 
			set.insert(dis[j]);
	}
}

void divide(int now)
{
	vis[now] = true;
	getAns(now);

	int sizeBackup = fullSize;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (vis[to] == true) continue;
		fullSize = size[to] > size[now] ? sizeBackup - size[now] : size[to];
		globalMin = INF;
		getFocus(to);
		divide(nextRoot);
	}
}

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));

	n = gi, k = gi;
	for (int i = 1; i < n; i++) {
		int from = gi, to = gi, value = gi;
		addEdge(from, to, value); addEdge(to, from, value);
	}

	globalMin = INF; fullSize = n;
	getFocus(0);
	divide(nextRoot);

	if (ans == INF) printf("-1");
	else printf("%d", ans);

	return 0;
}

