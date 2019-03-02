/**************************
  * Writer : Leo101
  * Problem : Luogu P3684 [CERC2016]机棚障碍 Hangar Hurdles
  * Tags : Kruskal重构树，二分
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
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

int Value[Max_N][Max_N], Map[Max_N][Max_N];
int Gox[4] = {0, 0, 1, -1}, Goy[4] = {1, -1, 0, 0};

void Get_Dist(int n)
{
	std :: queue<int> Qx, Qy;
	memset(Value, 0x3f, sizeof(Value));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (Map[i][j] == 1) {
				Qx.push(i), Qy.push(j); 
				Value[i][j] = 0;
			}

	while (!Qx.empty()) {
		int x = Qx.front(), y = Qy.front();
		Qx.pop(); Qy.pop();
		for (int i = 0; i < 4; i++) {
			int Gx = x + Gox[i], Gy = y + Goy[i];
			if (Gx < 0 || Gy < 0 || Gx >= n || Gy >= n)
				continue;
			if (Value[Gx][Gy] != INF) continue;
			Value[Gx][Gy] = Value[x][y] + 1;
			Qx.push(Gx); Qy.push(Gy);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Value[i][j] == 0) continue;
			int Max_Val = std :: min(std :: min(i, j) + 1, std :: min(n - i, n - j));
			Value[i][j] = std :: min(Value[i][j], Max_Val);
			Value[i][j] = 2 * (Value[i][j] - 1) + 1;
		}
	}
}

class edge
{
public:
	int From, To, Value;
} edges[Max_N * Max_N * 10];
int e_num;
void add_edge(int From, int To, int Value)
{ edges[e_num++] = (edge) {From, To, Value}; }
bool operator< (const edge& a, const edge& b)
{ return a.Value > b.Value; }

int Father[Max_N * Max_N * 10];
int Get_fathet(int u) 
{ return Father[u] == u ? u : Father[u] = Get_father(Father[u]); }

class Edge
{
public:
	int Next, To;
} Edges[Max_N * Max_N * 10];
int Head[Max_N * Max_N * 10], E_num;
int Node[Max_N * Max_N * 10], N_num = Max_N * Max_N + 1;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num++] = (Edge) {Head[From], To};
	Head[From] = E_num++;
}

void Build_Graph(int n)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int x = 0; x < 4; x++) {
				int Gx = i + Gox[i], Gy = j + Goy[i];
				if (Gx < 0 || Gy < 0 || Gx >= n || Gy >= n)
					continue;
				add_edge(i * n + j, Gx * n + Gy, std :: min(Value[i][j], Value[Gx][Gy]));
			}
		}
	}
}
void Ex_Kruskal(int n)
{
	Build_Graph(n);
	std :: sort(edges, edges + e_num);
	for (int i = 0; i < Max_N * Max_N * 10; i++) Father[i] = i;

	for (int i = 0; i < e_num; i++) {
		int From = edges[i].From, To = edges[i].To, Value = edges[i].Value;
		int Fa_F = Get_father(From), Fa_T = Get_father(To);
		if (Fa_F == Fa_T) continue;
		Father[Fa_F] = Fa_T;
		Add_edge(N_num, Fa_F); Add_edge(Fa_F, N_num);
		Add_edge(N_Num, Fa_T); Add_edge(Fa_T, N_num);
		Node[N_num++] = Value;
	}
}

int main()
{
	File(code);

	int n = gi;
	for (int i = 0; i < n; i++) {
		std :: string Str;
		std :: cin >> Str;
		for (int j = 0; j < n; j++)
			Map[i][j] = Str[j] == '.' ? 0 : 1;
	}

	Get_Dist(n);
	Ex_Kruskal(n);

	return 0;
}
