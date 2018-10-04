/**************************
  * Writer : Leo101
  * Problem : BZOJ2563: 阿狸和桃子的游戏
  * Tags : 贪心
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 20000
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

int Value[_];

int main()
{
	File(code);
	
	int n = gi, m = gi;
	for (int i = 0; i < n; i++) Value[i] = gi * 2;
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1, Val = gi;
		Value[From] += Val;
		Value[To] += Val;
	}

	std::sort(Value, Value + n);
	int Ans = 0;
	for (int i = 0; i < n; i += 2) Ans -= Value[i];
	for (int i = 1; i < n; i += 2) Ans += Value[i];

	printf("%d", Ans / 2);

	return 0;
}
