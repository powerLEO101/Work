#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_long_long()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 5000000
#define INF 10000000000000000
#define ll long long
int get_long_long()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

class Edge1
{
public:
	int From, To, Value;
	bool Flag;
}Edges1[_];
class Edge
{
public:
	int Next, To, Value;
}Edges[_];
bool operator< (const Edge1& a, const Edge1& b)
{
	return a.Value < b.Value;
}
int E_num, E_num1, Head[_], Deep[_];
void Add_edge(int From, int To, int Value)
{
	Edges1[E_num1++] = (Edge1){From, To, Value, false};
}
void Add_edges(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

int Father[_];
ll MST;
void init() {for (int i = 0; i < _; i++) Father[i] = i;}
int Get_father(int u) {return Father[u] == u ? u : Father[u] = Get_father(Father[u]);}
void Merge(int u, int v) {Father[Get_father(u)] = Get_father(v);}
bool Query(int u, int v) {return Get_father(u) == Get_father(v);}
void Kruskal()
{
	init();
	std::sort(Edges1, Edges1 + E_num1);
	for (int i = 0; i < E_num1; i++) {
		int From = Edges1[i].From, To = Edges1[i].To, Value = Edges1[i].Value;
		if (Query(From, To) == true) continue;
		Merge(From, To);
		Edges1[i].Flag = true;
		MST += Value;
		Add_edges(From, To, Value);
		Add_edges(To, From, Value);
	}
}

int Up[_][21], Max[_][21], Max1[_][21];

void Dfs(int Now = 0)
{
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Up[Now][0]) continue;
		Up[To][0] = Now;
		Deep[To] = Deep[Now] + 1;
		Max[To][0] = Value;
		Max1[To][0] = -0x3f3f3f3f;
		Dfs(To);
	}
}
int Move(int& u, int& v, int Value)
{
	if (Deep[u] == Deep[v]) return -0x3f3f3f3f;
	if (Deep[u] < Deep[v]) std::swap(u, v);
	int Ret = -0x3f3f3f3f;
	for (int i = 20; i >= 0; i--)
		if (Deep[Up[u][i]] >= Deep[v]) {
			if (Max[u][i] != Value) Ret = std::max(Ret, Max[u][i]);
			else Ret = std::max(Ret, Max1[u][i]);
			u = Up[u][i];
		}
	return Ret;
}
int Maxi(int u, int v, int Value)
{
	int Ret = Move(u, v, Value);
	for (int i = 20; i >= 0; i--)
		if (Up[u][i] != Up[v][i]) {
			if (Max[u][i] != Value) Ret = std::max(Ret, Max[u][i]);
			else Ret = std::max(Ret, Max1[u][i]);
			if (Max[v][i] != Value) Ret = std::max(Ret, Max[v][i]);
			else Ret = std::max(Ret, Max1[v][i]);
			u = Up[u][i];
			v = Up[v][i];
		}
	if (u != v) {
		if (Max[u][0] != Value) Ret = std::max(Ret, Max[u][0]);
		else Ret = std::max(Ret, Max1[u][0]);
		if (Max[v][0] != Value) Ret = std::max(Ret, Max[v][0]);
		else Ret = std::max(Ret, Max1[v][0]);
	}
	return Ret;
}

int main()
{
	File(code);
	memset(Head, -1, sizeof(Head));
	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		Add_edge(From, To, Value);
	}
	Kruskal();
	Dfs();
	for (int j = 1; j < 21; j++) 
		for (int i = 0; i < n; i++) {
			Up[i][j] = Up[Up[i][j - 1]][j - 1],
			Max[i][j] = std::max(Max[i][j - 1], Max[Up[i][j - 1]][j - 1]);
			Max1[i][j] = std::max(Max1[i][j - 1], Max1[Up[i][j - 1]][j - 1]);
			if (Max[i][j - 1] < Max[Up[i][j - 1]][j - 1]) Max1[i][j] = std::max(Max1[i][j], Max[i][j - 1]);
			else if (Max[i][j - 1] > Max[Up[i][j - 1]][j - 1]) Max1[i][j] = std::max(Max1[i][j], Max[Up[i][j - 1]][j - 1]);
		}
	long long Ans = INF;
	for (int i = 0; i < m; i++) {
		if (Edges1[i].Flag == true) continue;
		int From = Edges1[i].From, To = Edges1[i].To, Value = Edges1[i].Value;
		Ans = std::min(Ans, MST - Maxi(From, To, Value) + Value);
	}
	printf("%lld", Ans);
	return 0;
}
