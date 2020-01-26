/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
const int MAXN = 2e5;
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define for_edge(i, x) for (int i = head[x]; i != -1; i = Edges[i].next)
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}
int N_num, Node[MAXN], num[MAXN];
int Father[MAXN * 2];
int Get_father(int u) 
{ return Father[u] == u ? u : Father[u] = Get_father(Father[u]); }
class edge
{
public:
	int From, To, Value;
} edges[MAXN];
int e_num;
void addEdge(int From, int To, int Value)
{
	edges[e_num++] = (edge) {From, To, Value};
}

int operator< (const edge& a, const edge& b)
{
	return a.Value > b.Value;
}

class Edge
{
public:
    int next, to;
} Edges[MAXN];
int eNum, head[MAXN];
void Add_edge(int from, int to)
{
	Edges[eNum] = (Edge) {head[from], to};
	head[from] = eNum++;
}

void Ex_Kruskal(int n)
{
	std :: sort(edges, edges + e_num);
	for (int i = 0; i < MAXN; i++) Father[i] = i;

	for (int i = 0; i < e_num; i++) {
		int From = edges[i].From, To = edges[i].To, Value = edges[i].Value;
		int Fa_F = Get_father(From), Fa_T = Get_father(To);
		if (Fa_F == Fa_T) continue;
		Father[Fa_T] = N_num; Father[Fa_F] = N_num;
		Add_edge(N_num, Fa_F);
		Add_edge(N_num, Fa_T);
		Node[N_num++] = Value;
	}
}

int Up[MAXN * 2][21], Depth[MAXN * 2];
bool Vis[MAXN * 2];
void Dfs(int Now, int Pre = -1)
{
	Vis[Now] = true;
	for_edge(i, Now) {
		int To = Edges[i].to;
		if (Vis[To] == true) continue;
		Up[To][0] = Now;
		Depth[To] = Depth[Now] + 1;
		Dfs(To, Now);
	}
}
void Move(int& u, int& v)
{
	if (Depth[u] < Depth[v]) std :: swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (Depth[Up[u][i]] >= Depth[v])
			u = Up[u][i];
}
int LCA(int u, int v)
{
	Move(u, v);
	for (int i = 20; i >= 0; i--) 
		if (Up[u][i] != Up[v][i])
			u = Up[u][i], v = Up[v][i];
	if (Up[u][0] != Up[v][0]) return 0;
	return u == v ? u : Up[u][0];
}

int main()
{
	_FILE(wormsort);
	
	memset(head, -1, sizeof(head));

	int n = gi, m = gi;
	N_num = n + 10;
	for (int i = 0; i < n; i++) num[i] = gi - 1;
	for (int i = 0; i < m; i++) {
		int from = gi, to = gi, value = gi;
		addEdge(from, to, value);
		addEdge(to, from, value);
	}
	
	for (int j = 1; j < 21; j++) 
		for (int i = 0; i < N_num; i++) 
			Up[i][j] = Up[Up[i][j - 1]][j - 1];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = std :: max(ans, Node[LCA(num[i], i)]);
	}

	std :: cout << ans;

	return 0;
}


