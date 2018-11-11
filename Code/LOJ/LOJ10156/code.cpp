/**************************
  * Writer : Leo101
  * Problem : LOJ #10156. 「一本通 5.2 例 4」战略游戏
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 6000
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

int Dp[_][2];
void Get_ans(int Now = 0) 
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		Get_ans(To);
		Dp[Now][0] += Dp[To][1];
		Dp[Now][1] += std::min(Dp[To][0], Dp[To][1]);
	}
	Dp[Now][1]++;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 0; i < n; i++) {
		int From = gi, Size = gi;
		while (Size--) {
			int To = gi;
			Add_edge(From, To);
		}
	}

	Get_ans();

	printf("%d", std::min(Dp[0][1], Dp[0][0]));

	return 0;
}
