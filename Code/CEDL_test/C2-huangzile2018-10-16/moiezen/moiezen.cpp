/***************************
  * Writer : Leo101
  * Problem : Test10-16 T3 moiezen
  * Tags : 
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 100001
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, p, k, Num[_];

int Check(int Mid)
{
	for (int x = 0; x < p; x++) {
		bool Flag = true;
		int Index = 1, Val = Mid;
		for (int i = 0; i < n; i++) {
			Val -= (Num[i] + x) % p;
			if (Val < 0) {
				Val = Mid - ((Num[i] + x) % p);
				if (Val < 0) Flag = false;
				Index++;
			}
			if (Index > k) Flag = false;
		}
		if (Flag == true) return true;
	}
	return false;
}

int main()
{
	File(moiezen);

	n = gi, p = gi, k = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;
	
	int l = 0, r = 1e5, Ans;
	while (l <= r) {
		int Mid = (l + r) / 2;
		if (Check(Mid) == true) r = Mid - 1, Ans = Mid;
		else l = Mid + 1;
	}

	printf("%d", Ans);

	return 0;
}
