/**************************
  * Writer : Leo101
  * Problem : Luogu P3385 【模板】负环
  * Tags : SPFA, 最短路
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define YES "YE5"
#define NO "N0"
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 500000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
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

int Count[_], Dist[_];
bool Vis[_];

void SPFA(int n)
{
	std::queue<int> Q;
	Q.push(0);
	memset(Vis, 0, sizeof(Vis));
	for (int i = 0; i < _; i++) Dist[i] = 2147483647;
	memset(Count, 0, sizeof(Count));
	Dist[0] = 0;
	Vis[0] = true;

	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		Vis[Now] = false;
		for_edge (i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if (Dist[To] <= Dist[Now] + Value) continue;
			Dist[To] = Dist[Now] + Value;
			if (Vis[To] == false) {
				Vis[To] = true;
				Count[To]++;
				if (Count[To] >= n) {
					printf(YES);
					return ;
				}
				Q.push(To);
			}
		}
	}

	printf(NO);
}

int main()
{
	File(code);

	int T = gi;

	while (T--) {
		int n = gi, m = gi;
		memset(Head, -1, sizeof(Head));
		for (int i = 0; i < m; i++) {
			int From = gi - 1, To = gi - 1, Value = gi;
			if (Value < 0)
				Add_edge(From, To, Value); 
			else {
				Add_edge(From, To, Value);
				Add_edge(To, From, Value);
			}
		}

		SPFA(n);

		printf("\n");
		E_num = 0;
	}
	return 0;
}
