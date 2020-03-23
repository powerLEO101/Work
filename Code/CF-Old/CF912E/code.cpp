/**************************
  * Writer : Leo101
  * Problem : CF912E Prime Gift
  * Tags : Meet in the middle, 分治思想
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, Num[_];
std::vector<long long> Ans1, Ans2;

void Dfs1(int Now, long long Sum)
{
	if (Now >= n) {
		Ans1.push_back(Sum);
		return ;
	}
	for (long long i = 1; 1e18 / i >= Sum; i *= Num[Now])
		Dfs1(Now + 2, Sum * i);
}
void Dfs2(int Now, long long Sum)
{
	if (Now >= n) {
		Ans2.push_back(Sum);
		return ;
	}
	for (long long i = 1; 1e18 / i >= Sum; i *= Num[Now])
		Dfs2(Now + 2, Sum * i);
}

int main()
{
	File(code);
	n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;
	long long K = gi;
	std::sort(Num, Num + n);
	Dfs1(0, 1); Dfs2(1, 1);
	std::sort(Ans1.begin(), Ans1.end()); std::sort(Ans2.begin(), Ans2.end());
	long long l = 0, r = 1e18, Ans = -1;
	while (l <= r) {
		long long Mid = (l + r) / 2, Sum = 0, p1, p2 = Ans2.size() - 1;
		for (p1 = 0; p1 < Ans1.size(); p1++) {
			while (p2 != -1 && Mid / Ans1[p1] < Ans2[p2]) p2--;
			Sum += p2 + 1;
		}
		if (Sum < K) l = Mid + 1;
		else r = Mid - 1, Ans = Mid;
	}
	std::cout << Ans;
	return 0;
}
