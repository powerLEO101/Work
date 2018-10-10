/**************************
 * Writer : Leo101
 * Problem : BZOJ 1306: [CQOI2009]match循环赛
 * Tags : Deep First Search
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _ 11
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int n, Ans, f[4] = {3, 1}, s, m;
int Num[_], Value[_];

void Dfs(register int From, register int To)
{
	if (Value[From] > Num[From]) return ;
	if (Value[From] + (3 * (n - To)) < Num[From]) return;
	if (From == n - 1) {
		Ans++;
		return ;
	}
	if (To == n - 1) {
		register int Need = Num[From] - Value[From];
		if (Need == 2) return ;
		Value[To] += f[Need];
		if (Value[To] <= Num[To]) Dfs(From + 1, From + 2);
		Value[To] -= f[Need];
	} else {
		Value[From] += 3; if (Value[From] <= Num[From]) Dfs(From, To + 1); Value[From] -= 3;
		Value[To] += 3; if (Value[To] <= Num[To]) Dfs(From , To + 1); Value[To] -= 3;
		Value[From]++; Value[To]++;
		if (Value[From] <= Num[From] && Value[To] <= Num[To])
			Dfs(From, To + 1);
		Value[From]--; Value[To]--;
	}
}

int main()
{
	n = gi;
	for (register int i = 0; i < n; i++) Num[i] = gi;

	Dfs(0, 1);
	printf("%d", Ans);

	return 0;
}

