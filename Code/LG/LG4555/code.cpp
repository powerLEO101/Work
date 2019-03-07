/**************************
  * Writer : Leo101
  * Problem : Luogu P4555 [国家集训队]最长双回文串
  * Tags : Manacher
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 3e5;
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

char Str[Max_N], Tmp[Max_N];
int L[Max_N], R[Max_N], p[Max_N];

int main()
{
	File(code);

	scanf("%s", Tmp + 1);
	int Len = strlen(Tmp + 1), n = 0;
	Str[++n] = '#'; Str[0] = ' ';
	for (int i = 1; i <= Len; i++) Str[++n] = Tmp[i], Str[++n] = '#';

	int Pos = 0, Max_P = 0;
	for (int i = 1; i <= n; i++) {
		if (i <= Max_P) p[i] = std::min(Max_P - i + 1, p[Pos * 2 - i]);
		else p[i] = 1;
		while (Str[i + p[i]] == Str[i - p[i]]) p[i]++;
		if (i + p[i] - 1 > Max_P) {
			Max_P = i + p[i] - 1;
			Pos = i;
		}
		L[i + p[i] - 2] = std :: max(L[i + p[i] - 2], p[i] - 1);
		R[i - p[i] + 2] = std :: max(R[i - p[i] + 2], p[i] - 1);
	}

	for (int i = 2; i <= Len * 2; i += 2) R[i] = std :: max(R[i], R[i - 2] - 2);
	for (int i = Len * 2; i >= 2; i -= 2) L[i] = std :: max(L[i], L[i + 2] - 2);

	int Ans = 0;
	for (int i = 2; i < Len * 2; i += 2) Ans = std :: max(Ans, L[i] + R[i + 2]);

	printf("%d", Ans);

	return 0;
}
