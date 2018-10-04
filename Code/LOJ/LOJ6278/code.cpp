/**************************
  * Writer : Leo101
  * Problem : LOJ #6278. 数列分块入门 2
  * Tags : 分块
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 200000
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

long long a[_], Len, Tag[_], Belong[_], n;
std::vector<long long> Num[_];

void Update(int x)
{
	Num[x].clear();
	for (int i = x * Len; i < (x + 1) * Len && i < n; i++)
		Num[x].push_back(a[i]);
	std::sort(Num[x].begin(), Num[x].end());
}
void Modify(int l, int r, long long Value)
{
	for (int i = l; i < (Belong[l] + 1) * Len && i <= r; i++) a[i] += Value;
	Update(Belong[l]);

	if (Belong[l] != Belong[r]) {
		for (int i = Belong[r] * Len; i <= r; i++) a[i] += Value;
		Update(Belong[r]);
	}

	for (int i = Belong[l] + 1; i < Belong[r]; i++) Tag[i] += Value;
}
int Query(int l, int r, long long Value)
{
	int Ans = 0;

	for (int i = l; i < (Belong[l] + 1) * Len && i <= r; i++) 
		Ans += (a[i] + Tag[Belong[l]]) < Value;

	if (Belong[l] != Belong[r]) {
		for (int i = Belong[r] * Len; i <= r; i++) 
			Ans += (a[i] + Tag[Belong[r]]) < Value;
	}

	for (int i = Belong[l] + 1; i < Belong[r]; i++)
		Ans += std::lower_bound(Num[i].begin(), Num[i].end(), 1ll * Value - Tag[i]) - Num[i].begin();
	
	return Ans;
}

int main()
{
	File(code);

	n = gi;
	Len = sqrt(n) / 2;

	for (int i = 0; i < n; i++) a[i] = gi, Belong[i] = i / Len, Num[Belong[i]].push_back(a[i]);

	for (int i = 0; i <= Belong[n - 1]; i++) std::sort(Num[i].begin(), Num[i].end());

	for (int i = 0; i < n; i++) {
		int opt = gi, l = gi - 1, r = gi - 1, c = gi;
		if (opt == 0) {
			Modify(l, r, c);
		} else {
			printf("%d\n", Query(l, r, 1ll * c * c));
		}
	}

	return 0;
}
