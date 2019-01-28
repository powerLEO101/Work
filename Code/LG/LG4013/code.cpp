/**************************
  * Writer : Leo101
  * Problem : Luogu P4013 数字梯形问题
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
const int Max_N = 30, Max_E = 10001;
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

int Num[Max_N][Max_N], S, T, Number[Max_N][Max_N];

class Edge
{
public:
	int Next, To, Value, Cost;
}Edges[Max_E];
int Head[Max_E], E_num;
void Add_edge(int From, int To, int Value, int Cost)
{
	Edges[E_num] = (Edge){Head[From], To, Value, Cost};
	Head[From] = E_num++;
}

bool Vis[Max_E];
long long Dist[Max_E];
int Cur[Max_E];
bool SPFA()
{
	memcpy(Cur, Head, sizeof(Head));
	memset(Vis, 0, sizeof(Vis));
	for (int i = 0; i < Max_N * Max_N * 8; i++)
		Dist[i] = -INF;

	std::queue<int> Q;
	Q.push(S);
	Vis[S] = true;
	Dist[S] = 0;
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
			if (Value <= 0 || Dist[To] >= Dist[Now] + Cost) continue;
			Dist[To] = Dist[Now] + Cost;
			if (Vis[To] == false) {
				Vis[To] = true;
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}

	return Dist[T] != -INF;
}
int Answer;
int Dfs(int Now, int Min)
{
	if (Now == T) return Min;
	if (Vis[Now] == true) return 0;
	Vis[Now] = true;
	for (int& i = Cur[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
		if (Value <= 0 || Dist[To] != Dist[Now] + Cost) continue;
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
int Dinic()
{
	Answer = 0;
	while (SPFA()) {
		memset(Vis, 0, sizeof(Vis));
		while (Dfs(S, INF))
			memset(Vis, 0, sizeof(Vis));
	}
	return Answer;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));
	
	int m = gi, n = gi, Sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + m; j++)
			Num[i][j] = gi, Number[i][j] = Sum++;
	Sum *= 2;
	S = Sum + 1, T = Sum + 2;
	int Squ = (m + n + m - 1) * n / 2;

	/*CASE 1*/

	for (int i = 0; i < m; i++)
		Add_edge(S, Number[0][i], 1, 0), Add_edge(Number[0][i], S, 0, 0);
	for (int i = 0; i < n + m - 1; i++)
		Add_edge(Number[n - 1][i] + Squ, T, 1, 0), Add_edge(T, Number[n - 1][i] + Squ, 0, 0);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0 ; j < i + m; j++) {
			Add_edge(Number[i][j], Number[i][j] + Squ, 1, Num[i][j]);
			Add_edge(Number[i][j] + Squ, Number[i][j], 0, -Num[i][j]);

			Add_edge(Number[i][j] + Squ, Number[i + 1][j], 1, 0);
			Add_edge(Number[i + 1][j], Number[i][j] + Squ, 0, 0);

			Add_edge(Number[i][j] + Squ, Number[i + 1][j + 1], 1, 0);
			Add_edge(Number[i + 1][j + 1], Number[i][j] + Squ, 0, 0);
		}
	}
	for (int i = 0; i < n + m - 1; i++) {
		Add_edge(Number[n - 1][i], Number[n - 1][i] + Squ, 1, Num[n - 1][i]);
		Add_edge(Number[n - 1][i] + Squ, Number[n - 1][i], 0, -Num[n - 1][i]);
	}

	printf("%d\n", Dinic());

	/*CASE 2*/
	
	memset(Head, -1, sizeof(Head));
	memset(Edges, 0, sizeof(Edges));
	E_num = 0;
	
	for (int i = 0; i < m; i++) {
		Add_edge(S, Number[0][i], 1, 0);
		Add_edge(Number[0][i], S, 0, 0);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m + i; j++) {
			Add_edge(Number[i][j], Number[i + 1][j], 1, Num[i][j]);
			Add_edge(Number[i + 1][j], Number[i][j], 0, -Num[i][j]);
			
			Add_edge(Number[i][j], Number[i + 1][j + 1], 1, Num[i][j]);
			Add_edge(Number[i + 1][j + 1], Number[i][j], 0, -Num[i][j]);
		}
	}
	for (int i = 0; i < n + m + 1; i++) {
		Add_edge(Number[n - 1][i], T, INF, Num[n - 1][i]);
		Add_edge(T, Number[n - 1][i], 0, -Num[n - 1][i]);
	}

	printf("%d\n", Dinic());

	/*CASE 3*/

	memset(Head, -1, sizeof(Head));
	memset(Edges, 0, sizeof(Edges));
	E_num = 0;
	
	for (int i = 0; i < m; i++) {
		Add_edge(S, Number[0][i], 1, 0);
		Add_edge(Number[0][i], S, 0, 0);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m + i; j++) {
			Add_edge(Number[i][j], Number[i + 1][j], INF, Num[i][j]);
			Add_edge(Number[i + 1][j], Number[i][j], 0, -Num[i][j]);
			
			Add_edge(Number[i][j], Number[i + 1][j + 1], INF, Num[i][j]);
			Add_edge(Number[i + 1][j + 1], Number[i][j], 0, -Num[i][j]);
		}
	}
	for (int i = 0; i < n + m + 1; i++) {
		Add_edge(Number[n - 1][i], T, INF, Num[n - 1][i]);
		Add_edge(T, Number[n - 1][i], 0, -Num[n - 1][i]);
	}

	printf("%d", Dinic());

	return 0;
}
