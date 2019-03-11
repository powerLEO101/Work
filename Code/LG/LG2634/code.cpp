/**************************
  * Writer : Leo101
  * Problem : Luogu P2634 [国家集训队]聪聪可可
  * Tags : 点分治，数学
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 4e4, INF = 0x3f3f3f3f;
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
} edges[MAXN << 1];
int head[MAXN], edgesNum;
void addEdge(int from, int to, int value)
{
	edges[edgesNum] = (Edge) {head[from], to, value};
	head[from] = edgesNum++;
}

int size[MAXN], count[MAXN], dis[MAXN];
int globalMin, nextRoot, fullSize, cnt;
bool vis[MAXN];
long long ans;
void getFocus(int now, int pre = -1)
{
	int maxVal = 0; size[now] = 1;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		if (vis[to] == true || to == pre) continue;
		getFocus(to, now);
		size[now] += size[to];
		maxVal = std :: max(maxVal, size[to]);
	}

	maxVal = std :: max(maxVal, fullSize - size[now]);
	if (maxVal < globalMin) {
		globalMin = maxVal;
		nextRoot = now;
	}
}
void dfs(int now, int extra, int pre = -1, int dist = 0)
{
	dis[cnt++] = dist + extra;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (to == pre || vis[to] == true) continue;
		dfs(to, extra, now, dist + value);
	}
}
long long getAns(int now, int extra)
{
	memset(count, 0, sizeof(count));
	cnt = 0; dfs(now, extra);

	for (int i = 0; i < cnt; i++) count[dis[i] % 3]++;
	return 2ll * count[1] * count[2] + (count[0] == 0 ? 0 : 1ll * count[0] * (count[0] - 1));
}
void divide(int now)
{
	vis[now] = true;
	ans += getAns(now, 0);

	int sizeBackup = fullSize;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (vis[to] == true) continue;
		ans -= getAns(to, value);
		fullSize = size[to] > size[now] ? sizeBackup - size[now] : size[to];
		globalMin = INF;
		getFocus(to);
		divide(nextRoot);
	}
}

long long getGcd(long long x, long long y)
{ return y == 0 ? x : getGcd(y, x % y); }

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));

	int n = gi;
	for (int i = 1; i < n; i++) {
		int from = gi, to = gi, value = gi;
		addEdge(from, to, value); addEdge(to, from, value);
	}

	fullSize = n; globalMin = INF;
	getFocus(1);
	divide(nextRoot);
	ans += n;
	
	long long gcd = getGcd(ans, 1ll * n * n);
	printf("%lld/%lld", ans / gcd, 1ll * n * n / gcd);

	return 0;
}
