/**************************
  * Writer : Leo101
  * Problem : Luogu P4016 负载平衡问题
  * Tags : 网络流
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define INF 0x3f3f3f3f
#define Max_N 1001
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

int S, T;

class Edge
{
public:
	int Next, To, Value, Cost;
}Edges[Max_N << 1];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value, int Cost)
{
	Edges[E_num] = (Edge){Head[From], To, Value, Cost};
	Head[From] = E_num++;
}

class edge
{
public:
	int Index, To;
}Pre[Max_N];

int Dist[Max_N];
bool Vis[Max_N];
bool SPFA()
{
	memset(Dist, 0x3f, sizeof(Dist));
	memset(Vis, 0, sizeof(Vis));
	std::queue<int> Q;
	Q.push(S);
	Dist[S] = 0;
	Vis[S] = true;
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
			if (Value <= 0 || Dist[Now] + Cost >= Dist[To]) continue;
			Pre[To] = (edge) {i, Now};
			Dist[To] = Dist[Now] + Cost;
			if (Vis[To] == false) {
				Q.push(To);
				Vis[To] = true;
			}
		}
		Vis[Now] = false;
	}
	return Dist[T] != INF;
}

int Min_Cost(int n)
{
	int Answer = 0;
	while (SPFA() == true) {
		int Now = T, Min = INF;
		while (Now != S) {
			int To = Pre[Now].To, Index = Pre[Now].Index;
			Min = std::min(Min, Edges[Index].Value);
			Now = To;
		}
		Now = T;
		while (Now != S) {
			int To = Pre[Now].To, Index = Pre[Now].Index;
			Edges[Index].Value -= Min;
			Edges[Index ^ 1].Value += Min;
			Now = To;
		}
		Answer += Min * Dist[T];
	}
	return Answer;
}

int Num[Max_N];
int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi, Aver = 0;
	for (int i = 0; i < n; i++) Num[i] = gi, Aver += Num[i];

	Aver /= n;
	S = n + 1, T = n + 2;
	for (int i = 0; i < n; i++) {
		if (Num[i] < Aver) {
			Add_edge(i, T, Aver - Num[i], 0);
			Add_edge(T, i, 0, 0);
		} else {
			Add_edge(S, i, Num[i] - Aver, 0);
			Add_edge(i, S, 0, 0);
		}
	}
	for (int i = 1; i < n; i++) {
		Add_edge(i - 1, i, INF, 1), Add_edge(i, i - 1, 0, -1);
		Add_edge(i, i - 1, INF, 1), Add_edge(i - 1, i, 0, -1);
	}
	Add_edge(0, n - 1, INF, 1), Add_edge(n - 1, 0, 0, -1);
	Add_edge(n - 1, 0, INF, 1), Add_edge(0, n - 1, 0, -1);

	printf("%d", Min_Cost(n));

	return 0;
}
