/**************************
  * Writer : Leo101
  * Problem : LOJ #10169. 「一本通 5.3 练习 4」数字计数
  * Tags : Digital Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

long long Dp[20][2][20][2];
int Num[20];
long long Dfs(int Now, int Sum, bool Flag, bool Zero, int Target)
{
	if (Now == -1) return Sum;
	if (Dp[Now][Zero][Sum][Flag] != -1) return Dp[Now][Zero][Sum][Flag];
	long long Ret = 0;
	int Lim = Flag == false ? 9 : Num[Now];
	for (int i = 0; i <= Lim; i++)
		Ret += Dfs(Now - 1, Sum + (i == Target && (Zero == false || (i != 0))), Flag & (i == Lim), Zero & (i == 0), Target);
	Dp[Now][Zero][Sum][Flag] = Ret;
	return Ret;
}

long long Get_ans(long long Lim, int Digit)
{
	memset(Num, 0, sizeof(Num));
	memset(Dp, -1, sizeof(Dp));
	int Len = 0;
	while (Lim != 0) {
		Num[Len++] = Lim % 10;
		Lim /= 10;
	}
	
	return Dfs(Len - 1, 0, true, true, Digit);
}

int main()
{
	File(code);

	long long l = gi, r = gi;
	for (int i = 0; i < 10; i++)
		printf("%lld ", Get_ans(r, i) - Get_ans(l - 1, i));

	return 0;
}
