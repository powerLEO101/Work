/**************************
  * Writer : Leo101
  * Problem : Luogu P3167 [CQOI2014]通配符匹配
  * Tags : Hash, Dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 3e5;
const unsigned long long BASE = 998244353;
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
int Pos[20], Dp[20][Max_N];
unsigned long long HashA[Max_N], HashB[Max_N], Pow[Max_N];

unsigned long long GetA(int l, int r)
{ return HashA[r] - HashA[l - 1] * Pow[r - l + 1]; }
unsigned long long GetB(int l, int r)
{ return HashB[r] - HashB[l - 1] * Pow[r - l + 1]; }

int main()
{
	File(code);

	scanf("%s", Str + 1);
	int LenA = strlen(Str + 1) + 1;
	Str[LenA] = '?';

	Pow[0] = 1;
	int Tot = 0;
	for (int i = 1; i <= Max_N; i++) Pow[i] = Pow[i - 1] * BASE;
	for (int i = 1; i <= LenA; i++) {
		HashA[i] = HashA[i - 1] * BASE + Str[i];
		if (Str[i] == '*' || Str[i] == '?') Pos[++Tot] = i;
	}

	int n = gi;
	while (n--) {
		memset(Dp, 0, sizeof(Dp));
		scanf("%s", Tmp + 1);
		int LenB = strlen(Tmp + 1) + 1;
		Tmp[LenB] = '$';
		Dp[0][0] = 1; 
		for (int i = 1; i <= LenB; i++) HashB[i] = HashB[i - 1] * BASE + Tmp[i];
		for (int i = 0; i <= Tot; i++) {
			if (Str[Pos[i]] == '*') 
				for (int x = 1; x <= LenB; x++) Dp[i][x] |= Dp[i][x - 1];
			for (int j = 0; j <= LenB; j++) {
				if (Dp[i][j] == 0) continue;
				int Len = Pos[i + 1] - Pos[i] - 1;
				if (GetA(Pos[i] + 1, Pos[i + 1] - 1) == GetB(j + 1, j + Len)) {
					if (Str[Pos[i + 1]] == '*') Dp[i + 1][j + Len] = 1;
					else  Dp[i + 1][j + Len + 1] = 1;
				}
			}
		}

		if (Dp[Tot][LenB] == false) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}
