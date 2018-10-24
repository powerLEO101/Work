/**************************
  * Writer : Leo101
  * Problem : LOJ #10163. 「一本通 5.3 例 1」Amount of Degrees
  * Tags : Digital Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100
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

int k, b;
int Dp[_][_], Num[_];

int Get_ans(int Limit)
{
	int Len = 0;
	while (Limit != 0) {
		Num[Len++] = Limit % b;
		Limit /= b;
	}
	int Ans = 0, Count = 0;
	for (int i = Len - 1; i >= 0; i--) {
		if (Num[i] == 1) {
			Ans += Dp[i][k - Count], Count++;
			if (Count == k) {
				return Ans + 1;
			}
		} else if (Num[i] > 1) {
			Ans += Dp[i + 1][k - Count];
			return Ans;
		}
	}
	return Ans;
}

int main()
{
	File(code);

	int l = gi, r = gi;
	k = gi, b = gi;
	
	int Temp_r = r, i = 1;
	Dp[0][0] = 1;
	while (Temp_r != 0) {
		Dp[i][0] = 1;
		for (int j = 1; j <= i; j++) Dp[i][j] = Dp[i - 1][j] + Dp[i - 1][j - 1];
		Temp_r /= b; i++;
	}

	printf("%d", Get_ans(r) - Get_ans(l - 1));

	return 0;
}
