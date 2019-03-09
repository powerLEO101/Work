#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define gi get_int()
const int Max_N = 200001;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Shift[Max_N], Trie[Max_N][130], Val[Max_N], Length[Max_N], Tot = 1;
void Insert(std :: string Str)
{
	int Len = Str.size(), Root = 0;
	for (int i = 0; i < Len; i++) {
		if (Trie[Root][Str[i]] == 0) Trie[Root][Str[i]] = Tot++;
		Root = Trie[Root][Str[i]];
	}
	Val[Root] = true;
	Length[Root] = Len;
}
void Get_Shift()
{
	std :: queue<int> Q;
	for (int i = 'a'; i <= 'z'; i++)
		if (Trie[0][i] != 0) Q.push(Trie[0][i]);
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for (int i = 'a'; i <= 'z'; i++) {
			if (Trie[Now][i] != 0) Shift[Trie[Now][i]] = Trie[Shift[Now]][i],
				Q.push(Trie[Now][i]);
			else Trie[Now][i] = Trie[Shift[Now]][i];
		}
	}
}

int Rt[Max_N];
char Ans[Max_N];
void Get_Ans(std :: string Str)
{
	int Len = Str.size(), Root = 0, Top = 0;
	Rt[Top++] = 0;
	for (int i = 0; i < Len; i++) {
		Root = Trie[Root][Str[i]];
		Rt[Top] = Root;
		Ans[Top++] = Str[i];
		if (Val[Root] == true) {
			Top -= Length[Root];
			Root = Rt[Top - 1];
		}
	}

	for (int i = 1; i < Top; i++) printf("%c", Ans[i]);
}

int main()
{
	std :: string S, p;
	std :: cin >> S;

	int n = gi;
	while (n--) {
		std :: cin >> p;
		Insert(p);
	}

	Get_Shift();
	Get_Ans(S);
	printf("\n");

	return 0;
}

