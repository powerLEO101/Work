#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 2000005
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

long long C[_], n, m;
int Lowbit(int u) {return u & (-u);}
void Add(int Index,long long Value)
{
	while (Index <= n) {
		C[Index] += Value;
		Index += Lowbit(Index);
	}
}
long long Sum(int Index)
{
	long long Ans = 0;
	while(Index > 0) {
		Ans += C[Index];
		Index -= Lowbit(Index);
	}
	return Ans;
}

int main()
{
	File(code);
	n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		long long Value = gi;
		Add(i + 1, Value);
	}
	for (int i = 0; i < m; i++) {
		int Mod = gi;
		if (Mod == 1) {
			long long Index = gi, Val = gi;
			Add(Index, Val);
		} else {
			long long l = gi, r = gi;
			printf("%lld\n", Sum(r) - Sum(l - 1));
		}
	}
	return 0;
}
