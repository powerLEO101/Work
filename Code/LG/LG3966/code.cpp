/**************************
  * Writer : Leo101
  * Problem : Luogu P3966 [TJOI2013]单词
  * Tags : AC自动机
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
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

int Trie[Max_N][26], Val[Max_N], Rt[Max_N], Shift[Max_N], Tot = 1;
std :: vector<int> Edges[Max_N];
void Insert(std :: string Str, int Id)
{
	int Len = Str.size(), Root = 0;
	for (int i = 0; i < Len; i++) {
		int Now = Str[i] - 'a';
		if (Trie[Root][Now] == 0) Trie[Root][Now] = Tot++;
		Root = Trie[Root][Now];
		Val[Root]++;
	}
	Rt[Id] = Root;
}
void Get_Shift()
{
	std :: queue<int> Q;
	for (int i = 0; i < 26; i++) 
		if (Trie[0][i] != 0) {
			Q.push(Trie[0][i]);
			Edges[0].push_back(Trie[0][i]);
		}
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for (int i = 0; i < 26; i++) {
			if (Trie[Now][i] != 0) {
				Shift[Trie[Now][i]] = Trie[Shift[Now]][i];
				Edges[Shift[Trie[Now][i]]].push_back(Trie[Now][i]);
				Q.push(Trie[Now][i]);
			} else {
				Trie[Now][i] = Trie[Shift[Now]][i];
			}
		}
	} 
}
void Dfs(int Now = 0)
{
	for (auto it = Edges[Now].begin(); it != Edges[Now].end(); it++) {
		int To = *it;
		Dfs(To);
		Val[Now] += Val[To];
	}
}

int main()
{
	File(code);

	int n = gi;
	for (int i = 0; i < n; i++) {
		std :: string Str;
		std :: cin >> Str;
		Insert(Str, i);
	}

	Get_Shift();
	Dfs();

	for (int i = 0; i < n; i++)
		printf("%d\n", Val[Rt[i]]);

	return 0;
}
