#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1000005
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

long long A[_], B[_];

long long ABS(long long u) {return u < 0 ? -u : u;}

int main()
{
	File(ntt);
	int n = gi, m = gi;
	long long P = gi;
	for (int i = 0; i < n; i++)
		A[i] = gi;
	for (int i = 0; i < m; i++)
		B[i] = gi;
	long long Ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			Ans += sqrt(ABS(A[i] - B[j]));
			Ans %= P;
		}
	std::cout<<Ans;
	return 0;
}
