/**************************
  * Writer : Leo101
  * Problem : Luogu P1659 [国家集训队]拉拉队排练
  * Tags : Manacher, Q_pow
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()

typedef long long LL;
#define int LL

const int Max_N = 2e7, Mod = 19930726;
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

char Str[Max_N];
int p[Max_N], Cnt[Max_N];

void Manacher(int Len)
{
	Str[0] = '$';
	int Pos = 0, Max_P = 0;
	for (int i = 1; i <= Len; i++) {
		if (i < Max_P) p[i] = std :: min(Max_P - i, p[2 * Pos - i]);
		else p[i] = 1;
		while (Str[i + p[i]] == Str[i - p[i]]) p[i]++;
		if (i + p[i] > Max_P) {
			Max_P = i + p[i];
			Pos = i;
		}
		++Cnt[p[i] * 2 - 1];
	}
}

int Q_pow(int x, int y)
{
	long long Ans = 1, Base = x;
	while (y != 0) {
		if ((y & 1) == 1) Ans = (Ans * Base) % Mod;
		Base = (Base * Base) % Mod;
		y >>= 1;
	}

	return Ans;
}

signed main()
{
	File(code);

	int Len = gi;
	long long k = gi;
	scanf("%s", Str + 1);

	Manacher(Len);

	long long Ans = 1, Sum = 0;

	for (int i = Len - (1 - (Len % 2)); i >= 1 && k > 0; i -= 2) {
		Sum += Cnt[i];
		Ans = (Ans * Q_pow(i, std :: min(k, Sum))) % Mod,
		k -= Sum;
	}

	printf("%lld", k > 0 ? -1ll : Ans);

	return 0;
}
