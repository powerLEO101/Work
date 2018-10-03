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
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int a[_], Len, Tag[_];
std::vector<int> Num[_];

void Update(int x)
{
	Num[x].clear();
	for (int i = Belong[x] * Len; i < Belong[x + 1] * Len; i++)
		Num[x].push_back(Num[i]);
	std::sort(Num[x].begin(), Num[x].end());
}
void Modify(int l, int r, int Value)
{
	for (int i = Belong[l] * Len; i < (Belong[l] + 1) * Len && i <= r; i++) a[i] += Value;
	Update(Belong[l]);

	if (Belong[l] != Belong[r]) {
		for (int i = Belong[r] * Len; i <= r; i++) a[i] += Value;
		Update(Belong[r]);
	}

	for (int i = Belong[l] + 1; i < Belong[r]; i++) Tag[Belong[i]] += Value;
}
int Query(int l, int r, int Value)
{
	int Ans = 0;

	for (int i = Belong[l] * Len; i < (Belong[l] + 1) * Len && i <= r; i++) 
		Ans += (a[i] + Tag[Belong[i]]) <= Value;

	if (Belong[l] != Belong[r]) {
		for (int i = Belong[r] * Len; i <= r; i++) 
			Ans += (a[i] + Tag[Belong[i]]) <= Value;
	}

	for (int i = Belong[l] + 1; i < Belong[r]; i++)
		Ans += std::lower_bound(Num[i].begin(), Num[i].end(), Value - Tag[i]) - Num[i].begin();
	
	return Ans;
}

int main()
{
	File(code);

	int n = gi;
	Len = sqrt(n) / 2;
	for (int i = 0; i < n; i++) a[i] = gi, Belong[i] = i / Len, Num[Belong[i]].push_back(a[i]);

	for (int i = 0; i < n; i++) {
		int opt = gi, l = gi, r = gi, c = gi;
		if (opt == 0) {
			Modify(l, r, c);
		} else {
			printf("%d\n", Query(l, r, c));
		}
	}

	return 0;
}
