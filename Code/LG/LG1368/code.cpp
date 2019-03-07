/**************************
  * Writer : Leo101
  * Problem : P1368 工艺
  * Tags : 最小循环表示法
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 700001;
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

int Num[Max_N];

int main()
{
	File(code);

	int n = gi;
	for (int x = 0; x < n; x++) Num[x] = Num[x + n] = gi;
	
	int i = 0, j = 1, k = 0;
	while (i < n && j < n && k < n) {
		if (Num[i + k] == Num[j + k]) k++;
		else if (Num[i + k] > Num[j + k]) i = i + k + 1, k = 0;
		else if (Num[i + k] < Num[j + k]) j = j + k + 1, k = 0;
		if (i == j) j++;
	}

	for (int x = std :: min(i, j); x < std :: min(i, j) + n; x++)
		printf("%d ", Num[x]);

	return 0;
}
