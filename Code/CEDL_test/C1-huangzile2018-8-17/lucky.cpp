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

int Num[20];
int Judge(int x)
{
	int n = 0;
	while (x != 0) {
		Num[++n] = x % 10;
		x /= 10;
	}
	for (int i = 1; (i != n - i + 1) && (i <= n/2); i++) {
		if (Num[i] == Num[n - i + 1]) {
			return 0;
		}
	}
	return 1;
}
int main()
{
	File(lucky);
	int From = gi, To = gi;
	int Ans = 0;
	for (int i = From; i <= To; i++)
		Ans += Judge(i);
	std::cout<<Ans;
	return 0;
}
