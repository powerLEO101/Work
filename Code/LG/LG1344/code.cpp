/**************************
  * Writer : Leo101
  * Problem : Luogu P1344 [USACO4.4]追查坏牛奶Pollutant Control
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
const int Max_N = 1000001;
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
	int Next, To;
	long long Value;
}Edges[Max_N];
int Head[Max_N], E_num;
void Add_edge(int From, int To, long long Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

int Depth[Max_N], Cur[Max_N];
bool Bfs()
{
	memset(Depth, -1, sizeof(Depth));
	memcpy(Cur, Head, sizeof(Head));

	std::queue<int> Q;
	Q.push(S); Depth[S] = 0;
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To;
			long long Value = Edges[i].Value;
			if (Value <= 0 || Depth[To] != -1) continue;
			Depth[To] = Depth[Now] + 1;
			Q.push(To);
		}
	}
	return Depth[T] != -1;
}
int Dfs(int Now, long long Min)
{
	if (Now == T) return Min;
	long long Used = 0;
	for (int& i = Cur[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To;
		long long Value = Edges[i].Value;
		if (Depth[To] != Depth[Now] + 1 || Value <= 0) continue;
		long long Val = Dfs(To, std::min(Min - Used, Value));
		if (Val != 0) {
			Used += Val;
			Edges[i].Value -= Val;
			Edges[i ^ 1].Value += Val;
		}
		if (Used == Min) break;
	}
	return Used;
}
long long Dinic()
{
	long long Answer = 0;
	while (Bfs()) {
		int Val = Dfs(S, INF);
		while (Val != 0) {
			Answer += Val;
			Val = Dfs(S, INF);
		}
	}
	return Answer;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi, m = gi;
	S = 0, T = n - 1;
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		Add_edge(From, To, 1ll * Value * 10001 + 1); Add_edge(To, From, 0);
	}

	long long Ans = Dinic();
	printf("%lld %lld", Ans / 10001, Ans % 10001);

	return 0;
}
