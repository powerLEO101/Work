/**************************
  * Writer : Leo101
  * Problem : Luogu P1129 [ZJOI2007]矩阵游戏
  * Tags : 二分图
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 200000
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
bool Hungray(int Now)
{
	if (Now == -1) return true;
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (Vis[To] == true) continue;
		Vis[To] = true;
		if (Hungray(Match[To]) == true) {
			Match[To] = Now;
			return true;
		}
	}
	return false;
}

int main()
{
	File(code);
	int T = gi;
	while (T--) {
		memset(Head, -1, sizeof(Head));
		memset(Match, -1, sizeof(Match));
		E_num = 0;
		int n = gi, Ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (gi == 1) Add_edge(i, j);
		for (int i = 0; i < n; i++) {
			memset(Vis, 0, sizeof(Vis));
			Ans += Hungray(i);
		}
		if (Ans == n) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
