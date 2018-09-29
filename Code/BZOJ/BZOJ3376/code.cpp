/**************************
  * Writer : Leo101
  * Problem : BZOJ #3376. [Usaco2004 Open]Cube Stacking 方块游戏
  * Tags : 带权并查集
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Father[_], Value[_], Sum[_];
void init() {for (int i = 0; i < _; i++) Father[i] = i, Sum[i] = 1;}
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
	
	init();

	int n = gi;
	for (int i = 0; i < n; i++) {
		char ch = getchar();
		if (ch == 'M') {
			int x = Get_father(gi), y = Get_father(gi);
			if (x == y) continue;
			Father[x] = y;
			Value[x] = Sum[y];
			Sum[y] += Sum[x]; Sum[x] = 0;
		} else {
			int x = gi;
			Get_father(x);
			printf("%d\n", Value[x]);
		}
	}

	return 0;
}
