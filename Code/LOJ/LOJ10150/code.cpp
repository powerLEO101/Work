/**************************
  * Writer : Leo101
  * Problem : LOJ #10150. 「一本通 5.1 练习 1」括号配对
  * Tags : Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
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

int Dp[_][_];

int main()
{
	File(code);

	std::string Str;
	std::cin >> Str;
	int Len = Str.size();

	for (int i = Len - 2; i >= 0; i--) {
		for (int j = i + 1; j < Len; j++) {
			for (int k = i; k < j; k++)
				Dp[i][j] = std::max(Dp[i][j], Dp[i][k] + Dp[k + 1][j]);
			if ((Str[i] == '(' && Str[j] == ')') || (Str[i] == '[' && Str[j] == ']')) Dp[i][j] = std::max(Dp[i][j], Dp[i + 1][j - 1] + 2);
		}
	}

	printf("%d", Len - Dp[0][Len - 1]);

	return 0;
}
