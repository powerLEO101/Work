/***************************
  * Writer : Leo101
  * Problem : T3 pos
  * Tags : 
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 30
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Start[600], End[221184];
int S_Len, Gox[4] = {0, 0, 1, -1}, Goy[4] = {1, -1, 0, 0};

char Map[_][_];

class Edge
{
public:
	int Next, To;
}Edges[442368];
int Head[221184], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

void Get(int x, int y, int n, int m, int Time)
{
	for (int i = 0; i < 4; i++) {
		int Tox = x + Gox[i], Toy = y + Goy[i];
		if (Tox < 0 || Toy < 0 || Tox >= n || Toy >= m) continue;
		if (Map[Tox][Toy] == 'W') continue;
		Add_edge((Time * n * m) + (x * n + y), ((Time + 1) * n * m) + (Tox * n + Toy));
	}
}
void Build(int n, int m, int Time)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == 'W') continue;
			if (Map[i][j] == 'P' && Time == 0)
				Start[S_Len++] = i * n + j;
			if (Map[i][j] == 'D') 
				End[(Time * n * m) + i * n + j] = true;
			Get(i, j, n, m, Time);
		}
}

char Vis[221184], Can[221184];
int Bfs(int S)
{
	memset(Vis, 0, sizeof(Vis));
	std::queue<int> Q, Deep;
	Q.push(S);
	Deep.push(1);
	Vis[S] = true;
	while (!Q.empty()) {
		int Now = Q.front(), Now_Deep = Deep.front();
		Q.pop(); Deep.pop();
		for_edge(i, Now) {
			int To = Edges[i].To;
			if (Vis[To] == true || Can[To] == true) continue;
			if (End[To] == true) return Now_Deep + 1;
			Vis[To] = true;
			Q.push(To); Deep.push(Now_Deep + 1);
		}
	}
	return -1;
}

void Dfs(int Now, int n, int m)
{
	if (Vis[Now] == true) return ;
	Vis[Now] = Can[Now] = true;
	for_edge (i, Now) {
		int To = Edges[i].To;
		int Temp = To % (n * m);
		if (Map[Temp / n][Temp % n] == 'D' || Map[Temp / n][Temp % n] == 'W') continue;
		Dfs(To, n, m);
	}
}

void CASE1(int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == 'W') continue;
			for (int k = 0; k < 4; k++) {
				int x = i + Gox[k], y = j + Goy[k];
				if (x < 0 || y < 0 || x >= n || y >= m) continue;
				if (Map[x][y] == 'W') continue;
				if (Map[i][j] == 'P')
					Start[S_Len++] = i * n + j;
				if (Map[i][j] == 'D')
					End[i * n + j] = true;
				Add_edge(i * n + j, x * n + y);
			}
		}
}

int main()
{
	File(pos);

	int T = gi;
	while (T--) {
		
		memset(Head, -1, sizeof(Head));
		memset(Can, 0, sizeof(Can));
		memset(Start, 0, sizeof(Start));
		memset(End, 0, sizeof(End));
		S_Len = 0;
		E_num = 0;

		int n = gi, m = gi, k = gi;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				Map[i][j] = getchar();
			getchar();
		}

		for (int i = 0; i <= 2 * (n + m); i++) Build(n, m, i);
		for (int i = 0; i < k; i++) {
			int x = gi - 1, y = gi - 1;
			if (Map[x][y] == 'W') continue;
			memset(Vis, 0, sizeof(Vis));
			Dfs(x * n + y, n, m);
		}
		
		char Flag = true;
		int Ans = 0;
		for (int i = 0; i < S_Len; i++) {
			int Temp = Bfs(Start[i]);
			if (Temp == -1) {
				Flag = false;
				break;
			}
			Ans = std::max(Temp, Ans);
		}

		if (Flag == false) printf("Death\n");
		else printf("%d\n", Ans);
	}
	
	return 0;
}

