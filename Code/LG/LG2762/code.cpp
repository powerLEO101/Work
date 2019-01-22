/**************************
  * Writer : Leo101
  * Problem : Luogu P2762 太空飞行计划问题
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
#define Max_n 1001
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
}Edges[Max_n << 2];
int Head[Max_n << 1], E_num;
char tools[10000];
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

int Depth[Max_n << 1];
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
int Dfs(int Now, int Min = INF)
{
	if (Now == T) return Min;
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (Value <= 0 || Depth[To] != Depth[Now] + 1) continue;
		int Temp = Dfs(To, std::min(Min, Value));
		if (Temp != 0) {
			Edges[i].Value -= Temp;
			Edges[i ^ 1].Value += Temp;
			return Temp;
		}
	}
	return 0;
}
int Min_Cut()
{
	Bfs();
	int Answer = 0;
	while (Depth[T] != -1) {
		int Val = Dfs(S);
		while (Val != 0) {
			Answer += Val;
			Val = Dfs(S);
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
	S = n + m + 1, T = n + m + 2;
	for (int i = 0; i < n; i++) {
		int Value = gi;
		Sum += Value;
		Add_edge(S, i, Value); Add_edge(i, S, 0);
		memset(tools, 0, sizeof(tools));
		std::cin.getline(tools, 10000);
		int ulen = 0, tool;
		while (sscanf(tools + ulen, "%d", &tool) == 1) {
			Add_edge(i, tool + n, INF); Add_edge(tool + n, i, 0);
			if (tool == 0) 
				ulen++;
			else {
				while (tool) {
					tool /= 10;
					ulen++;
				}
			}
			ulen++;
		}
	}
	for (int i = 1; i <= m; i++) {
		int Value = gi;
		Add_edge(i + n, T, Value); Add_edge(T, i + n, 0);
	}

	int Cut = Min_Cut();
	for (int i = 0; i < n; i++)
		if (Depth[i] != -1) printf("%d ", i + 1);
	printf("\n");
	for (int i = n + 1; i <= n + m; i++)
		if (Depth[i] != -1) printf("%d ", i - n);
	printf("\n%d", Sum - Cut);

	return 0;
}
