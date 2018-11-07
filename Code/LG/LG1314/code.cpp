/**************************
  * Writer : Leo101
  * Problem : Luogu P1314 聪明的质监员
  * Tags : 二分答案, 前缀和
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF64 0x3f3f3f3f3f3f3f3f
const int MaxN = 400000;
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

class Interval
{
public:
	int l, r;
}Intervals[MaxN];
long long ABS(long long u) {return u < 0 ? -u : u;}

long long Sum[MaxN];
int Sum1[MaxN], w[MaxN], v[MaxN], n, m;
long long Check(int Mid)
{
	for (int i = 1; i <= n; i++)
		Sum[i] = Sum[i - 1] + (v[i] * (w[i] >= Mid)),
		Sum1[i] = Sum1[i - 1] + (w[i] >= Mid);
	
	long long Ret = 0;
	for (int i = 0; i < m; i++) {
		int l = Intervals[i].l, r = Intervals[i].r;
		int Count = Sum1[r] - Sum1[l - 1];
		long long Val = Sum[r] - Sum[l - 1];
		Ret += Val * Count;
	}
	return Ret;
}

int main()
{
	File(code);

	n = gi, m = gi;
	long long S = gi;
	for (int i = 1; i <= n; i++)
		w[i] = gi, v[i] = gi;
	for (int i = 0; i < m; i++) 
		Intervals[i].l = gi,
		Intervals[i].r = gi;
	
	int l = 0, r = 5000000;
	long long Ans = INF64;
	while (l <= r) {
		int Mid = (l + r) / 2;
		long long Val = Check(Mid);
		Ans = std::min(Ans, ABS(Val - S));
		if (Val > S) l = Mid + 1;
		else r = Mid - 1;
	}
	printf("%lld", Ans);

	return 0;
}
