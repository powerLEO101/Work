/**************************
  * Writer : Leo101
  * Problem : Luogu P2633 Count on a tree
  * Tags : 主席树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define Mid ((l + r) / 2)
const int Max_N = 100001, Max_M = 300000;
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

int n, m;

class Data
{
public:
	int Index, Val;
} Temp[Max_N];
bool operator< (const Data& a, const Data& b)
{ return a.Val < b.Val; }

int Num[Max_N];

class Edge
{
public:
	int Next, To;
}Edges[Max_M];
int Head[Max_N], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge) {Head[From], To};
	Head[From] = E_num++;
}

class Node
{
public:
	int Val;
	Node* l_son,* r_son;
Node() {
	Val = 0;
	l_son = r_son = NULL;
}
}* Root[Max_N];
int Get(Node* Root) { return Root == NULL ? 0 : Root -> Val; }
Node* l_son(Node* Root) { return Root == NULL ? NULL : Root -> l_son; }
Node* r_son(Node* Root) { return Root == NULL ? NULL : Root -> r_son; }
Node* Modify(Node* Root, int Index, int l = 0, int r = n)
{
	/*Judge*/
	Node* New = new Node;
	if (l == r - 1) {
		New -> Val = Get(Root) + 1;
		return New;
	}

	/*Build_Next*/
	New -> l_son = l_son(Root);
	New -> r_son = r_son(Root);
	if (Index < Mid) New -> l_son = Modify(New -> l_son, Index, l, Mid);
	else New -> r_son = Modify(New -> r_son, Index, Mid, r);
	New -> Val = Get(New -> l_son) + Get(New -> r_son);

	/*Return New Node*/
	return New;
}
int Query(Node* u, Node* v, Node* Lca, Node* Fa, int k, int l = 0, int r = n)
{
	/*Judge*/
	if (l == r - 1) return l;

	int x = Get(l_son(u)) + Get(l_son(v)) - Get(l_son(Lca)) - Get(l_son(Fa));
	if (k < x) return Query(l_son(u), l_son(v), l_son(Lca), l_son(Fa), k, l, Mid);
	else return Query(r_son(u), r_son(v), r_son(Lca), r_son(Fa), k - x, Mid, r);
}

int Up[Max_N][21], Deep[Max_N];
void Dfs(int Now)
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Up[Now][0]) continue;
		Up[To][0] = Now;
		Deep[To] = Deep[Now] + 1;
		Root[To] = Modify(Root[Now], Num[To]);
		Dfs(To);
	}
}
void Move(int& u, int& v)
{
	if (Deep[u] < Deep[v]) std::swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (Deep[Up[u][i]] >= Deep[v]) u = Up[u][i];
}
int LCA(int u, int v)
{
	Move(u, v);
	for (int i = 20; i >= 0; i--) {
		if (Up[u][i] == Up[v][i]) continue;
		u = Up[u][i]; v = Up[v][i];
	}
	return u == v ? u : Up[u][0];
}

int main()
{
	File(code);

	/*Init*/
	memset(Head, -1, sizeof(Head));

	/*Input & Prepare*/
	n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		Temp[i].Index = i;
		Temp[i].Val = gi;
	}

	/*Discretization*/
	std::sort(Temp, Temp + n);
	for (int i = 0; i < n; i++) {
		Num[Temp[i].Index] = i;
	}

	/*Input & Build_Tree*/
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To); Add_edge(To, From);
	}

	/*Redouble_Prepare & Build_Chairman_Tree*/
	Up[0][0] = Up[n][0] = n;
	Deep[0] = 1;
	Root[0] = Modify(NULL, Num[0]);
	Dfs(0);
	for (int j = 1; j < 21; j++)
		for (int i = 0; i <= n; i++)
			Up[i][j] = Up[Up[i][j - 1]][j - 1];

	/*Input & Get_ans*/
	int LastAns = 0;
	for (int i = 0; i < m; i++) {
		int u = (gi ^ LastAns) - 1, v = gi - 1, k = gi - 1;
		int Lca = LCA(u, v);
		printf("%d\n", LastAns = Temp[Query(Root[u], Root[v], Root[Lca], Root[Up[Lca][0]], k)].Val);
	}

	return 0;
}
