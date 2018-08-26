#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1000010
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

int Q[_], l[_], r[_];

int main()
{
	File(code);
	int n = gi, Left = 1, Right = 0, Ans = 1;
	for (int i = 1; i <= n; i++) {
		l[i] = gi, r[i] = gi;
		while (Left <= Right && l[Q[Left]] > r[i]) Left++;
		while (Left <= Right && l[Q[Right]] <= l[i]) Right--;
		Q[++Right] = i;
		Ans = std::max(Ans, i - Q[Left - 1]);
	}
	printf("%d", Ans);
	return 0;
}
