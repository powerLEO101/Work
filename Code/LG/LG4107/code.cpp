/**************************
  * Writer : Leo101
  * Problem : Luogu P4107 [HEOI2015]兔子与樱花
  * Tags : 贪心，Dfs
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
const int Max_N = 2100000;
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
	int Next, To;
}Edges[Max_N];
int Head[Max_N], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge) {Head[From], To};
	Head[From] = E_num++;
}

int Sum[Max_N], Cost[Max_N], Tmp[Max_N];
int Ans, n, m;
void Dfs(int Now = 0)
{
	int Num = 0;
	for_edge(i, Now) {
		int To = Edges[i].To;
		Dfs(To);
		Sum[Now] += Sum[To];
		Tmp[Num++] = Cost[To];
	}
	
	std::sort(Tmp, Tmp + Num);
	int Count = m - Sum[Now];

	for (int i = 0; i < Num; i++) {
		if (Count - Tmp[i] < 0) break;
		Count -= Tmp[i];
		Ans++;
	}

	Sum[Now]++;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	n = gi, m = gi;
	for (int i = 0; i < n; i++) Cost[i] = gi;
	for (int i = 0; i < n; i++) {
		int Number = gi;
		for (int j = 0; j < Number; j++) Add_edge(i, gi);
	}

	Dfs();

	printf("%d", Ans);

	return 0;
}
