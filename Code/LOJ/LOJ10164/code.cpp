/**************************
  * Writer : Leo101
  * Problem : #10164. 「一本通 5.3 例 2」数字游戏
  * Tags : Digital Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 101
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

int Dp[_][_], Num[_];

int Get_ans(int Limit)
{
	int Len = 0;
	while (Limit != 0) {
		Num[Len++] = Limit % 10;
		Limit /= 10;
	}
	Num[Len] = 0;
	int Ans = 0;
	for (int i = 0; i < Len - 1; i++)
		for (int j = 0; j < 10; j++) 
			Ans += Dp[i][j];
	bool Flag = false;
	for (int i = Len - 1; i >= 0; i--) {
		if (i != Len - 1 && Num[i] < Num[i + 1]) {
			Flag = true;
			break;
		}
		for (int j = Num[i + 1]; j < Num[i]; j++) Ans += Dp[i][j];
	}
	if (Flag == false) Ans++;
	return Ans;
}

int main()
{
	File(code);

	for (int i = 0; i < 10; i++) Dp[0][i] = 1;
	for (int i = 1; i < 31; i++)
		for (int j = 1; j < 10; j++)
			for (int k = j; k < 10; k++)
				Dp[i][j] += Dp[i - 1][k];

	int l, r;
	while (scanf("%d%d",& l,& r) == 2) {
		printf("%d\n", Get_ans(r) - Get_ans(l - 1));
	}

	return 0;
}
