/**************************
  * Writer : Leo101
  * Problem : LOJ #10169. 「一本通 5.3 练习 4」数字计数
  * Tags : Digital Dp
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

int Answer[10];
bool Vis[_];

void Dfs(int Now, bool Flag)
{
	if (Flag == false && Vis[Now] == true) {
		for (int i = 0; i < 10; i++) Answer[i] += Dp[Now][i];
		return ;
	}
	if (Now == -1) {
		
	}

	int Lim = Flag == false ? 9 : Num[Now];
	for (int i = 0; i <= Lim; i++) {
		
	}
}

void Get_ans(int Lim) 
{
	memset(Num, 0, sizeof(Num));
	memset(Dp, -1, sizeof(Dp));
	
	int Len = 0;
	while (Lim != 0) {
		Num[Len++] = Lim % 10;
		Lim /= 10;
	}
}

int main()
{
	File(code);

	int l = gi, r = gi;

	return 0;
}
