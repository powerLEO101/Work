#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long
#define gi get_int()
const int MAXN = 7e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, rank[MAXN << 4], lSon[MAXN], rSon[MAXN], vis[MAXN], cnt = 1;

class Edge
{
public:
	int next, to, value;
} edges[MAXN << 2];
int head[MAXN << 2], eNum;
void addEdge(int from, int to, int value)
{
	edges[eNum] = (Edge) {head[from], to, value};
	head[from] = eNum++;
}

void buildTree1(int now, int lRange = 0, int rRange = n)
{
	if (lRange + 1 == rRange) {
		rank[lRange] = now;
		return ;
	}
	int mid = (lRange + rRange) / 2;
	lSon[now] = cnt++;
	rSon[now] = cnt++;
	addEdge(now, lSon[now], 0);
	addEdge(now, rSon[now], 0);
	buildTree1(lSon[now], lRange, mid);
	buildTree1(rSon[now], mid, rRange);
}
void buildTree2(int now, int lRange = 0, int rRange = n)
{
	if (lRange + 1 == rRange) {
		return ;
	}
	int mid = (lRange + rRange) / 2;
	if (lRange == mid - 1) {
		lSon[now] = rank[lRange];
		addEdge(rank[lRange], now, 0);
	} else {
		lSon[now] = cnt++;
		addEdge(lSon[now], now, 0);
	} 
	if (mid == rRange - 1) {
		rSon[now] = rank[mid];
		addEdge(rank[mid], now, 0);
	} else  {
		rSon[now] = cnt++;
		addEdge(rSon[now], now, 0);
	}
	buildTree2(lSon[now], lRange, mid);
	buildTree2(rSon[now], mid, rRange);
}

void modify(int now, int from, int toL, int toR, int value, int mode, int lRange = 0, int rRange = n)
{
	if (toR <= lRange || rRange <= toL) return ;
	if (toL <= lRange && rRange <= toR) {
		if (mode == 2)
			addEdge(from, now, value);
		if (mode == 3)
			addEdge(now, from, value);
		return ;
	}
	int mid = (lRange + rRange) / 2;
	modify(lSon[now], from, toL, toR, value, mode, lRange, mid);
	modify(rSon[now], from, toL, toR, value, mode, mid, rRange);
}

std::pair<int, int> heap[MAXN];
int dis[MAXN], heapSize;
int cmp(const std::pair<int, int>& a, const std::pair<int, int>& b)
{
	return a.second >= b.second;
}
void push(int rank, int value)
{
	heap[heapSize++] = std::make_pair(rank, value);
	std::push_heap(heap, heap + heapSize, cmp);
}
int pop()
{
	std::pop_heap(heap, heap + heapSize, cmp);
	return heap[--heapSize].first;
}

signed main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	memset(head, -1, sizeof(head));

	n = gi;
	int q = gi, s = gi - 1;
	buildTree1(0);
	int root2 = cnt;
	buildTree2(cnt++);
	while (q--) {
		int mode = gi;
		if (mode == 1) {
			int from = gi - 1, to = gi - 1, value = gi;
			addEdge(rank[from], rank[to], value);
		} else if (mode == 2) {
			int from = gi - 1, toL = gi - 1, toR = gi, value = gi;
			modify(0, rank[from], toL, toR, value, 2);
		} else if (mode == 3) {
			int from = gi - 1, toL = gi - 1, toR = gi, value = gi;
			modify(root2, rank[from], toL, toR, value, 3);
		}
	}

	memset(dis, 0x3f, sizeof(dis));
	dis[rank[s]] = 0;
	push(rank[s], 0);
	while (heapSize != 0) {
		int now = pop();
		vis[now] = false;
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to, value = edges[i].value;
			if (dis[now] + value >= dis[to])
				continue;
			dis[to] = dis[now] + value;
			if (vis[to] == false) {
				vis[to] = true;
				push(to, dis[to]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (dis[rank[i]] == 0x3f3f3f3f3f3f3f3f)
			std::cout << -1 << ' ';
		else {
				std::cout << dis[rank[i]] << ' ';
		}
	}

	return 0;
}
