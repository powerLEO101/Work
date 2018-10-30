/**************************
 * Writer : Leo101
 * Problem : LOJ #10166. 「一本通 5.3 练习 1」数字游戏
 * Tags : Digital Dp
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 35
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

int Num[_], Dp[_][101], Mod;

int Dfs(int Now, int Sum, char Flag)
{
	//printf("%d %d %d\n", Now, Sum, Flag);
	if (Now < 0) return (Sum % Mod) == 0;
	if (Flag == false && Dp[Now][Sum] != -1) return Dp[Now][Sum];
	int Lim = Flag == true ? Num[Now] : 9;
	int Ret = 0;
	for (int i = 0; i <= Lim; i++)
		Ret += Dfs(Now - 1, Sum + i, Flag & (i == Lim));
	if (Flag == false) Dp[Now][Sum] = Ret;
	return Ret;
}
int Get_ans(int Lim)
{
	memset(Num, 0, sizeof(Num));
	memset(Dp, -1, sizeof(Dp));
	int Len = 0;
	while (Lim != 0) {
		Num[Len++] = Lim % 10;
		Lim /= 10;
	}

	int Ans = 0;
	for (int i = 0; i < Num[Len - 1]; i++) Ans += Dfs(Len - 2, i, false);
	Ans += Dfs(Len - 2, Num[Len - 1], true);
	return Ans;
}

int main()
{
	File(code);

	int l, r;
	while (scanf("%d%d%d",& l,& r,& Mod) == 3)
		printf("%d\n", Get_ans(r) - Get_ans(l - 1));

	return 0;
}
