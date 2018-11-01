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
#define _ 30
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
long long Pow[20];
Node Dfs(int Now, int Sum, int Val, bool Flag)
{
	if (Flag == false && Dp[Now][Sum][Val].Cnt != -1) return Dp[Now][Sum][Val];
	if (Now == -1) return (Node) {0, 0, Sum && Val};

	int Lim = Flag == true ? Num[Now] : 9;
	Node Ret;
	for (int i = 0; i <= Lim; i++) {
		if (i == 7) continue;
		int Cur = (i * Pow[Now]) % Mod;
		Node Tmp = Dfs(Now - 1, (Sum + i) % 7, (Val * 10 + i) % 7, Flag & (i == Lim));
		Ret.Cnt = (Ret.Cnt + Tmp.Cnt) % Mod;
		Ret.Sum = (Ret.Sum + ((Cur * Tmp.Cnt) + Tmp.Sum) % Mod) % Mod;
		Ret.Sq = (((Ret.Sq + Tmp.Sq) % Mod + (Tmp.Cnt * ((Cur * Cur) % Mod)) % Mod) % Mod + (((2 * Cur) % Mod) * Tmp.Sum) % Mod) % Mod;
	}
	if (Flag == false) Dp[Now][Sum][Val] = Ret;
	return Ret;
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

	Pow[0] = 1;
	for (int i = 1; i < 20; i++) Pow[i] = (Pow[i - 1] * 10) % Mod;

	int T = gi;
	while (T--) {
		long long l = gi, r = gi;
		printf("%lld\n", ((Get_ans(r) + Mod) - Get_ans(l - 1)) % Mod);
	}

	return 0;
}
