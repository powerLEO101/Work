/**************************
  * Writer : Leo101
  * Problem : Luogu P2342 叠积木
  * Tags : dsu
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 5e5;
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

int Father[Max_N], Weight[Max_N], Size[Max_N];
int Get_father(int u) 
{ 
	if (Father[u] == u) return u;
	int Tmp = Father[u];
	Father[u] = Get_father(Father[u]);
	Weight[u] += Weight[Tmp];
	Size[u] = Size[Tmp];
	return Father[u];
}

int ABS(int u) { return u < 0 ? -u : u; }

int main()
{
	File(code);

	for (int i = 0; i < Max_N; i++) Father[i] = i, Weight[i] = 0, Size[i] = 1;

	int T = gi;
	while (T--) {
		char Type;
		std :: cin >> Type;
		if (Type == 'M') {
			int From = gi, To = gi;
			int F_F = Get_father(From), F_T = Get_father(To);
			if (F_F == F_T) continue;
			Weight[F_F] += Size[F_T];
			Size[F_F] += Size[F_T];
			Size[F_T] = Size[F_F];
			Father[F_F] = F_T;
		} else {
			int x = gi;
			Get_father(x);
			printf("%d\n", Weight[x]);
		}
	}

	return 0;
}
