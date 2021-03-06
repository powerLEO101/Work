/**************************
  * Writer : Leo101
  * Problem : Luogu P2763 试题库问题
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
const int Max_N = 100001;
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
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

int Depth[Max_N], Cur[Max_N];
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

	memset(Head, -1, sizeof Head);

	int k = gi, n = gi, Sum = 0;
	S = k + n + 1, T = k + n + 2;
	for (int i = 0; i < k; i++) {
		int Value = gi;
		Sum += Value;
		Add_edge(n + i, T, Value); Add_edge(T, n + i, 0);
	}
	for (int i = 0; i < n; i++) {
		Add_edge(S, i, 1); Add_edge(i, S, 0);
	}
	for (int i = 0; i < n; i++) {
		int Num = gi;
		for (int j = 0; j < Num; j++) {
			int To = gi - 1;
			Add_edge(i, To + n, 1); Add_edge(To + n, i, 0);
		}
	}

	if (Dinic() < Sum) {
		printf("No Solution!");
	} else {
		for (int i = n; i < n + k; i++) {
			printf("%d: ", i - n + 1);
			for_edge (j, i) {
				int To = Edges[j].To, Value = Edges[j].Value;
				if (Value != 1 || To == T) continue;
				printf("%d ", To + 1);
			}
			printf("\n");
		}
	}

	return 0;
}
