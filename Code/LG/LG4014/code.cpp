/**************************
  * Writer : Leo101
  * Problem : Luogu P4014 分配问题
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
const int Max_N = 10001;
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
	int Next, To, Value, Cost, Value1;
}Edges[Max_N];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value, int Cost)
{
	Edges[E_num] = (Edge) {Head[From], To, Value, Cost, Value};
	Head[From] = E_num++;
}

int Answer;
int Dist[Max_N], Cur[Max_N];
bool Vis[Max_N];
bool SPFA(int CASE)
{
	if (CASE == 1)
		memset(Dist, -0x3f, sizeof(Dist));
	else 
		memset(Dist, 0x3f, sizeof(Dist));
	memset(Vis, 0, sizeof(Vis));
	memcpy(Cur, Head, sizeof(Head));

	std::queue<int> Q;
	Q.push(S); Dist[S] = 0;
	Vis[S] = true;

	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
			if (Value <= 0) continue;
			if (CASE == 0 && Dist[To] <= Dist[Now] + Cost) continue;
			if (CASE == 1 && Dist[To] >= Dist[Now] + Cost) continue;
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
int Dfs(int Now, int Min)
{
	if (Now == T) return Min;
	if (Vis[Now] == true) return 0;
	Vis[Now] = true;
	
	for (int& i = Cur[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
		if(Value <= 0 || Dist[To] != Dist[Now] + Cost) continue;
		int Val = Dfs(To, std::min(Min, Value));
		if (Val != 0) {
			Answer += Cost * Val;
			Edges[i].Value -= Val;
			Edges[i ^ 1].Value += Val;
			return Val;
		}
	}

	return 0;
}
int Dinic(int CASE)
{
	for (int i = 0; i < E_num; i++) Edges[i].Value = Edges[i].Value1;
	Answer = 0;
	int Ret = 0;
	while (SPFA(CASE)) {
		memset(Vis, 0, sizeof(Vis));
		int Val = Dfs(S, INF);
		while (Val != 0) {
			Ret += Val;
			memset(Vis, 0, sizeof(Vis));
			Val = Dfs(S, INF);
		}
	}

	return Answer;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	S = n + n + 1, T = n + n + 2;
	
	for (int i = 0; i < n; i++) {
		Add_edge(S, i, 1, 0);
		Add_edge(i, S, 0, 0);

		Add_edge(i + n, T, 1, 0);
		Add_edge(T, i + n, 0, 0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int Value = gi;
			Add_edge(i, j + n, 1, Value);
			Add_edge(j + n, i, 0, -Value);
		}

	printf("%d\n%d", Dinic(0), Dinic(1));

	return 0;
}
