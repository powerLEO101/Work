#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 20000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, m, Num[_];

void CASE1()
{
	for (int i = 0; i < n; i++) Num[i] = gi;
	for (int x = 0; x < m; x++) {
		int l = gi - 1, r = gi - 1, p = gi, v = gi;
		int Ans = 0;
		for (int i = l; i <= r; i++) 
			if (Num[i] % p == v) Ans++;
		printf("%d\n", Ans);
	}
}

std::vector<int> T[200000];

int main()
{
	File(light);
	n = gi, m = gi;
	if (n <= 10000 && m <= 10000) {
		CASE1();
		return 0;
	}
	for (int i = 0; i < n; i++) Num[i] = gi;
	int l = gi - 1, r = gi - 1, p = gi, v = gi;
	for (int i = 0; i < n; i++) T[Num[i] % p].push_back(i);
	int Len = T[v].size(), Ans = 0;
	for (int i = 0; i < Len; i++) {
		if (T[v][i] > r) break;
		if (T[v][i] < l) continue;
		Ans++;
	}
	printf("%d\n", Ans);
	for (int x = 1; x < m; x++) {
		int l = gi - 1, r = gi - 1, p = gi, v = gi;
		Len = T[v].size(), Ans = 0;
		for (int i = 0; i < Len; i++) {
			if (T[v][i] > r) break;
			if (T[v][i] < l) continue;
			Ans++;
		}
		printf("%d\n", Ans);
	}
	return 0;
}
