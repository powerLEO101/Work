/**************************
  * Writer : Leo101
  * Problem : LOJ #10157. 「一本通 5.2 例 5」皇宫看守
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define INF 0x3f3f3f3f
#define _ 10001
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

int Val[_], Dp[_][3];
void Get_ans(int Now = 1, int Pre = -1)
{
	bool Flag = false;
	int Min = -1;
	Dp[Now][0] = Val[Now];
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Get_ans(To, Now);
		Dp[Now][0] += std::min(Dp[To][0], std::min(Dp[To][1], Dp[To][2]));
		Dp[Now][2] += Dp[To][1];
		if (Min == -1) Min = To;
		else Min = Dp[Min][0] < Dp[To][0] ? Min : To;
		if (Dp[To][0] < Dp[To][1]) {
			Flag = true;
			Dp[Now][1] += Dp[To][0];
		} else {
			Dp[Now][1] += Dp[To][1];
		}
	}
	if (Flag == false && Min != -1)
		Dp[Now][1] += Dp[Min][0] - Dp[Min][1];
	if (Min == -1) Dp[Now][1] = INF;
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 0; i < n; i++) {
		int Now = gi;
		Val[Now] = gi;
		int Size = gi;
		while (Size--) {
			int To = gi;
			Add_edge(Now, To);
			Add_edge(To, Now);
		}
	}

	Get_ans();

	printf("%d", std::min(Dp[1][0], Dp[1][1]));

	return 0;
}
