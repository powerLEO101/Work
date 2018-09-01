#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 200000
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
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

long long Dist[_], h, x, y, z;
bool Vis[_];
void SPFA()
{
	memset(Dist, 0x3f, sizeof(Dist));
	memset(Vis, 0, sizeof(Vis));
	std::queue<int> Q;
	Q.push(1 % x);
	Vis[1 % x] = true;
	Dist[1 % x] = 1;
	while (!Q.empty()) {
		int Now = Q.front();Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if (Dist[To] <= Dist[Now] + Value) continue;
			Dist[To] = Dist[Now] + Value;
			if (Vis[To] == false) {
				Vis[To] = true;
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}
}

int main()
{
	File(code);
	memset(Head, -1, sizeof(Head));
	h = gi, x = gi, y = gi, z = gi;
	for (int i = 0; i < x; i++) {
		Add_edge(i, (i + y) % x, y);
		Add_edge(i, (i + z) % x, z);
	}
	SPFA();
	long long Ans = 0;
	for (int i = 0; i < x; i++)
		if (Dist[i] <= h) Ans += (h - Dist[i]) / x + 1;
	printf("%lld", Ans);
	return 0;
}
