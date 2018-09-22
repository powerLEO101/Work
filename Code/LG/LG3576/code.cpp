/**************************
  * Writer : Leo101
  * Problem : Luogu3576 [POI2014]MRO-Ant colony
  * Tags : Dfs, 二分查找, 动态规划, 树形动规
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 2000100
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

int Out[_], n, g, k;
long long L[_], R[_], s[_];

void Dfs(int Now, int Pre)
{
	for_edge (i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Out[Now] = Out[Now] + 1;
	}
	
	for_edge (i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		L[To] = L[Now] * Out[Now];
		R[To] = (R[Now] + 1) * Out[Now] - 1;
		R[To] = std::min(R[To], s[g - 1]);
		if (L[To] <= s[g - 1]) Dfs(To, Now);
	}
}

long long Binary_Search(long long x)
{
	int l = 0, r = g - 1, Ans = -1;
	while (l <= r) {
		int Mid = (l + r) / 2;
		if (s[Mid] < x) {
			Ans = Mid;
			l = Mid + 1;
		} else {
			r = Mid - 1;
		}
	}
	return Ans;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	n = gi, g = gi, k = gi;
	for (int i = 0; i < g; i++) s[i] = gi;
	int From = gi - 1, To = gi - 1;
	Add_edge(From, To);
	Add_edge(To, From);
	int S1 = From, S2 = To;
	for (int i = 2; i < n; i++) {
		From = gi - 1, To = gi - 1;
		Add_edge(From, To);
		Add_edge(To, From);
	}

	std::sort(s, s + g);
	L[S1] = L[S2] = R[S1] = R[S2] = k;
	Dfs(S1, S2);
	Dfs(S2, S1);
	
	long long Ans = 0;
	for (int i = 0; i < n; i++) {
		if (Out[i] != 0) continue;
		Ans += Binary_Search(R[i] + 1) - Binary_Search(L[i]);
	}
	printf("%lld", Ans * k);
	return 0;
}
