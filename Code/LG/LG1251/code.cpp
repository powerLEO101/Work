/**************************
  * Writer : Leo101
  * Problem : Luogu P1251 餐巾计划问题
  * Tags : 网络流
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
const int Max_N = 40002;
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
}Edges[Max_N];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value, int Cost)
{
	Edges[E_num] = (Edge) {Head[From], To, Value, Cost};
	Head[From] = E_num++;
}

bool Vis[Max_N];
int Cur[Max_N];
long long Depth[Max_N], Answer;
long long Dist[Max_N];
bool SPFA()
{
	memset(Vis, 0, sizeof(Vis));
	memset(Depth, -1, sizeof(Depth));
	memset(Dist, 0x3f, sizeof(Dist));
	memcpy(Cur, Head, sizeof(Head));

	std::queue<int> Q;
	Q.push(S); Depth[S] = 0;
	Dist[S] = 0; Vis[S] = true;
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
			if (Value <= 0 || Dist[To] <= Dist[Now] + Cost)
				continue;
			Dist[To] = Dist[Now] + Cost;
			if (Vis[To] == false) {
				Vis[To] = true;
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}
	return Dist[T] != Dist[T + 1];
}
long long Dfs(int Now, long long Min)
{
	if (Now == T) return Min;
	if (Vis[Now] == true) return 0;
	Vis[Now] = true;
	long long Used = 0;
	for (int& i = Cur[Now]; i != -1; i = Edges[i].Next) {
		long long To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
		if (Value <= 0 || Dist[To] != Dist[Now] + Cost) continue;
		int Val = Dfs(To, std::min(Min - Used, Value));
		if (Val != 0) {
			Used += Val;
			Answer += Val * Cost;
			Edges[i].Value -= Val;
			Edges[i ^ 1].Value += Val;
		}
		if (Used == Min) break;
	}
	return Used;
}
long long Dinic()
{
	while (SPFA()) {
		memset(Vis, 0, sizeof(Vis));
		while (Dfs(S, INF) != 0) {
			memset(Vis, 0, sizeof(Vis));
		}
	}
	return Answer;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int N = gi;
	S = N * 2 + 1, T = N * 2 + 2;
	for (int i = 0; i < N; i++) {
		int Value = gi;
		Add_edge(S, i, Value, 0); Add_edge(i, S, 0, 0);
		Add_edge(i + N, T, Value, 0); Add_edge(T, i + N, 0, 0);
	}
	int p = gi, m = gi, f = gi, n = gi, s = gi;
	for (int i = 0; i < N; i++) {
		Add_edge(S, i + N, INF, p); Add_edge(i + N, S, 0, -p);
		if (i + m < N) 
			Add_edge(i, i + m + N, INF, f), Add_edge(i + m + N, i, 0, -f);
		if (i + n < N)
			Add_edge(i, i + n + N, INF, s), Add_edge(i + n + N, i, 0, -s);
		if (i + 1 < N)
			Add_edge(i, i + 1, INF, 0), Add_edge(i + 1, i, 0, 0);
	}

	printf("%lld", Dinic());

	return 0;
}
