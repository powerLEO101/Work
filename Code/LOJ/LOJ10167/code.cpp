/**************************
  * Writer : Leo101
  * Problem : LOJ #10167. 「一本通 5.3 练习 2」不要 62
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

int Num[_], Dp[_][10];
int Dfs(int Now, int Pre, char Flag)
{
	if (Now == -1) return 1;
	if (Dp[Now][Pre] != -1 && Flag == false) return Dp[Now][Pre];
	int Lim = Flag == true ? Num[Now] : 9;
	
	int Ret = 0;
	for (int i = 0; i <= Lim; i++) {
		if (i == 4 || (Pre == 6 && i == 2)) continue;
		Ret += Dfs(Now - 1, i, Flag & (i == Lim));
	}
	return Ret;
}
int Get_ans(int Lim)
{
	if (Lim < 4) return Lim + 1;
	if (Lim > 4 && Lim < 10) return Lim;
	memset(Num, 0, sizeof(Num));
	memset(Dp, -1, sizeof(Dp));
	int Len = 0;
	while (Lim != 0) {
		Num[Len++] = Lim % 10;
		Lim /= 10;
	}

	int Ans = 0;
	for (int i = 0; i < Num[Len - 1]; i++) 
		if (i != 4) Ans += Dfs(Len - 2, i, false);
	if (Num[Len - 1] != 4) Ans += Dfs(Len - 2, Num[Len - 1], true);
	return Ans;
}

int main()
{
	File(code);

	int l = gi, r = gi;
	while ( !(l == 0 && r == 0) ) {
		printf("%d\n", Get_ans(r) - Get_ans(l - 1));

		l = gi, r = gi;
	}

	return 0;
}

