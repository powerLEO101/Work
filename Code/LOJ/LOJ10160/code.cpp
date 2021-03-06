/**************************
  * Writer : Leo101
  * Problem : LOJ #10160. 「一本通 5.2 练习 3」周年纪念晚会
  * Tags : Tree Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 7000
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

int Val[_], Dp[_][2];
void Get_ans(int Now)
{
	for_edge(i, Now) {
		int To = Edges[i].To;
		Get_ans(To);
		Dp[Now][1] += Dp[To][0];
		Dp[Now][0] += std::max(Dp[To][1], Dp[To][0]);
	}
	Dp[Now][1] += Val[Now];
}

int In[_];
int main()
{
	File(code);

	memset(Head, -1, sizeof(Head));

	int n = gi;
	for (int i = 0; i < n; i++) Val[i] = gi;
	int To = gi - 1, From = gi - 1;
	while (!(From == -1 && To == -1)) {
		Add_edge(From, To);
		In[To]++;
		To = gi - 1, From = gi - 1;
	}
	
	for (int i = 0; i < n; i++)
		if (In[i] == 0) {
			Get_ans(i);
			printf("%d", std::max(Dp[i][0], Dp[i][1]));
			break;
		}

	return 0;
}
