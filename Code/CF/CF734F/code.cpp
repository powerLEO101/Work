/**************************
  * Author : Leo101
  * Problem : CF734F Anton and School
  * Tags : 贪心, 构造
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
typedef unsigned long long LL;
#define int LL
const int MAXN = 2e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int numA[MAXN], numB[MAXN], numC[MAXN], count[64];

bool check(int n)
{
	// get sum
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 64; j++) 
			count[j] += (numA[i] >> j) & 1;

	// operation &
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < 64; j++) {
			if (((numA[i] >> j) & 1) == 0) continue;
			temp += count[j] << j;
		}
		if (temp != numB[i]) return false;
	}

	// operation |
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j < 64; j++) {
			if (((numA[i] >> j) & 1) == 1) {
				temp += n << j;
			} else {
				temp += count[j] << j;
			}
		}
		if (temp != numC[i]) return false;
	}

	return true;
}

signed main()
{
	_FILE(code);

	int n = gi;
	for (int i = 0; i < n; i++) numB[i] = gi;
	for (int i = 0; i < n; i++) numC[i] = gi;

	int sum = 0;
	for (int i = 0; i < n; i++) 
		sum += numB[i] + numC[i];
	sum /= 2 * n;

	for (int i = 0; i < n; i++) 
		numA[i] = ((numB[i] + numC[i]) - sum) / n;

	if (check(n) == false) {
		printf("-1");
		return 0;
	}

	for (int i = 0; i < n; i++) std :: cout << numA[i] << " ";

	return 0;
}
