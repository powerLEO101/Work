/**************************
  * Writer : Leo101
  * Problem : LOJ #10174. 「一本通 5.4 练习 3」动物园
  * Tags : State Compress Dp
**************************/
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

int main()
{
	File(code);

	int n = gi, c = gi;
	for (int I = 0; I < c; I++) {
		int e = gi, F_Num = gi, L_Num = gi;
		int Fear = 0, Like = 0;
		for (int i = 0; i < F_Num; i++) {
			int x = gi;
			x = ((x - e) % n + n) % n;
			Fear |= (1 << x);
		}
		for (int i = 0; i < L_Num; i++) {
			int x = gi;
			x = ((x - e) % n + n) % n;
			Like |= (1 << x);
		}
		for (int i = e; i < e + 5; i++) {
			if (
		}
	}

	return 0;
}
