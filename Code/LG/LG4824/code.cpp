/**************************
  * Writer : Leo101
  * Problem : Luogu P4824 [USACO15FEB]Censoring (Silver) 审查(银)
  * Tags : kmp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 2e6;
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

int Stack[Max_N], Shift[Max_N], Top;
char Ans[Max_N];

void Get_Shift(std :: string S)
{
	int j = -1, Len = S.size();
	Shift[0] = -1;
	for (int i = 1; i < Len; i++) {
		while (j != -1 && S[i] != S[j + 1]) j = Shift[j];
		if (S[i] == S[j + 1]) j++;
		Shift[i] = j;
	}
}

int main()
{
	File(code);

	std :: string S, T;
	std :: cin >> S >> T;

	Get_Shift(T);

	int j = -1; Top = 1;
	Stack[0] = -1;
	for (int i = 0; i < S.size(); i++) {
		while (j != -1 && T[j + 1] != S[i]) j = Shift[j];
		if (T[j + 1] == S[i]) j++;
		Stack[Top] = j; Ans[Top++] = S[i];
		if (j == T.size() - 1) {
			Top -= T.size();
			j = Stack[Top - 1];
		}
	}

	for (int i = 1; i < Top; i++) printf("%c", Ans[i]);

	return 0;
}
