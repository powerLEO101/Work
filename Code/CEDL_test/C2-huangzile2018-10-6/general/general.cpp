/***************************
  * Writer : Leo101
  * Problem : Test10-6 T2 general
  * Tags : 图论
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 2000000
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
int Head[_], E_num, n, k, t;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

int Deep[_], Father[_];
bool Vis[_];
void Dfs(int Now, int Pre)
{
	Father[Now] = Pre;
	for_edge (i, Now) {
		int To = Edges[i].To;
		if (To == Pre || Vis[To] == true) continue;
		Deep[To] = Deep[Now] + 1;
		Dfs(To, Now);
	}
}

class Node
{
public:
	int Id, Value;
}Nodes[_];
bool operator< (const Node& a, const Node& b)
{
	return a.Value > b.Value;
}

int f[_];
void Dfs1(int Now)
{
	if (f[Now] == 0) return ;
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (f[Now] - 1 <= f[To]) continue;
		f[To] = f[Now] - 1;
		Dfs1(To);
	}
}
void Work(int Now)
{
	for (int i = 0; i < k; i++) Now = Father[Now];
	f[Now] = k;
	Dfs1(Now);
}

int main()
{
	File(general);
	
	memset(f, -1, sizeof(f));
	memset(Head, -1, sizeof(Head));

	n = gi, k = gi, t = gi;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To);
		Add_edge(To, From);
	}
	
	Dfs(0, 0);
	for (int i = 0; i < n; i++) Nodes[i].Id = i, Nodes[i].Value = Deep[i];
	std::sort(Nodes, Nodes + n);

	int Ans = 0;
	for (int i = 0; i < n; i++) {
		int Now = Nodes[i].Id;
		if (f[Now] != -1) continue;
		Work(Now);
		Ans++;
	}

	printf("%d", Ans);

	return 0;
}
