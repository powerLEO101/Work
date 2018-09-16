#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
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
	int Next, To, Value;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value) {
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

int Tot, Dfn[_], Rnk[_], Deep[_], Up[_][21];
long long Dis[_];
void Dfs(int Now = 0)
{
	Dfn[Now] = Tot++;
	Rnk[Tot - 1] = Now;
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Up[Now][0]) continue;
		Up[To][0] = Now;
		Deep[To] = Deep[Now] + 1;
		Dis[To] = Dis[Now] + Value;
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
long long Dist(int u, int v)
{
	if (u == v) return 0;
	return Dis[u] + Dis[v] - (Dis[LCA(u, v)] * 2);
}

std::set<int> Set;

std::set<int>::iterator Left(std::set<int>::iterator it)
{
	if (it == Set.begin()) return --Set.end();
	return --it;
}
std::set<int>::iterator Right(std::set<int>::iterator it)
{
	if (it == --Set.end()) return Set.begin();
	return ++it;
}

int main()
{
	File(code);
	memset(Head, -1, sizeof(Head));
	int n = gi;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		Add_edge(From, To, Value);
		Add_edge(To, From, Value);
	}
	Dfs(0);
	for (int j = 1; j < 21; j++)
		for (int i = 0; i < n; i++)
			Up[i][j] = Up[Up[i][j - 1]][j - 1];
	int m = gi;
	long long Ans = 0;
	std::set<int>::iterator it;
	while (m--) {
		char op = getchar();
		while (op != '?' && op != '+' && op != '-') op = getchar();
		if (op == '?') {
			printf("%lld\n", Ans / 2);
			continue; 
		}
		int x = gi - 1;
		if (op == '+') {
			if (Set.size() != 0) {
				it = Set.lower_bound(Dfn[x]);
				if (it == Set.end()) it = Set.begin();
				Ans += Dist(Rnk[*it], x) + Dist(Rnk[*Left(it)], x) - Dist(Rnk[*it], Rnk[*Left(it)]);
			}
			Set.insert(Dfn[x]);
		} else {
			it = Set.find(Dfn[x]);
			Ans -= Dist(x, Rnk[*Left(it)]) + Dist(x, Rnk[*Right(it)]) - Dist(Rnk[*Left(it)], Rnk[*Right(it)]);
			Set.erase(Dfn[x]);
		}
	}
	return 0;
}
