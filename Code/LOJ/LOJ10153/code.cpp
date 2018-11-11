/**************************
  * Writer : Leo101
  * Problem : LOJ #10153. 「一本通 5.2 例 1」二叉苹果树
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 210
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

class Edge
{
public:
	int Next, To, Value;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

int f[_][_], n, Q;
int l_son[_], r_son[_], Val[_];
int Dp(int i, int j)
{
	if (j == 0) return 0;
	if (f[i][j] != -1) return f[i][j];
	if (l_son[i] == -1) return Val[i];
	for (int k = 0; k < j; k++)
		f[i][j] = std::max(f[i][j], Dp(l_son[i], k) + Dp(r_son[i], j - k - 1));
	f[i][j] += Val[i];
	return f[i][j];
}

void Build(int Now = 0, int Pre = -1)
{
	int i;
	for (i = Head[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Pre) continue;
		Build(To, Now);
		l_son[Now] = To; Val[To] = Value;
		break;
	}

	for (; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Pre) continue;
		Build(To, Now);
		r_son[Now] = To, Val[To] = Value;
	}
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));
	memset(f, -1, sizeof(f));
	memset(l_son, -1, sizeof(l_son));
	memset(r_son, -1, sizeof(r_son));

	n = gi, Q = gi;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		Add_edge(From, To, Value);
		Add_edge(To, From, Value);
	}

	Build();

	printf("%d", Dp(0, Q + 1));

	return 0;
}
