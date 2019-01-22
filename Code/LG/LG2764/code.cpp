/**************************
  * Writer : Leo101
  * Problem : Luogu P2764 最小路径覆盖问题
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
#define Max_N 100001
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

int S, T, n, m;

class Edge
{
public:
	int Next, To, Value;
}Edges[Max_N << 1];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

int Father[Max_N], Next[Max_N];
void Init() {for (int i = 0; i < Max_N; i++) Father[i] = i;}

int Depth[Max_N];
void Bfs()
{
	memset(Depth, -1, sizeof(Depth));
	std::queue<int> Q;
	Q.push(S); 
	Depth[S] = 0;

	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if (Value <= 0 || Depth[To] != -1) continue;
			Depth[To] = Depth[Now] + 1;
			Q.push(To);
		}
	}
}
int Dfs(int Now, int Min)
{
	if (Now == T) return Min;
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (Value <= 0 || Depth[To] != Depth[Now] + 1) continue;
		int Temp = Dfs(To, std::min(Min, Value));
		if (Temp != 0) {
			if (Now != S && To != T) {
				Father[To - n] = Now;
				Next[Now] = To;
			}
			Edges[i].Value -= Temp;
			Edges[i ^ 1].Value += Temp;
			return Temp;
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

	memset(Next, -1, sizeof(Next));
	memset(Head, -1, sizeof(Head));
	Init();

	n = gi, m = gi;
	S = n + n + 1, T = n + n + 2;
	for (int i = 0; i < n; i++) {
		Add_edge(S, i, 1);  Add_edge(i, S, 0);
		Add_edge(i + n, T, 1); Add_edge(T, i + n, 0);
	}
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To + n, INF); Add_edge(To + n, From, 0);
	}
	
	int Ans = Dinic();
	for (int i = 0; i < n; i++) {
		if (Father[i] != i) continue;
		int Now = i;
		printf("%d ", Now + 1);
		while (Next[Now] != -1) {
			Now = Next[Now] - n;
			printf("%d ", Now + 1);
		}
		printf("\n");
	}
	printf("%d", n - Ans);

	return 0;
}
