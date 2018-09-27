/**************************
  * Writer : Leo101
  * Problem : BZOJ 4883 [Lydsy1705月赛]棋盘上的守卫
  * Tags : 最小生成树, 二分图
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 500000
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
	int From, To, Value;
}Edges[_];
bool operator< (const Edge& a, const Edge& b)
{
	return a.Value < b.Value;
}
int E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num++] = (Edge){From, To, Value};
}

int Father[_], Cir[_];
void init() {for (int i = 0; i < _; i++) Father[i] = i;}
int Get_father(int u) {return Father[u] == u ? u : Father[u] = Get_father(Father[u]);}

int main()
{
	File(code);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			Add_edge(i, j + n, gi);

	init();
	long long Ans = 0;
	std::sort(Edges, Edges + E_num);
	for (int i = 0; i < E_num; i++) {
		int From = Get_father(Edges[i].From), To = Get_father(Edges[i].To), Value = Edges[i].Value;
		if (From == To && Cir[From] == false) Cir[From] = true, Ans += Value;
		else if (!Cir[From] || !Cir[To]) Cir[To] |= Cir[From], Father[From] = To, Ans += Value;
	}

	std::cout << Ans;

	return 0;
}
