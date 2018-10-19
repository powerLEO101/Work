/**************************
  * Writer : Leo101
  * Problem : LOJ #10155. 「一本通 5.2 例 3」数字转换
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 500000
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
	int Next, To, Value;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

int Num[_], Dp[_];
void Get_ans(int Now, int Pre = -1)
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Get_ans(To, Now);
		Dp[Now] = std::max(Dp[Now], Dp[To] + 1);
	}
}

int main()
{
	File(code);
	
	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 1; i <= n; i++) {
		if (Num[i] < i) {
			Add_edge(Num[i], i);
			Add_edge(i, Num[i]);
		}
		for (int j = i * 2; j <= n; j += i) Num[j] += i;
	}

	Get_ans(1);

	int Ans1 = 0, Ans2 = 0;
	for_edge(i, 1) {
		int To = Edges[i].To;
		if (Dp[To] > Ans1) {
			Ans2 = Ans1;
			Ans1 = Dp[To];
		} else if (Dp[To] > Ans2) {
			Ans2 = Dp[To];
		}
	}

	printf("%d", Ans1 + Ans2 + 2);

	return 0;
}
