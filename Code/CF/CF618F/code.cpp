/**************************
  * Author : Leo101
  * Problem : CF618F Double Knapsack
  * Tags : 构造
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int main()
{
	_FILE(code);

	int n = gi;
	bool flag = false;
	for (int i = 1; i <= n; i++) 
		num1[i] = gi, sum1[i] = sum1[i - 1] + num1[i];
	for (int i = 1; i <= n; i++)
		num2[i] = gi, sum2[i] = sum2[i - 1] + num2[i];

	if (sum1[n] < sum2[n]) {
		std :: swap(num1, num2);
		std :: swap(sum1, sum2);
		flag = true;
	}

	int j = 0;
	for (int i = 0; i < n; i++) {
		while (sum2[j] < sum2[i])
	}

	return 0;
}
