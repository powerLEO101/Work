#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define MOD 1004535809
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

long long ksm(int a, int k)
{
	long long Temp = a, Ans = 1;
	while (k != 0) {
		if (k & 1 == 1) Ans = (Ans * Temp) % MOD;
		Temp = (Temp * Temp) % MOD;
		k >>= 1;
	}
	return Ans;
}

int main()
{
	File(matrix);
	int n = gi, k = gi, a = gi;
	printf("%lld", ksm(a, k));
	return 0;
}
