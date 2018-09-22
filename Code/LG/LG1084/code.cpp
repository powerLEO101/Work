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
	int Next, To, Value;
}Edges[_];
int Head[_], E_num, n, m;
int Lena, Lenb, RestId[_], RestMin[_], Up[_][21], Dis[_][21];
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

void Dfs(int Now = 0)
{
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Up[Now][0]) continue;
		Up[To][0] = Now;
		Dis[To][0] = Value;
		Dfs(To);
	}
}

class Node
{
public:
	int Id, Rest;
}a[_], b[_];
bool operator< (const Node& a, const Node& b)
{
	return a.Rest > b.Rest;
}
bool Vis[_];
		

bool Judge(int Now = 0, int Pre = -1)
{
	if (Vis[Now] == true) return true;
	bool Flag = true, Flag1 = false;
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Pre) continue;
		Flag1 = true;
		if (Judge(To, Now) == true) continue;
		Flag = false;
		if (Now == 0) b[Lenb++] = (Node){To, Value};
		else return false;
	}
	if (Flag1 == false) return false;
	return Flag;
}

int Army[_];
bool Used[_];

bool Check(int Mid)
{
	memset(RestId, -1, sizeof(RestId));
	memset(RestMin, 0, sizeof(RestMin));
	memset(Used, 0, sizeof(Used));
	memset(Vis, 0, sizeof(Vis));
	Lena = Lenb = 0;
	for (int i = 0; i < m; i++) {
		int x = Army[i];
		int Num = 0;
		for (int j = 20; j >= 0; j--) 
			if (Up[x][j] > 0 && Dis[x][j] + Num <= Mid) 
				Num += Dis[x][j],
				x = Up[x][j];
		if (Up[x][0] == 0 && Num + Dis[x][0] <= Mid) {
			a[Lena++] = (Node){i, Mid - Num - Dis[x][0]};
			if (RestId[x] == -1 || a[Lena - 1].Rest < RestMin[x]) {
				RestId[x] = i;
				RestMin[x] = a[Lena - 1].Rest;
			}
		} else {
			Vis[x] = true;
		}
	}
	if (Judge() == true) return true;
	std::sort(a, a + Lena); std::sort(b, b + Lenb);
	int Now = 0;
	for (int i = 0; i < Lenb; i++) {
		int Id = b[i].Id, Rest = b[i].Rest;
		if (RestId[Id] != -1 && Used[RestId[Id]] == false) {
			Used[RestId[Id]] = true;
			continue;
		}
		while (Now < Lena && (Used[a[Now].Id] == true || Rest > a[Now].Rest)) Now++;
		if (Now == Lena) return false;
		Used[a[Now].Id] = true;
	}
	return true;
}

int main()
{
	File(code);
	memset(Head, -1, sizeof(Head));
	n = gi;
	for (int i = 1; i < n ; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		Add_edge(From, To, Value);
		Add_edge(To, From, Value);
	}
	Dfs();
	for (int j = 1; j < 21; j++)
		for (int i = 0; i < n; i++)
			Up[i][j] = Up[Up[i][j - 1]][j - 1],
			Dis[i][j] = Dis[i][j - 1] + Dis[Up[i][j - 1]][j - 1];
	m = gi;
	for (int i = 0; i < m; i++) Army[i] = gi - 1;
	int l = 0, r = 1e9, Ans = -1;
	while (l <= r) {
		int Mid = (l + r) / 2;
		if (Check(Mid) == true) r = Mid - 1, Ans = Mid;
		else l = Mid + 1;
	}
	printf("%d", Ans);
	return 0;
}
