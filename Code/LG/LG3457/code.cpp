/**************************
  * Writer : Leo101
  * Problem : Luogu P3457 [POI2007]POW-The Flood
  * Tags : 并查集，贪心
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 1001;
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

class Node
{
public:
	int x, y, Val;
} Nodes[Max_N * Max_N];
bool operator< (const Node& a, const Node& b)
{ return a.Val < b.Val; }

int N_num, n, m, Ans;
int Num[Max_N][Max_N], Gox[4] = {0, 0, 1, -1}, Goy[4] = {1, -1, 0, 0};

int Father[Max_N * Max_N], Vis[Max_N * Max_N];
void Init() { for (int i = 0; i < Max_N * Max_N; i++) Father[i] = i; }
int Get_father(int u) { return Father[u] == u ? u : Father[u] = Get_father(Father[u]); }
int Hash(int x, int y) { return x * m + y; }
int ABS(int u) {return u < 0 ? -u : u; }

int main()
{
	File(code);

	/*Input*/
	n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			Num[i][j] = gi;
			Nodes[N_num++] = (Node) {i, j, ABS(Num[i][j])};
		}
	}

	/*Prepare*/
	std::sort(Nodes, Nodes + N_num);
	Init();

	/*Get_ans*/
	for (int i = 0; i < N_num; i++) {
		int x = Nodes[i].x, y = Nodes[i].y, Val = Nodes[i].Val;
		for (int j = 0; j < 4; j++) {
			int Tmpx = x + Gox[j], Tmpy = y + Goy[j];
			if (Tmpx < 0 || Tmpy < 0 || Tmpx >= n || Tmpy >= m) continue;
			if (ABS(Num[Tmpx][Tmpy]) <= Val) {
				int Fx = Get_father(Hash(x, y));
				int Fy = Get_father(Hash(Tmpx, Tmpy));
				Vis[Fy] |= Vis[Fx];
				Father[Fx] = Fy;
			}
		}

		if (Val == Nodes[i + 1].Val) continue;
		for (int j = i; Nodes[j].Val == Val; j--) {
			if (Num[Nodes[j].x][Nodes[j].y] < 0) continue;
			int Fa = Get_father(Hash(Nodes[j].x, Nodes[j].y));
			if (Vis[Fa] == false) {
				Vis[Fa] = true;
				Ans++;
			}
		}
	}

	/*Output*/
	printf("%d", Ans);
	
	return 0;
}
