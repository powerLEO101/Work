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
typedef long long LL;
#define int LL
const int MAXN = 1000100;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int A[MAXN], B[MAXN], num1[MAXN], num2[MAXN];
bool vis[MAXN];

signed main()
{
	_FILE(code);

	int n = gi;
	bool flag = false;
	for (int i = 1; i <= n; i++) 
		num1[i] = gi + num1[i - 1];
	for (int i = 1; i <= n; i++)
		num2[i] = gi + num2[i - 1];

	if (num1[n] > num2[n]) {
		std :: swap(num1, num2);
		flag = true;
	}

	int j = 0;
	for (int i = 0; i <= n; i++) {
		while (j < n && num2[j + 1] <= num1[i]) j++;
		int value = num1[i] - num2[j];
		if (vis[value] == true) {
			if (flag == true) {
				B[value]++; A[value]++;
				printf("%lld\n", j - B[value] + 1);
				for (int x = B[value]; x <= j; x++) printf("%lld ", x);
				printf("\n%lld\n", i - A[value] + 1);
				for (int x = A[value]; x <= i; x++) printf("%lld ", x);
			} else {
				B[value]++; A[value]++;
				printf("%lld\n", i - A[value] + 1);
				for (int x = A[value]; x <= i; x++) printf("%lld ", x);
				printf("\n%lld\n", j - B[value] + 1);
				for (int x = B[value]; x <= j; x++) printf("%lld ", x);
			}
			return 0;
		} else {
			vis[value] = true;
			A[value] = i;
			B[value] = j;
		}
	}

	return 0;
}
