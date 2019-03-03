/**************************
  * Writer : Leo101
  * Problem : 
  * Tags : 
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

int main()
{
	File(b);

	int a = gi, b = gi, k = gi;
	int Lim = std :: min(a, b);
	
	for (int i = Lim; i >= 0; i--) {
		if (a % i ==0 && b % i == 0) k--;
		if (k == 0) {
			printf("%d", i);
			return 0;
		}
	}

	return 0;
}
