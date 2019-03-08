/**************************
  * Writer : Leo101
  * Problem : Luogu P4324 [JSOI2016]扭动的回文串
  * Tags : Manacher
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 1e6;
const unsigned long long BASE = 1e9 + 7;
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

char Str1[Max_N], Str2[Max_N], Str[Max_N];
int n, p1[Max_N], p2[Max_N], Ans = 0;
unsigned long long HashA[Max_N], HashB[Max_N], Pow[Max_N];

void Manacher(char* Tmp, int* p)
{
	int Len = 0;
	Str[0] = ' '; Str[++Len] = '$';
	for (int i = 1; i <= n; i++) {
		Str[++Len] = Tmp[i];
		Str[++Len] = '$';
	}

	int Max_P = 0, Pos = 0;
	for (int i = 1; i <= Len; i++) {
		if (i <= Max_P) p[i] = std :: min(Max_P - i + 1, p[Pos * 2 - i]);
		else p[i] = 1;
		while (Str[i + p[i]] == Str[i - p[i]]) p[i]++;
		if (i + p[i] - 1 > Max_P) {
			Max_P = i + p[i] - 1;
			Pos = i;
		}
		Ans = std :: max(Ans, p[i] - 1);
	}
	for (int i = 1; i <= Len; i++) p[i]--;
}

int Get(int Id, int l, int r)
{ return Id == 1 ? HashA[r] - HashA[l - 1] * Pow[r - l + 1] : HashB[l] - HashB[r + 1] * Pow[r - l + 1]; }
bool Check(int Mid, int l, int r) 
{ return l - Mid + 1 >= 1 && r + Mid - 1 <= n && Get(1, l - Mid + 1, l) == Get(2, r, r + Mid - 1); }
void Solve1()
{
	for (int i = 2; i <= 2 * n; i++) {
		int ll, rr;
		if (i % 2 == 0) {
			ll = (i / 2) - (p1[i] / 2) - 1;
			rr = (i / 2) + (p1[i] / 2);
		} else {
			ll = ((i + 1) / 2) - (p1[i] / 2) - 1;
			rr = (i / 2) + (p1[i] / 2);
		}
		int l = 0, r = n, Tmp = 0;
		while (l <= r) {
			int Mid = (l + r) / 2;
			if (Check(Mid, ll, rr) == true) {
				l = Mid + 1;
				Tmp = Mid;
			} else {
				r = Mid - 1;
			}
		}
		Ans = std :: max(Ans, p1[i] + 2 * Tmp);
	}
}
void Solve2()
{
	for (int i = 2; i <= 2 * n; i++) {
		int ll, rr;
		if (i % 2 == 0) {
			ll = (i / 2) - (p2[i] / 2);
			rr = (i / 2) + (p2[i] / 2) + 1;
		} else {
			ll = ((i + 1) / 2) - (p2[i] / 2);
			rr = (i / 2) + (p2[i] / 2) + 1;
		}

		int l = 0, r = n, Tmp = 0;
		while (l <= r) {
			int Mid = (l + r) / 2;
			if (Check(Mid, ll, rr) == true) {
				l = Mid + 1;
				Tmp = Mid;
			} else {
				r = Mid - 1;
			}
		}
		Ans = std :: max(Ans, p2[i] + 2 * Tmp);
	}
}

int main()
{
	File(code);

	n = gi;
	scanf("%s %s", Str1 + 1, Str2 + 1);

	Manacher(Str1, p1); Manacher(Str2, p2);

	for (int i = 1; i <= n; i++) HashA[i] = HashA[i - 1] * BASE + Str1[i];
	for (int i = n; i >= 1; i--) HashB[i] = HashB[i + 1] * BASE + Str2[i];
	Pow[0] = 1;
	for (int i = 1; i <= Max_N; i++) Pow[i] = Pow[i - 1] * BASE;

	Solve1(); Solve2();
	
	printf("%d", Ans);
	
	return 0;
}
