/**************************
  * WrIter : Leo101
  * Problem : Luogu P3805 【模板】manacher算法
  * Tags : Manacher
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 31000001;
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

int p[Max_N];

int main()
{
	File(code);

	std :: string Str, Tmp;
	std :: cin >> Tmp;

	Str = "%";
	for (auto It = Tmp.begin(); It != Tmp.end(); It++) {
		Str += *It;
		Str += "#";
	}
	Str += "%";

	int Len = Str.size(), Max_P = -1, Pos = -1, Ans = 0;
	for (int i = 0; i < Len; i++) {
		if (i < Max_P) p[i] = std :: min(p[2 * Pos - 1], Max_P - i + 1);
		else p[i] = 1;
		while (Str[i - p[i]] == Str[i + p[i]]) p[i]++;
		if (Max_P < p[i]) {
			Max_P = p[i] + i;
			Pos = i;
		}
		Ans = std :: max(Ans, p[i] - 1);
	}

	printf("%d", Ans);

	return 0;
}
