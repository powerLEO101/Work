#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
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

int Left[500000], Right[500000], n, m;
int Lowbit(int u) {return u & (-u);}
void Add(int Index, int Value, int C[])
{
	while (Index <= n) {
		C[Index] += Value;
		Index += Lowbit(Index);
	}
}
int Sum(int Index, int C[])
{
	int Ans = 0;
	while (Index > 0) {
		Ans += C[Index];
		Index -= Lowbit(Index);
	}
	return Ans;
}

int main()
{
	File(code);
	n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int Mod = gi;
		if (Mod == 1) {
			int l = gi, r = gi;
			Add(l, 1, Left);
			Add(r, 1, Right);
		} else {
			int l = gi, r = gi;
			printf("%d\n", Sum(r, Left) - Sum(l - 1, Right));
		}
	}
	return 0;
}
