/**************************
  * Writer : Leo101
  * Problem : LOJ #10151. 「一本通 5.1 练习 2」分离与合体
  * Tags : Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
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

int Dp[_][_], Pos[_][_], Num[_];

void Print(int l, int r)
{
	std::queue<int> Ql, Qr;
	Ql.push(l); Qr.push(r);
	while (!Ql.empty()) {
		int Nowl = Ql.front(), Nowr = Qr.front();
		Ql.pop(); Qr.pop();
		if (Nowl != Nowr) {
			printf("%d ", Pos[Nowl][Nowr] + 1);
			Ql.push(Nowl);
			Qr.push(Pos[Nowl][Nowr]);
			Ql.push(Pos[Nowl][Nowr] + 1);
			Qr.push(Nowr);
		}
	}
}

int main()
{
	File(code);

	int n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;

	for (int L = 0; L < n; L++) {
		for (int i = 0; i + L < n; i++) {
			int j = i + L;
			for (int k = i; k < j; k++)
				if (Dp[i][j] < Dp[i][k] + Dp[k + 1][j] + (Num[i] + Num[j]) * Num[k]) {
					Dp[i][j] = Dp[i][k] + Dp[k + 1][j] + (Num[i] + Num[j]) * Num[k];
					Pos[i][j] = k;
				}
		}
	}

	printf("%d\n", Dp[0][n - 1]);
	Print(0, n - 1);

	return 0;
}
