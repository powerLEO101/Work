#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 200005
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

int Num[_], Log[_], Maximum[_][21], Minimum[_][21];

int main()
{
	File(code);
	int n = gi, m = gi;
	for (int i = 0; i < n; i++)
		Num[i] = gi;
	Minimum[0][0] = Maximum[0][0] = Num[0];
	Log[0] = -1;
	for (int i = 1; i <= n; i++) {
		Minimum[i][0] = Maximum[i][0] = Num[i];
		Log[i] = Log[i >> 1] + 1;
	}
	for (int j = 1; j <= 20; j++)
		for (int i = 0; i + (1 << (j - 1)) < n; i++) {
			Minimum[i][j] = std::min(Minimum[i][j - 1],\
					Minimum[i + (1 << (j - 1))][j-1]);
			Maximum[i][j] = std::max(Maximum[i][j - 1],\
					Maximum[i + (1 << (j - 1))][j-1]);
		}
	for (int i = 0; i + m - 1 < n; i++) {
		int r = i + m - 1, l = i;
		int Temp = Log[r - l + 1];
		printf("%d %d\n",\
			std::max(Maximum[i][Temp], Maximum[r - (1 << Temp) + 1][Temp]),\
			std::min(Minimum[i][Temp], Minimum[r - (1 << Temp) + 1][Temp]));
	}
	return 0;
}
