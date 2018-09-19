#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 1000000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

class Edge
{
public:
	int Next, To;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

int Up[_][21], Deep[_];
void Dfs(int Now = 0)
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Up[Now][0]) continue;
		Up[To][0] = Now;
		Deep[To] = Deep[Now] + 1;
		Dfs(To);
	}
}

void Move(int& u, int& v)
{
	if (Deep[u] == Deep[v]) return;
	if (Deep[u] < Deep[v]) std::swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (Deep[Up[u][i]] >= Deep[v])
			u = Up[u][i];
}
int LCA(int u, int v)
{
	Move(u, v);
	for (int i = 20; i >= 0; i--)
		if (Up[u][i] != Up[v][i])
			u = Up[u][i],
			v = Up[v][i];
	return u == v ? u : Up[u][0];
}

int Calc(int x, int y, int z, int a, int b, int c)
{
	return (Deep[x] + Deep[y] + Deep[z]) - Deep[a] - Deep[b] - Deep[c];
}

int main()
{
	File(code);
	memset(Head, -1, sizeof(Head));
	int n = gi, m = gi;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To);
		Add_edge(To, From);
	}
	Dfs();
	for (int j = 1; j < 21; j++)
		for (int i = 0; i < n; i++)
			Up[i][j] = Up[Up[i][j - 1]][j - 1];
	for (int i = 0; i < m; i++) {
		int x = gi - 1, y = gi - 1, z = gi - 1;
		int a = LCA(x, y), b = LCA(x, z), c = LCA(y, z);
		if (a == b) printf("%d %d\n", c + 1, Calc(x, y, z, c, a, b));
		else if (b == c) printf("%d %d\n", a + 1, Calc(x, y, z, a, b, c));
		else if (a == c) printf("%d %d\n", b + 1, Calc(x, y, z, b, a, c));
	}
	return 0;
}
