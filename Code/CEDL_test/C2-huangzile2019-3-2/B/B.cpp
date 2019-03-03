/**************************
  * Writer : Leo101
  * Problem : Test2019-3-2 B
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
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

class Node
{
public:
	int x, y;
}Nodes[Max_N * Max_N];
int N_num;
void Add_node(int x, int y)
{ Nodes[N_num++] = (Node) {x, y}; }

int n;
int Map[Max_N][Max_N], Value[Max_N][Max_N];
int Gox[4] = {0, 0, 1, -1}, Goy[4] = {1, -1, 0, 0};

int ABS(int x) { return x < 0 ? -x : x; }
void Dfs(int x, int y, int DistX = 0, int DistY = 0)
{
	for (int i = 0; i < 4; i++) {
		int Gx = x + Gox[i], Gy = y + Goy[i];
		int Val = std :: max(DistX + ABS(Gox[i]), DistY + ABS(Goy[i]));
		if (Gx < 0 || Gy < 0 || Gx >= n || Gy >= n) 
			continue;
		if (Map[Gx][Gy] == 1 || Value[Gx][Gy] <= Val)
			continue;
		Value[Gx][Gy] = Val;
		Dfs(Gx, Gy, DistX + ABS(Gox[i]), DistY + ABS(Goy[i]));
	}
}

int Ans, Vis[Max_N][Max_N], Fuck[Max_N][Max_N];
class Data { public: int Index, Val; } Tmp[4];
bool operator< (const Data& a, const Data& b) 
{ return a.Val > b.Val; }
int Dfs(int x1, int y1, int x2, int y2, int Val)
{
	if (x1 == x2 && y1 == y2) {
		return true;
	}
	Fuck[x1][y1] = true;
	for (int i = 0; i < 4; i++) {
		int Gx = x1 + Gox[i], Gy = y1 + Goy[i];
		if (Gx < 0 || Gy < 0 || Gx >= n || Gy >= n)
			continue;
		if (Fuck[Gx][Gy] == true || Value[Gx][Gy] < Val) continue;
		if (Dfs(Gx, Gy, x2, y2, Val) == 1) 
			return 1;
	}
	return 0;
}
int Get_ans(int x1, int y1, int x2, int y2)
{
	int l = 0, r = Value[x1][y1], Ans = 0;
	while (l <= r) {
		int Mid = (l + r) / 2;
		memset(Fuck, 0, sizeof(Fuck));
		if (Dfs(x1, y1, x2, y2, Mid) == true) l = Mid + 1, Ans = Mid;
		else r = Mid - 1;
	}
	return Ans;
}
int main()
{
	File(B);

	n = gi;
	for (int i = 0; i < n; i++) {
		std :: string Str;
		std :: cin >> Str;
		for (int j = 0; j < n; j++) {
			Map[i][j] = Str[j] == '.' ? 0 : 1;
			if (Map[i][j] == 1) Add_node(i, j);
		}
	}

	memset(Value, 0x3f, sizeof(Value));
	for (int i = 0; i < N_num; i++) {
		int x = Nodes[i].x, y = Nodes[i].y;
		Value[x][y] = 0;
		Dfs(x, y);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Value[i][j] == 0) continue;
			int Max_Val = std :: min(std :: min(i, j) + 1, std :: min(n - i, n - j));
			Value[i][j] = std :: min(Value[i][j], Max_Val);
			Value[i][j] = (Value[i][j] - 1) * 2 + 1;
		}
	}

	int Q = gi;
	while (Q--) {
		Ans = 0;
		memset(Vis, -1, sizeof(Vis));
		memset(Fuck, 0, sizeof(Fuck));
		int x1 = gi - 1, y1 = gi - 1, x2 = gi - 1, y2 = gi - 1;
		printf("%d\n", Get_ans(x1, y1, x2, y2));
	}

	return 0;
}
