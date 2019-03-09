/**************************
  * Writer : Leo101
  * Problem : P2444 [POI2000]病毒
  * Tags : AC自动机
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 10001;
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

int Trie[Max_N][2], Shift[Max_N], Tot = 1;
bool Val[Max_N], Vis[Max_N];
void Insert(std :: string Str)
{
	int Len = Str.size(), Root = 0;
	for (int i = 0; i < Len; i++) {
		int Now = Str[i] - '0';
		if (Trie[Root][Now] == 0) Trie[Root][Now] = Tot++;
		Root = Trie[Root][Now];
	}
	Val[Root] = true;
}
void Get_Shift()
{
	std :: queue<int> Q;
	if (Trie[0][0] != 0) Q.push(Trie[0][0]);
	if (Trie[0][1] != 0) Q.push(Trie[0][1]);

	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		for (int i = 0; i <= 1; i++) {
			if (Trie[Now][i] != 0) Shift[Trie[Now][i]] = Trie[Shift[Now]][i],
					       Q.push(Trie[Now][i]);
			else Trie[Now][i] = Trie[Shift[Now]][i];
		}
	}
}
void Dfs(int Now = 0)
{
	if (Val[Now] == true) return ;
	if (Vis[Now] == true) {
		printf("TAK");
		exit(0);
	}
	Vis[Now] = true;
	for (int i = 0; i <= 1; i++) {
		int To = Trie[Now][i];
		Dfs(To);
	}
}

int main()
{
	File(code);

	int n = gi;
	std :: string Str;
	for (int i = 0; i < n; i++) {
		std :: cin >> Str;
		Insert(Str);
	}

	Get_Shift();
	Dfs();

	printf("NIE");

	return 0;
}
