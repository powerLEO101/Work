/**************************
  * Writer : Leo101
  * Problem : LOJ #10158. 「一本通 5.2 练习 1」加分二叉树
  * Tags : Intervals Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 300
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

long long Dp[_][_];
int Root[_][_], Num[_];

void Print_Tree(int l, int r)
{
	if (l > r) return ;
	printf("%d ", Root[l][r] + 1);
	Print_Tree(l, Root[l][r] - 1);
	Print_Tree(Root[l][r] + 1, r);
}

int main()
{
	File(code);

	int n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			Dp[i][j] = 1;
	for (int i = 0; i < n; i++) Dp[i][i] = Num[i], Root[i][i] = i;
	for (int l = 1; l < n; l++) 
		for (int i = 0; i + l < n; i++) {
			int j = i + l;
			for (int k = i; k <= j; k++) {
				if (k - 1 < 0) {
					if (Dp[k + 1][j] + Num[k] > Dp[i][j]) {
						Dp[i][j] = Dp[k + 1][j] + Num[k];
						Root[i][j] = k;
					}
				} else if (k + 1 >= n) {
					if (Dp[i][k - 1] + Num[k] > Dp[i][j]) {
						Dp[i][j] = Dp[i][k - 1] + Num[k];
						Root[i][j] = k;
					}
				} else if ((Dp[i][k - 1] * Dp[k + 1][j]) + Num[k] > Dp[i][j]) {
					Dp[i][j] = (Dp[i][k - 1] * Dp[k + 1][j]) + Num[k];
					Root[i][j] = k;
				}
			}
		}

	printf("%lld\n", Dp[0][n - 1]);
	Print_Tree(0, n - 1);

	return 0;
}
