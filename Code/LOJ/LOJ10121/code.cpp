#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
#define _ 20000005
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

int Max[_][21], St[_], f[_], Last[10000005], Log[_];

int Get(int Left, int Right)
{
	if (St[Left] == Left) return Left;
	if (St[Right] < Left) return Right + 1;
	int l = Left, r = Right;
	while (l <= r) {
		int Mid = (l + r) / 2;
		if (St[Mid] < Left)
			l = Mid + 1;
		else 
			r = Mid - 1;
	}
	return l;
}

int RMQ(int Left, int Right)
{
	int log = Log[Right - Left + 1];
	return std::max(Max[Left][log],\
			Max[Right - (1 << log) + 1][log]);
}

int main()
{
	File(code);
	int n = gi, m = gi, M = 1e6 + 5;
	Log[0] = -1;
	for (int i = 1; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	memset(Last, -1, sizeof(Last));
	for (int i = 0; i < n; i++) {
		int x = gi;
		St[i] = std::max(St[std::max(i - 1, 0)], Last[x + M] + 1);
		f[i] = i - St[i] + 1;
		Last[x + M] = i;
	}
	for (int i = 0; i < n; i++)
		Max[i][0] = f[i];
	for (int j = 1; j <= 20; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			Max[i][j] = std::max(Max[i][j - 1],\
					Max[i + (1 << (j - 1))][j - 1]);
	while (m--) {
		int l = gi, r = gi;
		int Mid = Get(l, r), Ans = -INF;
		if (Mid > l) Ans = Mid - l;
		if (Mid <= r) Ans = std::max(Ans, RMQ(Mid, r));
		printf("%d\n", Ans);
	}
	return 0;
}
