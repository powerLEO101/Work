/***************************
  * Writer : Leo101
  * Problem : Test10-16 T2 swap
  * Tags : 
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1001
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Num[_], q[_], Temp[_], n;
int Judge()
{
	for (int i = 0; i < n; i++) Temp[i] = i;
	for (int i = 0; i < n - 1; i++)
		std::swap(Temp[q[i]], Temp[q[i] + 1]);
	for (int i = 0; i < n; i++)
		if (Temp[i] != Num[i]) return false;
	return true;
}

int main()
{
	File(swap);

	n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;

	int Ans = 0;
	for (int i = 0; i < n - 1; i++) q[i] = i;
	do {
		Ans += Judge();
	}
	while (std::next_permutation(q, q + n - 1));

	printf("%d", Ans);

	return 0;
}

