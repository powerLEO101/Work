#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
const int MAXN = 260100;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int mapD[200], dis[MAXN], vis[MAXN];

class Edge
{
public:
	int next, to, value;
} edges[MAXN << 3];
int head[MAXN], eNum;
void addEdge(int from, int to, int value)
{
	edges[eNum] = (Edge) {head[from], to, value};
	head[from] = eNum++;
}

int getDis(char ch, char target)
{
	int ret = mapD[target] - mapD[ch];
	if (ret >= 0) return ret;
	return 4 + ret;
}

int heap[MAXN];
int heapSize;
int cmp(const int& a, const int& b)
{
	return dis[a] >= dis[b];
}
void push(int index)
{
	heap[heapSize++] = index;
	std::push_heap(heap, heap + heapSize, cmp);
}
int remove()
{
	std::pop_heap(heap, heap + heapSize, cmp);
	return heap[--heapSize];
}

int main()
{
	freopen("code.in", "r", stdin);
	freopen("code.out", "w", stdout);

	memset(head, -1, sizeof(head));

	mapD['N'] = 0;
	mapD['E'] = 1;
	mapD['S'] = 2;
	mapD['W'] = 3;
	int n = gi, m = gi;
	char ch;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ch = getchar();
			while (ch != 'X' && ch != 'N' && ch != 'W' && ch != 'S' && ch != 'E')
				ch = getchar();
			if (ch == 'X') continue;
			if (i - 1 != -1)
				addEdge(i * m + j, (i - 1) * m + j, getDis(ch, 'N'));
			if (i + 1 != n)
				addEdge(i * m + j, (i + 1) * m + j, getDis(ch, 'S'));
			if (j - 1 != -1)
				addEdge(i * m + j, i * m + j - 1, getDis(ch, 'W'));
			if (j + 1 != m)
				addEdge(i * m + j, i * m + j + 1, getDis(ch, 'E'));
		}
	}

	memset(dis, 0x3f, sizeof(dis));
	dis[0] = 0;
	push(0);
	while (heapSize != 0) {
		int now = remove();
		if (vis[now] == true) continue;
		vis[now] = true;
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to, value = edges[i].value;
			if (dis[now] + value >= dis[to]) continue;
			dis[to] = dis[now] + value;
			push(to);
		}
	}

	if (dis[n * m - 1] == 0x3f3f3f3f) 
		std::cout << -1;
	else 
		std::cout << dis[n * m - 1];

	return 0;
}
