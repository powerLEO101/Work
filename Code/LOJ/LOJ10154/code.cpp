/**************************
  * Writer : Leo101
  * Problem : LOJ #10154. 「一本通 5.2 例 2」选课
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 400
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
}Edges[_ << 1];
int Head[_], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

int n, m;
int Dp[_][_], Val[_];
void Get_ans(int Now = 0)
{
	Dp[Now][0] = 0;
	
	for_edge(j, Now) {
		int To = Edges[j].To;
		Get_ans(To);
		for (int i = m; i > 0; i--)
			for (int j = 0; j <= i; j++)
				Dp[Now][i] = std::max(Dp[Now][i], Dp[Now][i - j] + Dp[To][j]);
	}
	if (Now != 0)
		for (int i = m; i > 0; i--)
			Dp[Now][i] = Dp[Now][i - 1] + Val[Now];
}

int main()
{
	File(code);
	
	memset(Head, -1, sizeof(Head));

	n = gi, m = gi;
	for (int i = 1; i <= n; i++) {
		int Fa = gi;
		Add_edge(Fa, i);
		Val[i] = gi;
	}
	
	memset(Dp, -1, sizeof(Dp));
	Get_ans();

	std::cout << Dp[0][m];

	return 0;
}
