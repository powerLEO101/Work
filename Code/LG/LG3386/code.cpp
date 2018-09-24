/**************************
  * Writer : Leo101
  * Problem : Luogu P3386 【模板】二分图匹配
  * Tags : 匈牙利, 二分图最大匹配
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 1000001
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

int Match[_];
bool Vis[_];

bool Hungary(int Now)
{
	if (Now == -1) return true;
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (Vis[To] == true) continue;
		Vis[To] = true;
		if (Hungary(Match[To]) == true) {
			Match[To] = Now;
			return true;
		}
	}
	return false;
}

int main()
{
	File(code);

	memset(Match, -1, sizeof(Match));
	memset(Head, -1, sizeof(Head));

	int n = gi, m = gi, e = gi;

	for (int i = 0; i < e; i++) {
		int From = gi - 1, To = gi - 1;
		if (From >= n || To >= m) continue;
		Add_edge(From, To);
	}

	int Ans = 0;

	for (int i = 0; i < n; i++) {
		memset(Vis, 0, sizeof(Vis));
		if (Hungary(i) == true) Ans++;
	}

	printf("%d", Ans);

	return 0;
}
