/**************************
  * Writer : Leo101
  * Problem : Luogu P3384 【模板】树链剖分
  * Tags : 树链剖分
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 3e5;
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

int Weight[Max_N], Wt[Max_N], Son[Max_N], Size[Max_N],\
    Father[Max_N], Depth[Max_N], Top[Max_N], Dfn[Max_N];
int n, m, R, Mod;

class Node
{
public:
	int Val, Tag;
	Node* l_son,* r_son;
Node() {
	Val = Tag = 0;
	l_son = r_son = NULL;
}
}* Seg_Tree = NULL;
void Push_down(Node* Root, int l, int r)
{
	int Mid = (l + r) / 2;
	Root -> l_son -> Val += Root -> Tag * (Mid - l);
	Root -> r_son -> Val += Root -> Tag * (r - Mid);
	Root -> l_son -> Tag += Root -> Tag;
	Root -> r_son -> Tag += Root -> Tag;
	Root -> Tag = 0;
}
void Build(int l, int r, Node* &Root = Seg_Tree)
{
	if (Root == NULL) Root = new Node;
	if (l == r - 1) {
		Root -> Val = Weight[l];
		return ;
	}
	int Mid = (l + r) / 2;
	Build(l, Mid, Root -> l_son);
	Build(Mid, r, Root -> r_son);
	
	Root -> Val = Root -> l_son -> Val +\
		      Root -> r_son -> Val;
	Root -> Val %= Mod;
}
void Modify(int l, int r, int Ml, int Mr, int Val, Node* Root = Seg_Tree) // [)
{
	if (r <= Ml || Mr <= l) return ;
	if (Ml <= l && r <= Mr) {
		Root -> Val += Val * (r - l);
		Root -> Tag += Val;
		return ;
	}

	int Mid = (l + r) / 2;
	Push_down(Root, l, r);
	Modify(l, Mid, Ml, Mr, Val, Root -> l_son);
	Modify(Mid, r, Ml, Mr, Val, Root -> r_son);
	Root -> Val = Root -> l_son -> Val +\
		      Root -> r_son -> Val;
}
int Query(int l, int r, int Ml, int Mr, Node* Root = Seg_Tree)
{
	if (r <= Ml || Mr <= l) return 0;
	if (Ml <= l && r <= Mr) return Root -> Val;

	int Mid = (l + r) / 2;
	Push_down(Root, l, r);
	return Query(l, Mid, Ml, Mr, Root -> l_son) +\
	       Query(Mid, r, Ml, Mr, Root -> r_son);
}

class Edge
{
public:
	int Next, To;
} Edges[Max_N];
int Head[Max_N], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge) {Head[From], To};
	Head[From] = E_num++;
}

void Dfs1(int Now, int Pre = -1)
{
	Size[Now] = 1;
	for (int i = Head[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Father[To] = Now;
		Depth[To] = Depth[Now] + 1;
		Dfs1(To, Now);
		Size[Now] += Size[To];
		if (Size[To] > Son[Now] == -1 ? 0 : Size[Son[Now]]) Son[Now] = To;
	}
}
int Tot;
void Dfs2(int Now, int Pre)
{
	Top[Now] = Pre;
	Dfn[Now] = Tot++;
	Weight[Dfn[Now]] = Wt[Now];
	if (Son[Now] == -1) return ;
	Dfs2(Son[Now], Pre);
	for (int i = Head[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To;
		if (To == Father[Now] || To == Son[Now]) continue;
		Dfs2(To, To);
	}
}

void Range_Add(int x, int y, int v)
{
	while (Top[x] != Top[y]) {
		if (Depth[Top[x]] < Depth[Top[y]]) std :: swap(x, y);
		Modify(0, n, Dfn[Top[x]], Dfn[x] + 1, v);
		x = Father[Top[x]];
	}
	if (Depth[x] < Depth[y]) std :: swap(x, y);
	Modify(0, n, Dfn[y], Dfn[x] + 1, v);
}
void Range_Query(int x, int y)
{
	int Ans = 0;
	while (Top[x] != Top[y]) {
		if (Depth[Top[x]] < Depth[Top[y]]) std :: swap(x, y);
		Ans = (Ans + Query(0, n, Dfn[Top[x]], Dfn[x] + 1)) % Mod;
		x = Father[Top[x]];
	}
	if (Depth[x] < Depth[y]) std :: swap(x, y);
	Ans = (Ans + Query(0, n, Dfn[y], Dfn[x] + 1)) % Mod;
	printf("%d\n", Ans);
}
void Range_Add(int x, int v)
{ Modify(0, n, Dfn[x], Dfn[x] + Size[x], v); }
void Range_Query(int x)
{ printf("%d\n", Query(0, n, Dfn[x], Dfn[x] + Size[x])); }

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));
	memset(Son, -1, sizeof(Son));

	n = gi, m = gi, R = gi - 1, Mod = gi;
	for (int i = 0; i < n; i++) Wt[i] = gi;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To);
		Add_edge(To, From);
	}

	Dfs1(R); Dfs2(R, R);
	Build(0, n);

	for (int i = 0; i < m; i++) {
		int Opt = gi;
		if (Opt == 1) {
			int l = gi - 1, r = gi - 1, v = gi;
			Range_Add(l, r, v);
		} else if (Opt == 2) {
			int l = gi - 1, r = gi - 1;
			Range_Query(l, r);
		} else if (Opt == 3) {
			int N = gi, v = gi;
			Range_Add(N, v);
		} else {
			int N = gi;
			Range_Query(N);
		}
	}

	return 0;
}
