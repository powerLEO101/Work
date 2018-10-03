/**************************
  * Writer : Leo101
  * Problem : LOJ #6277. 数列分块入门 1
  * Tags : 分块
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 200000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Num[_], Tag[_], Belong[_], Len;

void Modify(int l, int r, int Value)
{
	for (int i = l; i < (Belong[l] + 1) * Len && i <= r; i++) 
		Num[i] += Value;

	if (Belong[r] != Belong[l]) {
		for (int i = Belong[r] * Len; i <= r; i++) 
			Num[i] += Value;
	}

	for (int i = Belong[l] + 1; i <= Belong[r] - 1; i++) Tag[i] += Value;
}

int main()
{
	File(code);
	
	int n = gi;
	Len = sqrt(n);
	for (int i = 0; i < n; i++) Num[i] = gi;
	for (int i = 0; i < n; i++) Belong[i] = i / Len;
	
	for (int i = 0; i < n; i++) {
		int opt = gi, l = gi - 1, r = gi - 1, c = gi;

		if (opt == 0) {
			Modify(l, r, c);
		} else {
			printf("%d\n", Num[r] + Tag[Belong[r]]);
		}
	}

	return 0;
}
