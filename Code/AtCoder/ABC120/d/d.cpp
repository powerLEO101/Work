/**************************
  * Writer : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 2e5, Max_M = 3e5;
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

int From[Max_M], To[Max_M];

int Father[Max_N], Value[Max_N];
int Get_father(int u)
{ return Father[u] == u ? u : Father[u] = Get_father(Father[u]); }

long long Ans[Max_M];

int main()
{
	File(d);

	int n = gi, m = gi;
	for (int i = 0; i < m; i++)
		From[i] = gi, To[i] = gi;

	for (int i = 0; i < n; i++) Father[i] = i, Value[i] = 1;

	Ans[m] = (1ll * (n - 1) * n) / 2;
	for (int i = m - 1; i >= 0; i--) {
		int u = From[i], v = To[i], w = Value[i];
		int Fa_u = Get_father(u), Fa_v = Get_father(v);
		Ans[i] = Ans[i + 1];
		if (Fa_u == Fa_v) continue;
		Ans[i] -= 1ll * Value[Fa_u] * Value[Fa_v];
		Father[Fa_u] = Fa_v;
		Value[Fa_v] += Value[Fa_u];
	}

	for (int i = 1; i <= m; i++) printf("%lld\n", Ans[i]);

	return 0;
}
