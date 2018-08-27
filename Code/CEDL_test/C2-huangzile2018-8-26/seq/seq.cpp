#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 500010
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

int Num[_];
bool Map[_];

int main()
{
	File(seq);
	int n = gi, m = gi;
	for (int i = 1; i <= n; i++) Num[i] = gi;
	for (int x = 0; x < m; x++) {
		int l = gi, r = gi, Mod = gi;
		memset(Map, 0, sizeof(Map));
		int Sum = 0, Ans = 0x3f3f3f3f;
		Map[0] = true;
		for (int i = l; i <= r; i++) {
			Sum = (Sum + Num[i]) % Mod;
			for (int j = Sum; j >= 0; j--)
				if (Map[j] == true) {
					Ans = std::min(Ans, Sum - j);
					break;
				}
			Map[Sum] = true;
			if (Ans == 0) break;
		}
		printf("%d\n", Ans);
	}
	return 0;
}
