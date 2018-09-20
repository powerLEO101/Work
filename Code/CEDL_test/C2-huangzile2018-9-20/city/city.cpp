#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
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

int n, a[_], b[_];
int Ans[_][_];
int Length, Num[_];

void Check()
{
	int Temp = 0;
	for (int i = 0; i < n; i++) 
		for (int j = i + 1; j < n; j++)
			b[Temp++] = a[i] + a[j];
	std::sort(b, b + Temp);
	for (int i = 0; i < Temp; i++) if (Num[i] != b[i]) return;
	for (int i = 0; i < n; i++) Ans[Length][i] = a[i];
	Length++;
}

void Dfs(int Now, int Pre = 1)
{
	if (Now == n) {
		Check();
		return;
	}
	for (int i = Pre; i <= 10; i++) {
		a[Now] = i;
		Dfs(Now + 1, i);
	}
}

int main()
{
	File(city);
	n = gi;
	for (int i = 0; i < n * (n - 1) / 2; i++) Num[i] = gi;
	std::sort(Num, Num + (n * (n - 1) / 2));
	Dfs(0);
	printf("%d\n", Length);
	for (int i = Length - 1; i >= 0; i--) {
		std::sort(Ans[i], Ans[i] + n);
		for (int j = 0; j < n; j++) printf("%d ", Ans[i][j]);
		printf("\n");
	}
	return 0;
}
