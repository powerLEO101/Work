/**************************
  * Writer : Leo101
  * Problem : Luogu P3167 [CQOI2014]通配符匹配
  * Tags : Hash, Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int BASE = 998244353;
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

int main()
{
	File(code);

	std :: string Str;
	std :: cin >> Str;
	int LenA = Str.size();
	Str += '?';

	Pow[0] = 1;
	for (int i = 1; i < Max_N; i++) Pow[i] = Pow[i - 1] * BASE;
	HashA[0] = Str[0];
	for (int i = 1; i < LenA; i++) HashA[i] = HashA[i - 1] * BASE + Str[i];
	for (int i = 0; i < LenA; i++) {
		if (!(Str[i] == '*' || Str[i] == '?')) continue;
		Pos[Cnt++] = i;
	}

	int n = gi;
	while (n--) {
		memset(Dp, 0, sizeof(Dp));
		std :: string Tmp;
		std :: cin >> Tmp;
		Tmp += "!";
		int LenB = Tmp.size();
		Dp[0][0] = 1; HashB[0] = Tmp[0];
		for (int i = 1; i < LenB; i++) HashB[i] = HashB[i - 1] * BASE + Tmp[i];
		for (int i = 0; i < Cnt; i++) {

		}

	}

	return 0;
}
