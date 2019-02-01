/**************************
  * Writer : Leo101
  * Problem : Luogu P4197 Peaks
  * Tags : 主席树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
const int Max_N = 2e5 + 207, Max_M = 1e6 + 207;
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

class E
{
public:
	int From, To, Value;
} edges[Max_M];
bool operator< (const E& a, const E& b)
{
	return a.Value < b.Value;
}
int e_num;
void New_edge(int From, int To, int Value)
{
	edges[e_num++] = (E) {From, To, Value};
}

class Edge
{
public:
	int Next, To;
} Edges[Max_M];
int Head[Max_M], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge) {Head[From], To};
	Head[From] = E_num++;
}

bool Vis[Max_N];
int Father[Max_N], Up[Max_N][21];
void Init_Father() {for (int i = 0; i < Max_N; i++) Father[i] = i;}
int Get_father(int u) {return Father[u] == u ? u : Father[u] = Get_father(Father[u]);}
int Cnt, Val[Max_N];
void Ex_Kruskal(int m = e_num)
{
	Init_Father();
	std::sort(edges, edges + m);
	for (int i = 0 ; i < m; i++) {
		int From = edges[i].From, To = edges[i].To, Value = edges[i].Value;
		From = Get_father(From); To = Get_father(To);
		if (From == To) continue;
		Father[From] = Father[To] = Cnt;
		Add_edge(Cnt, From); Add_edge(From, Cnt);
		Add_edge(Cnt, To); Add_edge(To, Cnt);
		Vis[From] = Vis[To] = true;
		Val[Cnt++] = Value;
	}
}

int Sum[Max_N], St[Max_N], Ed[Max_N], Count = -1, Pos[Max_N];
void Dfs(int Now)
{
	Pos[++Count] = Now; Vis[Now] = true;

	St[Now] = Count;
	for_edge (i, Now) {
		int To = Edges[i].To;
		if (To == Up[Now][0]) continue;
		Up[To][0] = Now;
		Dfs(To);
		Sum[Now] += Sum[To];
	}
	Ed[Now] = Count;

	if (Sum[Now] == 0) Sum[Now] = 1;
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
int Get(Node* Root) {return Root == NULL ? 0 : Root -> Val;}
Node* Modify(Node* Root, int l, int r, int Index)
{
	Node* New = new Node;
	if (l == r - 1) {
		New -> Val = Get(Root) + 1;
		return New;
	}

	int Mid = (l + r) / 2;
	if (Root != NULL) {
		New -> l_son = Root -> l_son;
		New -> r_son = Root -> r_son;
		if (Index < Mid) New -> l_son = Modify(New -> l_son, l, Mid, Index);
		else New -> r_son = Modify(New -> r_son, Mid, r, Index);
		New -> Val = Get(New -> l_son) + Get(New -> r_son);
	} else {
		if (Index < Mid) New -> l_son = Modify(NULL, l, Mid, Index);
		else New -> r_son = Modify(NULL, Mid, r, Index);
		New -> Val = Get(New -> l_son) + Get(New -> r_son);
	}
	
	return New;
}
int Get1(Node* Root) {
	if (Root == NULL) return 0;
	if (Root -> r_son == NULL) return 0;
	return Root -> r_son -> Val;
}
Node* L_SON(Node* Root)
{
	return Root == NULL ? NULL : Root -> l_son;
}
Node* R_SON(Node* Root)
{
	return Root == NULL ? NULL : Root -> r_son;
}
int Query_Kth(Node* Root1, Node* Root2, int l, int r, int k)
{
	if (l == r - 1) return l;

	int x = Get1(Root2) - Get1(Root1);
	int Mid = (l + r) / 2;
	if (k >= x) return Query_Kth(L_SON(Root1), L_SON(Root2), l, Mid, k - x);
	else return Query_Kth(R_SON(Root1), R_SON(Root2), Mid, r, k);
}


class Data
{
public:
	int Index, Val;
} Temp[Max_N];
bool operator< (const Data& a, const Data& b)
{
	return a.Val < b.Val;
}

int Query(int v, int x, int k)
{
	/*Redouble*/
	for (int i = 20; i >= 0; i--) {
		if (Val[Up[v][i]] > x) continue;
		v = Up[v][i];
	}

	if (Sum[v] < k) return -1;
	if (St[v] == 0) return Temp[Query_Kth(Root[Cnt], Root[Ed[v]], 0, 1e6 + 10, k - 1)].Val;
	else return Temp[Query_Kth(Root[St[v] - 1], Root[Ed[v]], 0, 1e6 + 10, k - 1)].Val;
}

int Num[Max_N];
int main()
{
	File(code);

	/*Init*/
	memset(Head, -1, sizeof(Head));

	/*Input & Build_Graph*/
	int n = gi, m = gi, Q = gi;
	for (int i = 0; i < n; i++) {
		Temp[i].Index = i;
		Temp[i].Val = gi;
	}
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		New_edge(From, To, Value);
	}

	/*Data_Prepare*/
	std::sort(Temp, Temp + n);
	for (int i = 0; i < n; i++)
		Num[Temp[i].Index] = i;

	/*Ex_Kruskal*/
	Cnt = n;
	Ex_Kruskal();

	/*Redouble & Preare*/
	for (int i = 0; i < Cnt; i++) {
		if (Vis[i] == true) continue;
		Up[i][0] = i;
		Dfs(i);
	}
	for (int j = 1; j < 21; j++)
		for (int i = 0; i < Cnt; i++)
			Up[i][j] = Up[Up[i][j - 1]][j - 1];

	/*Build_Tree*/
	for (int i = 0; i < Cnt; i++) {
		if (i != 0) Root[i] = Root[i - 1];
		if (Pos[i] < n)  Root[i] = Modify(Root[i], 0, 1e6 + 10, Num[Pos[i]]);
	}

	/*Input & Get_ans*/
	for (int i = 0; i < Q; i++) {
		int v = gi - 1, x = gi, k = gi;
		printf("%d\n", Query(v, x, k));
	}
	
	return 0;
}
