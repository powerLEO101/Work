#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 30000
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

int Ans[_], C[_ * 3], n;
int Lowbit(int u) {return u & (-u);}
void Add(int Index, int Value)
{
	while (Index <= 32001) {
		C[Index] += Value;
		Index += Lowbit(Index);
	}
}
int Sum(int Index)
{
	int Ans = 0;
	while (Index > 0) {
		Ans += C[Index];
		Index -= Lowbit(Index);
	}
	return Ans;
}

int main()
{
	File(code);
	n = gi;
	for (int i = 0; i < n; i++) {
		int Index = gi + 1,Temp = gi;
		Ans[Sum(Index)]++;
		Add(Index, 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", Ans[i]);
	return 0;
}
