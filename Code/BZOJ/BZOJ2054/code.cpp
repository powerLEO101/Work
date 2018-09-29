/**************************
  * Writer : Leo101
  * Problem : BZOJ #2054 疯狂的馒头
  * Tags : 并查集, 路径压缩
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 5000000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Father[_], Color[_];
int Get_father(int u) {return Father[u] == u ? u : Father[u] = Get_father(Father[u]);}

int main()
{
	File(code);
	
	int n = gi, m = gi, p = gi, q = gi;

	for (int i = 0; i < _; i++) Father[i] = i;

	for (int x = m; x >= 1; x--) {
		int From = (x * p % n + q) % n + 1;
		int To = (x * q % n + p) % n + 1;
		if (From > To) std::swap(From, To);

		for (int i = Get_father(From); i <= To; i = Get_father(i)) {
			Color[i] = x;
			Father[i] = i + 1;
		}
	}

	for (int i = 1; i <= n; i++) printf("%d\n", Color[i]);

	return 0;
}
