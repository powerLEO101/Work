/**************************
  * Writer : Leo101
  * Problem : Luogu P2774 方格取数问题
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
const int Max_N = 500001;
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
	int Next, To, Value;
}Edges[Max_N];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

int Cur[Max_N], Depth[Max_N];
void Bfs()
{
	memset(Depth, -1, sizeof Depth);
	memcpy(Cur, Head, sizeof Head);
	std::queue<int> Q;
	Q.push(S); Depth[S] = 0;

	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if (Depth[To] != -1 || Value <= 0) continue;
			Depth[To] = Depth[Now] + 1;
			Q.push(To);
		}
	}
}
int Dfs(int Now, int Min)
{
	if (Now == T) return Min;
	for (int& i = Cur[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (Value <= 0 || Depth[To] != Depth[Now] + 1) continue;
		int Val = Dfs(To, std::min(Min, Value));
		if (Val != 0) {
			Edges[i].Value -= Val;
			Edges[i ^ 1].Value += Val;
			return Val;
		}
	}
	return 0;
}
int Dinic()
{
	int Answer = 0;
	Bfs();
	while (Depth[T] != -1) {
		int Val = Dfs(S, INF);
		while (Val != 0) {
			Answer += Val;
			Val = Dfs(S, INF);
		}
		Bfs();
	}
	return Answer;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi, m = gi, Sum = 0;
	S = n * m + 1, T = n * m + 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int Value = gi;
			Sum += Value;
			if ((i + j) % 2 == 0)
				Add_edge(S, i * m + j, Value), Add_edge(i * m + j, S, 0);
			else 
				Add_edge(i * m + j, T, Value), Add_edge(T, i * m + j, 0);
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2 != 0) continue;
			if (i - 1 >= 0)
				Add_edge(i * m + j, (i - 1) * m + j, INF),
				Add_edge((i - 1) * m + j, i * m + j, 0);
			if (i + 1 < n)
				Add_edge(i * m + j, (i + 1) * m + j, INF),
				Add_edge((i + 1) * m + j, i * m + j, 0);
			if (j - 1 >= 0) 
				Add_edge(i * m + j, i * m + j - 1, INF),
				Add_edge(i * m + j - 1, i * m + j, 0);
			if (j + 1 < m)
				Add_edge(i * m + j, i * m + j + 1, INF),
				Add_edge(i * m + j + 1, i * m + j, 0);
		}

	printf("%d", Sum - Dinic());

	return 0;
}
