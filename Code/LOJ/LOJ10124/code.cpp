#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100
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

int Colors[_], Temp[_];

int main()
{
	File(code);
	int n = gi, k = gi, p = gi, Pre = -1, Ans = 0;
	for (int i = 0; i < n; i++) {
		int Color = gi, Cost = gi;
		if (Cost <= p) Pre = i;	
		if (Pre == i) {
			for (int i = 0; i < k; i++) {
				Colors[i] += Temp[i];
				Temp[i] = 0;
			}
		}
		if (Pre != -1) Ans += Colors[Color];
		if (Pre == i) Colors[Color]++;
		else Temp[Color]++;
	}
	printf("%d", Ans);
	return 0;
}
