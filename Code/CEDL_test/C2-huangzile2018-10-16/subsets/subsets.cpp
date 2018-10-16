/***************************
  * Writer : Leo101
  * Problem : Test10-16 subsets
  * Tags : Dfs
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1001
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, Num[_], Sum[_], Ans;
bool Vis[1048576 << 1];
void Dfs(int Now = 0, int Sumx = 0, int Sumy = 0, int Value = 0)
{
	if (Sumx + Sum[Now] < Sumy || Sumy + Sum[Now] < Sumx) 
		return ;
	if (Sumx + Sum[Now] == Sumy || Sumy + Sum[Now] == Sumx) {
		Value |= (((1 << n) - 1) ^ ((1 << Now) - 1));
		if (Vis[Value] == true || Value == 0) return ;
		Vis[Value] = true;
		Ans++;
		return ;
	}
	if (Now == n) {
		if (Vis[Value] == true || Value == 0) return ;
		Ans += (Sumx == Sumy);
		return ;
	}
	
	if (Sumx != Sumy) Dfs(Now + 1, Sumx + Num[Now], Sumy, Value | (1 << Now));
	Dfs(Now + 1, Sumx, Sumy + Num[Now], Value | (1 << Now));
	Dfs(Now + 1, Sumx, Sumy, Value);
}

int main()
{
	File(subsets);

	n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi; 
	for (int i = n; i >= 0; i--) Sum[i] =  Sum[i + 1] + Num[i];
	
	Dfs();

	std::cout << Ans;

	return 0;
}
