/**************************
  * Writer : Leo101
  * Problem : LOJ #10172. 「一本通 5.4 练习 1」涂抹果酱
  * Tags : State Compress Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define Mod 1000000
const int MaxN = 20000, MaxVal = 729;
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

bool Ok(int Lim, int m)
{
	int Pre = -1;
	for (int i = 0; i < m; i++) {
		if (Lim % 3 == Pre) return false;
		Pre = Lim % 3;
		Lim /= 3;
	}
	return true;
}

bool Judge(int a, int b, int m)
{
	for (int i = 0; i < m; i++) {
		if (a % 3 == b % 3) return false;
		a /= 3; b /= 3;
	}
	return true;
}
long long Dp[MaxN][MaxVal];
int Num[MaxVal], Len;
int Get_ans(int l, int Pre, int m)
{
	memset(Dp, 0, sizeof(Dp));
	Dp[0][Pre] = 1;
	for (int i = 1; i <= l; i++) 
		for (int j = 0; j < Len; j++) {
			int x = Num[j];
			for (int k = 0; k < Len; k++) {
				int y = Num[k];
				if (Judge(x, y, m) == false) continue;
				Dp[i][x] = (Dp[i][x] + Dp[i - 1][y]) % Mod;
			}
		}
	long long Ret = 0;
	for (int i = 0; i < Len; i++) Ret = (Ret + Dp[l][Num[i]]) % Mod;
	return Ret;
}

int main()
{
	File(code);

	int n = gi, m = gi, k = gi - 1, Status = 0;
	for (int i = 0; i < m; i++) Status = Status * 3 + gi - 1;
	
	int Lim = 1;
	for (int i = 0; i < m; i++) Lim *= 3;
	for (int i = 0; i < Lim; i++) {
		if (Ok(i, m) == false) continue;
		Num[Len++] = i;
	}

	printf("%d", (1ll * Get_ans(k, Status, m) * Get_ans(n - k - 1, Status, m)) % Mod);

	return 0;
}
