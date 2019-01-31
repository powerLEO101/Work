/**************************
  * Writer : Leo101
  * Problem : Luogu P2770 航空路线问题
  * Tags : 网络流
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>
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

std::map<std::string, int> Map;
std::map<int, std::string> ReMap;

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

int S, T;

int Dist[Max_N], Cur[Max_N];
bool Vis[Max_N];
bool Bfs()
{
	memset(Dist, -0x3f, sizeof(Dist));
	memcpy(Cur, Head, sizeof(Head));
	memset(Vis, 0, sizeof(Vis));

	std::queue<int> Q;
	Q.push(S); Dist[S] = 0;
	
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value, Cost = Edges[i].Cost;
			if (Value <= 0 || Dist[To] >= Dist[Now] + Cost) continue;
			Dist[To] = Dist[Now] + Cost;
			if (Vis[To] == false) {
				Q.push(To);
				Vis[To] = true;
			}
		}
		Vis[Now] = false;
	}

	return Dist[T] != Dist[T + 1];
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
		int Val = Dfs(To, std::min(Value, Min));
		if (Val != 0) {
			Answer += Val * Cost;
			Edges[i].Value -= Val;
			Edges[i ^ 1].Value += Val;
			return Val;
		}
	}
	return 0;
}
int Dinic()
{
	int Ret;
	while (Bfs() == true) {
		memset(Vis, 0, sizeof(Vis));
		int Val = Dfs(S, INF);
		while (Val != 0) {
			Ret += Val;
			memset(Vis, 0, sizeof(Vis));
			Val = Dfs(S, INF);
		}
	}
	return Ret;
}

int n, m, Num;
std::string Ans[Max_N];
void Dfs1(int Now = 0)
{
	if (Now == T || Vis[Now] == true) return ;
	if (Now != S && Now != T && Now != 0 && Now != 1 && Now != (n - 1) * 2 && Now != (n - 1) * 2 + 1) Vis[Now] = true;
	if (Now != S && Now != T && Now % 2 == 0) Ans[Num++] = ReMap[Now / 2];
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (Value <= 0 && To != S && To != T && Vis[To] == false) {
			Dfs1(To);
			return ;
		}
	}
}

int main()
{
	File(code);

	/*Prepare*/
	memset(Head, -1, sizeof(Head));

	/*Input & Add_edge*/
	n = gi, m = gi;
	S = 2 * n + 1, T = 2 * n + 2;
	for (int i = 0; i < n; i++) {
		std::string Str;
		std::cin >> Str;
		Map[Str] = i;
		ReMap[i] = Str;
	}
	for (int i = 0; i < m; i++) {
		std::string From, To;
		std::cin >> From >> To;
		if (Map[From] > Map[To]) std::swap(From, To);
		Add_edge(Map[From] * 2 + 1, Map[To] * 2, 1, 0);
		Add_edge(Map[To] * 2, Map[From] * 2 + 1, 0, 0);
	}
	for (int i = 1; i < n - 1; i++) {
		Add_edge(i * 2, i * 2 + 1, 1, 1);
		Add_edge(i * 2 + 1, i * 2, 0, -1);
	}
	Add_edge(0, 1, 2, 1); Add_edge(1, 0, 0, -1);
	Add_edge((n - 1) * 2, (n - 1) * 2 + 1, 2, 1); 
	Add_edge((n - 1) * 2 + 1, (n - 1) * 2, 0, -1);
	Add_edge(S, 0, INF, 0); Add_edge(0, S, 0, 0);
	Add_edge((n - 1) * 2 + 1, T, INF, 0); Add_edge(T, (n - 1) * 2 + 1, 0, 0);

	/*Output & Get_ans*/
	int Val = Dinic();
	if (Answer != 2) printf("%d\n", Answer - 2);
	else if (Answer >= 0) {
		printf("%d\n", Answer);
		std::cout << ReMap[0] << std::endl << ReMap[n - 1] << std::endl << ReMap[0];
		return 0;
	} else {
		printf("No Solution!");
		return 0;
	}
	memset(Vis, 0, sizeof(Vis));
	Dfs1();
	for (int i = 0; i < Num; i++) std::cout << Ans[i] << std::endl;
	Num = 0;
	Dfs1();
	for (int i = Num - 2; i >= 0; i--) std::cout << Ans[i] << std::endl;

	return 0;
}
