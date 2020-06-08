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
const int MAXN = 6e6;
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

int S, T, dis[MAXN];
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

class Heap
{
public:
	int index, value;
} heap[MAXN];
int operator< (const Heap& a, const Heap& b)
{
	return a.value > b.value;
}
int length;
void insert(int index, int value)
{
	heap[length++] = (Heap){index, value};
	std::push_heap(heap, heap + length);
}
int remove()
{
	std::pop_heap(heap, heap + length);
	return heap[--length].index;
}

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));
	int n = gi, m = gi, c = gi;
	for (int i = 0; i < m; i++) {
		int from = gi, to = gi, value = gi;
		addEdge(from, to, value);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 20; j++) {
			int to = i ^ (1 << j);
			if (to > n) continue;
			addEdge(i, to, (1 << j) * c);
			addEdge(to, i, (1 << j) * c);
		}
	}
	S = gi, T = gi;
	memset(dis, 0x3f, sizeof(dis));
	dis[S] = 0;
	insert(S, 0);
	while (length) {
		int now = remove();
		for (int i = head[now]; i != -1; i = edges[i].next) {
			int to = edges[i].to, value = edges[i].value;
			if (dis[now] + value >= dis[to]) continue;
			dis[to] = dis[now] + value;
			insert(to, dis[to]);
		}
	}
	std::cout << dis[T];

	return 0;
}
