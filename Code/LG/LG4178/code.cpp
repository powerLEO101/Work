/*************************
  * Writer : Leo101
  * Problem : LG P4178 Tree
  * Tags : 点分治
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 4e5;
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
} Edges[Max_N];
int Head[Max_N], E_num, k;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

int Ans, Next_Rt, Size, Cnt, Global_Min;
int Sz[Max_N], Dis[Max_N];
bool Vis[Max_N];
void Get_Focus(int Now, int Pre = -1)
{
	int Max_Val = 0; Sz[Now] = 1;
	for (int i = Head[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To;
		if (To == Pre || Vis[To] == true) continue;
		Get_Focus(To, Now);
		Sz[Now] += Sz[To];
		Max_Val = std :: max(Max_Val, Sz[To]);
	}

	Max_Val = std :: max(Max_Val, Size - Sz[Now]);
	if (Max_Val < Global_Min) {
		Global_Min = Max_Val;
		Next_Rt = Now;
	}
}
void Dfs(int Now, int Extra, int Pre = -1, int Dist = 0)
{
	Dis[Cnt++] = Dist + Extra;
	for (int i = Head[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Pre || Vis[To] == true) continue;
		Dfs(To, Extra, Now, Dist + Value);
	}
}
int Get_ans(int Now, int Extra)
{
	Cnt = 0; Dfs(Now, Extra);
	std :: sort(Dis, Dis + Cnt);

	int Ret = 0, l = 0, r = Cnt - 1;
	while (l < r) {
		if (Dis[l] + Dis[r] <= k) Ret += r - l, l++;
		else r--;
	}

	return Ret;
}
void Divide(int Now)
{
	Ans += Get_ans(Now, 0);
	Vis[Now] = true;
	int Size_Backup = Size;
	for (int i = Head[Now]; i != -1; i = Edges[i].Next) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (Vis[To] == true) continue;
		Next_Rt = -1, Size = Sz[To] > Sz[Now] ? Size_Backup - Sz[Now] : Sz[To];
		Global_Min = 0x3f3f3f3f;
		Get_Focus(To);
		Ans -= Get_ans(To, Value);
		Divide(Next_Rt);
	}
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 1; i < n; i++) {
		int From = gi, To = gi, Value = gi;
		Add_edge(From, To, Value); Add_edge(To, From, Value);
	}
	k = gi;

	Next_Rt = -1, Global_Min = 0x3f3f3f3f;
	Size = n;
	Get_Focus(1);
	Divide(Next_Rt);
	
	printf("%d", Ans);

	return 0;
}
