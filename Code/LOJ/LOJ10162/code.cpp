/**************************
  * Writer : Leo101
  * Problem : LOJ #10162. 「一本通 5.2 练习 5」骑士
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 2000000
#define INF 0x3f3f3f3f
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
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

long long Fa[_], Val[_];
long long Dp[_][2];
bool Vis[_];
void Dfs(int Now, int Pre)
{
	Dp[Now][0] = 0;
	Dp[Now][1] = Val[Now];
	Vis[Now] = true;
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Pre) {
			Dp[To][1] = -INF;
			continue;
		}
		Dfs(To, Pre);
		Dp[Now][1] += Dp[To][0];
		Dp[Now][0] += std::max(Dp[To][0], Dp[To][1]);
	}
}
long long Get_ans(int Now)
{
	while (Vis[Now] == false) {
		Vis[Now] = true;
		Now = Fa[Now];
	}
	Dfs(Now, Now); 
	long long Ans = std::max(Dp[Now][0], Dp[Now][1]);
	Dfs(Fa[Now], Fa[Now]);
	Ans = std::max(Ans, std::max(Dp[Fa[Now]][0], Dp[Fa[Now]][1]));
	return Ans;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 0; i < n; i++) {
		Val[i] = gi;
		Fa[i] = gi - 1;
		Add_edge(Fa[i], i);
	}

	long long Ans = 0;
	for (int i = 0; i < n; i++) {
		if (Vis[i] == true) continue;
		Ans += Get_ans(i);
	}
	std::cout << Ans;

	return 0;
}
