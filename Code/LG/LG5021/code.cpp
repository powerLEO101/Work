/**************************
  * Writer : Leo101
  * Problem : LuoguP5021 赛道修建
  * Tags :  贪心，二分答案，树型Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
const int Max_N = 5e5;
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
}Edges[Max_N << 1];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

std::multiset<int> MultiSet;
int Cnt, Mid, Dp[Max_N], Stack[Max_N];
void Dfs(int Now, int Pre)
{
	/*Prepare*/
	for_edge (i, Now) {
		int To = Edges[i].To;
		if (To == Pre) continue;
		Dfs(To, Now);
	}

	/*Dp & Get_Cnt*/
	int Len = 0;
	for_edge(i, Now) {
		int To = Edges[i].To, Value = Edges[i].Value;
		if (To == Pre) continue;
		Dp[To] += Value;
		if (Dp[To] >= Mid) Cnt++;
		else Stack[Len++] = Dp[To];
	}

	std::sort(Stack, Stack + Len);
	MultiSet.clear();

	/*Get_Cnt*/
	for (int i = 0; i < Len; i++) {
		auto Tmp = MultiSet.lower_bound(Mid - Stack[i]);
		if (Tmp != MultiSet.end()) Cnt++, MultiSet.erase(Tmp);
		else MultiSet.insert(Stack[i]);
	}
	
	Dp[Now] = MultiSet.size() == 0 ? 0 : *(MultiSet.rbegin());
}

int main()
{
	File(code);

	/*Prepare*/
	memset(Head, -1, sizeof(Head));

	/*Input*/
	int n = gi, m = gi, Sum = 0;
	for (int i = 1; i < n; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		Sum += Value;
		Add_edge(From, To, Value); Add_edge(To, From, Value);
	}

	/*Binary_Search*/
	int l = 0, r = Sum / m, Ans = Sum / m;
	while (l <= r) {
		Mid = (l + r) / 2;
		Cnt = 0; Dfs(0, -1);
		if (Cnt < m) r = Mid - 1;
		else l = Mid + 1, Ans = Mid;
	}

	/*Output*/
	printf("%d", Ans);
	
	return 0;
}
