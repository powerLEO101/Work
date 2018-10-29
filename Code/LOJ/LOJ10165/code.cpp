/**************************
  * Writer : Leo101
  * Problem : LOJ #10165. 「一本通 5.3 例 3」Windy 数
  * Tags : Digital Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1001
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

int Len, Dp[_][10][2], Num[_];

int Dist(int a, int b) { return a - b < 0 ? b - a : a - b; }
int Dfs(int Now, int Pre, bool Flag, bool Zero)
{
	if (Dp[Now][Pre][Zero] != -1 && Flag == false) return Dp[Now][Pre][Zero];
	if (Now == 0) return 1;
	int Ret = 0;
	if (Flag == false) {
		for (int i = 0; i < 10; i++) {
			if (Zero == false && Dist(i, Pre) < 2) continue;
			Ret += Dfs(Now - 1, i, false, (i == 0) & Zero);
		}
	} else {
		for (int i = 0; i < Num[Now]; i++) {
			if (Zero == false && Dist(i, Pre) < 2) continue;
			Ret += Dfs(Now - 1, i, false, (i == 0) & Zero);
		}
		if (Dist(Pre, Num[Now]) >= 2 || Zero == true) Ret += Dfs(Now - 1, Num[Now], true, (Num[Now] == 0) & Zero);
	}
	if (Flag == false) Dp[Now][Pre][Zero] = Ret;
	return Ret;
}
int Get_ans(int Lim)
{
	if (Lim == 0) return 1;
	memset(Dp, -1, sizeof(Dp));
	memset(Num, 0, sizeof(Num));
	Len = 0;
	while (Lim != 0) {
		Num[++Len] = Lim % 10;
		Lim /= 10;
	}
	int Ans = 0;
	for (int i = 0; i < Num[Len]; i++) Ans += Dfs(Len - 1, i, false, (i == 0));
	Ans += Dfs(Len - 1, Num[Len], true, (Num[Len] == 0));
	return Ans;
}

int main()
{
	File(code);
	
	int l = gi, r = gi;
	printf("%d", Get_ans(r) - Get_ans(l - 1));

	return 0;
}
