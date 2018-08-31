#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 300000
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
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
	int Next, To, Value;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

class heap
{
public:
	int Dist, Value;
}Heap[_];
bool operator < (const heap& a, const heap& b)
{
	return a.Dist > b.Dist;
}
int Lenght;
void Insert(int Dist, int Value)
{
	Heap[Lenght++] = (heap){Dist, Value};
	std::push_heap(Heap, Heap + Lenght);
}
int Delete()
{
	std::pop_heap(Heap, Heap + Lenght);
	return Heap[--Lenght].Value;
}
long long Dist[_];
bool Vis[_];
void Dijkstra()
{
	memset(Dist, 0x3f, sizeof(Dist));
	Dist[1] = 1;
	Insert(0, 1);
	while (Lenght) {
		int Now = Delete();
		if (Vis[Now] == true) continue;
		Vis[Now] = true;
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if (Vis[To] == true || Dist[To] <= Dist[Now] + Value) continue;
			Dist[To] = Dist[Now] + Value;
			Insert(Value, To);
		}
	}
}

int main()
{
	File(code);
	memset(Head, -1, sizeof(Head));
	long long h = gi, x = gi, y = gi, z = gi;
	for (int i = 0; i < x; i++) {
		Add_edge(i, (i + y) % x, y);
		Add_edge(i, (i + z) % x, z);
	}
	Dijkstra();
	for (int i = 0; i < x; i++) printf("%d ", Dist[i]);
	printf("\n");
	long long Ans = 0;
	for (int i = 0; i < x; i++)
		if (Dist[i] <= h) Ans += (h - Dist[i]) / x + 1;
	printf("%lld", Ans);
	return 0;
}

