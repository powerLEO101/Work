/**************************
  * Writer : Leo101
  * Problem : LOJ #10161. 「一本通 5.2 练习 4」叶子的颜色
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 20000
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

int n, m, Dp[_][2], Color[_];
void Get_ans(int Now, int Pre = -1)
{
	if (Now < m) {
		Dp[Now][Color[Now] ^ 1] = INF;
		Dp[Now][Color[Now]] = 1;
		return ;
	}
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Get_ans(To, Now);
		Dp[Now][0] += std::min(Dp[To][0] - 1, Dp[To][1]);
		Dp[Now][1] += std::min(Dp[To][0], Dp[To][1] - 1);
	}
	Dp[Now][0]++; Dp[Now][1]++;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	n = gi, m = gi;
	for (int i = 0; i < m; i++) Color[i] = gi;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1;
		Add_edge(From, To);
		Add_edge(To, From);
	}

	Get_ans(n - 1);
	
	printf("%d", std::min(Dp[n - 1][0], Dp[n - 1][1]));

	return 0;
}
