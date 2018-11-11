/**************************
  * Writer : Leo101
  * Problem : LOJ #6279. 数列分块入门 3
  * Tags : 分块
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define _ 2000000
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

int Len, a[_], Tags[_], Belong[_], n;
std::set<int> Num[_];

void Modify(int l, int r, int c)
{
	for (int i = l; i < (Belong[l] + 1) * Len && i <= r; i++) {
		Num[Belong[i]].erase(a[i]);
		a[i] += c;
		Num[Belong[i]].insert(a[i]);
	}
	
	if (Belong[l] != Belong[r]) {
		for (int i = Belong[r] * Len; i <= r; i++) {
			Num[Belong[i]].erase(a[i]);
			a[i] += c;
			Num[Belong[i]].insert(a[i]);
		}
	}

	for (int i = Belong[l] + 1; i < Belong[r]; i++) Tags[i] += c;

}

int Query(int l, int r, int c)
{
	int Ans = -1;
	for (int i = l; i < (Belong[l] + 1) * Len && i <= r; i++) {
		if (a[i] + Tags[Belong[l]] >= c) continue;
		Ans = std::max(Ans, a[i] + Tags[Belong[l]]);
	}
	for (int i = Belong[r] * Len; i <= r; i++) {
		if (a[i] + Tags[Belong[r]] >= c) continue;
		Ans = std::max(Ans, a[i] + Tags[Belong[r]]);
	}
	
	for (int i = Belong[l] + 1; i < Belong[r]; i++) {
		auto it = Num[i].lower_bound(c - Tags[i]);
		if (it == Num[i].begin()) continue;
		it--;
		Ans = std::max(Ans, *it + Tags[i]);
	}

	return Ans;
}

int main()
{
	File(code);

	n = gi;
	Len = sqrt(n);
	for (int i = 0; i < n; i++) a[i] = gi, Belong[i] = i / Len, Num[Belong[i]].insert(a[i]);

	for (int i = 0; i < n; i++) {
		int opt = gi, l = gi - 1, r = gi - 1, c = gi;
		if (opt == 0) {
			Modify(l, r, c);
		} else {
			printf("%d\n", Query(l, r, c));
		}
	}

	return 0;
}
