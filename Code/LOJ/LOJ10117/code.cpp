#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100005
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

int C[_], n, m;
int Lowbit(int u) {return u & (-u);}
void Add(int Index, int Value)
{
	while (Index <= n) {
		C[Index] += Value;
		Index += Lowbit(Index);
	}
}
int Sum(int Index)
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
			int l = gi,r = gi;
			Add(l, 1);
			Add(r + 1, 1);
		} else {
			int Index = gi;
			printf("%d\n", Sum(Index) % 2);
		}
	}
	return 0;
}
