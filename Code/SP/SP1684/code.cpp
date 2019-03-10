/**************************
 * Writer : Leo101
 * Problem : SP1684 FREQUENT - Frequent values
 * Tags : RMQ，倍增
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 200000;
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

int RMQ[Max_N][21], Log[Max_N], Num[Max_N];

int main()
{
	File(code);
	int n, m;
	while (n = gi) {
		m = gi;
		memset(RMQ, 0, sizeof(RMQ));
		for (int i = 1; i <= n; i++) Num[i] = gi;
		for (int i = 1; i <= n; i++) 
			RMQ[i][0] = (Num[i] == Num[i - 1]) ? RMQ[i - 1][0] + 1 : 1;
		Log[0] = -1;
		for (int i = 1; i <= n + 1; i++) Log[i] = Log[i >> 1] + 1;


		for (int j = 1; j <= Log[n + 1]; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
				RMQ[i][j] = std :: max(RMQ[i][j - 1], RMQ[i + (1 << (j - 1))][j - 1]);

		while (m--) {
			int l = gi + 1, r = gi;
			int Ans = 1;
			while (Num[l] == Num[l - 1] && l <= r) Ans++, l++;
			int Log2 = Log[r - l + 1];
			if (l <= r) Ans = std :: max(Ans, std :: max(RMQ[l][Log2], RMQ[r - (1 << Log2) + 1][Log2]));
			printf("%d\n", Ans);
		}
	}
	return 0;
}
