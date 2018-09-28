/**************************
  * Writer : Leo101
  * Problem : UOJ #67. 新年的毒瘤
  * Tags : 割点, 图论
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 2000000
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
} Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

int Tot, Dfn[_], Low[_];
bool Cut[_];
void Tarjan(int Now)
{
	Dfn[Now] = Low[Now] = Tot++;

	int Count = 0;
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (Dfn[To] == -1) {
			Count++;
			Tarjan(To);
			Low[Now] = std::min(Low[Now], Low[To]);
			if (Now != 0 && Low[To] >= Dfn[Now]) Cut[Now] = true;
		} else {
			Low[Now] = std::min(Low[Now], Dfn[To]);
		}
	}

	if (Now == 0 && Count > 1) Cut[Now] = true;
}

int Sum[_];

int main()
{
	File(code);
	
	memset(Head, -1, sizeof(Head));
	memset(Dfn, -1, sizeof(Dfn));

	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To);
		Add_edge(To, From);
		Sum[From]++;
		Sum[To]++;
	}
	
	Tarjan(0);

	int Cnt = 0;
	for (int i = 0; i < n; i++) {
		if (Cut[i] == true || m - (n - 2) != Sum[i]) continue;
		Cnt++;
	}

	printf("%d\n", Cnt);
	
	for (int i = 0; i < n; i++) {
		if (Cut[i] == true || m - (n - 2) != Sum[i]) continue;
		printf("%d ", i + 1);
	}

	return 0;
}
