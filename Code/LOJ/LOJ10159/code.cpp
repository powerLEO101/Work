/**************************
  * Writer : Leo101
  * Problem : LOJ #10159. 「一本通 5.2 练习 2」旅游规划
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
	int Next, To;
}Edges[_];
int E_num, Head[_];
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}


int Diameter, Dp1[_], Dp2[_], Dp3[_];
void Get_ans1(int Now = 0, int Pre = -1)
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Get_ans1(To, Now);
		if (Dp1[Now] < Dp1[To] + 1) {
			Dp2[Now] = Dp1[Now];
			Dp1[Now] = Dp1[To] + 1;
		} else if (Dp2[Now] < Dp1[To] + 1) {
			Dp2[Now] = Dp1[To] + 1;
		}
	}
	Diameter = std::max(Diameter, Dp1[Now] + Dp2[Now]);
}
void Get_ans2(int Now = 0, int Pre = -1)
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		if (Dp1[To] + 1 == Dp1[Now]) Dp3[To] = std::max(Dp2[Now] + 1, Dp3[Now] + 1);
		else Dp3[To] = std::max(Dp1[Now] + 1, Dp3[Now] + 1);
		Get_ans2(To, Now);
	}
}

int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 1; i < n; i++) {
		int From = gi, To = gi;
		Add_edge(From, To);
		Add_edge(To, From);
	}
	
	Get_ans1();
	Get_ans2();

	for (int Now = 0; Now < n; Now++) {
		if (Dp1[Now] + Dp2[Now] == Diameter || Dp1[Now] + Dp3[Now] == Diameter) {
			printf("%d\n", Now);
		}
	}

	return 0;
}
