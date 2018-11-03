/**************************
  * Writer : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MaxN = 20, MaxVal = 2048, MaxSum = 600;
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

int Num[MaxVal], Cnt, Sum[MaxVal];
long long Dp[MaxN][MaxVal][MaxSum];

int Get_Sum(int Val)
{
	int Ret = 0;
	while (Val != 0) Ret += Val & 1, Val >>= 1;
	return Sum[Cnt] = Ret;
}

int main()
{
	File(code);

	int n = gi, m = gi;
	for (int i = 0; i < (1 << n); i++)
		if ((i & (i << 1)) == 0) Dp[0][Cnt][Get_Sum(i)] = 1, Num[Cnt++] = i;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < Cnt; j++) {
			int x = Num[j];
			for (int k = 0; k < Cnt; k++){
				int y = Num[k];
				if ((x & y) || (x & (y << 1)) || (x & (y >> 1))) continue;
				for (int l = 0; l <= m; l++)
					Dp[i][j][l + Sum[j]] += Dp[i - 1][k][l];
			}
		}
	}

	long long Ans = 0;
	for (int i = 0; i < Cnt; i++)
		Ans += Dp[n - 1][i][m];
	printf("%lld", Ans);

	return 0;
}
