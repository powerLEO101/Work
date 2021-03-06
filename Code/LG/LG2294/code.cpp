/**************************
  * Writer : Leo101
  * Problem : Luogu 2294 [HNOI2005]狡猾的商人
  * Tags : 带权并查集
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100001
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Father[_], Value[_];
int Get_father(int u)
{
	if (Father[u] == u) return u;
	int Temp = Get_father(Father[u]);
	Value[u] += Value[Father[u]];
	Father[u] = Temp;
	return Temp;
}

int main()
{
	File(code);
	int T = gi;
	while (T--) {
		for (int i = 0; i < _ ; i++) Father[i] = i, Value[i] = 0;
		int n = gi, m = gi;
		bool Flag = false;
		for (int i = 0; i < m; i++) {
			int From = gi - 1, To = gi, Val = gi;
			if (Flag == true) continue;
			int x = Get_father(From), y = Get_father(To);
			if (x == y) {
				if (Value[To] - Value[From] != Val)
					Flag = true;
			} else {
				Father[y] = x;
				Value[y] = Value[From] + Val - Value[To];
			}
		}
		if (Flag == false) printf("true");
		else printf("false");
		printf("\n");
	}
	return 0;
}
