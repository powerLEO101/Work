/**************************
  * Writer : Leo101
  * Problem : LOJ #10168. 「一本通 5.3 练习 3」恨 7 不成妻
  * Tags : Digital Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define Mod 1000000007
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

class Node
{
public:
	long long Cnt;
	long long Sum;
	long long Sq;
} Dp[_][20][20];

int Num[20];
Node Dfs(int Now, int Sum, int Val, bool Flag)
{
	if (Flag == false && Dp[Now][Sum][Val] != -1) return Dp[Now][Sum][Val];
	if (Now == -1) return (Node){1, 0, 0};

	int Lim = Flag == true ? Num[Now] : 9;
	Node Ret;
	for (int i = 0; i <= Lim; i++) {
		if (i == 7 || ) continue;
		Dfs(To);
	}
}

long long Get_ans(long long Lim)
{
	memset(Num, 0, sizeof(Num));
	memset(Dp, 0, sizeof(Dp));
	int Len = 0;
	while (Lim != 0) {
		Num[Len++] = Lim % 10;
		Lim /= 10;
	}

	return Dfs(Len - 1, 0, 0, true).Sq;
}

int main()
{
	File(code);

	int T = gi;
	while (T--) {
		long long l = gi, r = gi;
		printf("%lld\n", ((Get_ans(r) + Mod) - Get_ans(l - 1)) % Mod);
	}

	return 0;
}
