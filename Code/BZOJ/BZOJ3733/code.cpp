/**************************
  * Writer : Leo101
  * Problem : Lydsy 3733: [Pa2013]Iloczyn
  * Tags : Deep First Search
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 2002
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int n, k, Index, f[_][23], Q[_];
bool Dfs(int Index1, int y, int Sum)
{
	if (y <= 0) return Sum == n;
	for (int i = Index1; i + y - 1 < Index; i++) {
		if (f[i][y - 1] < 0) return false;
		if (1ll * Sum * f[i][y - 1] > n) return false;
		if (Dfs(i + 1, y - 1, Sum * Q[i]) == true) return true;
	}
	return false;
}

int main()
{
	File(code);
	
	int T = gi;
	while (T--) {
		n = gi, k = gi, Index = 0;

		for (int i = 1; i * i <= n; i++) {
			if (n % i != 0) continue;
			Q[Index++] = i;
			if (i * i != n) Q[Index++] = n / i;
		}

		std::sort(Q, Q + Index);

		for (int i = 0; i < Index; i++) {
			long long Temp = 1;
			for (int j = 0; j < k && i + j < Index; f[i][j++] = Temp) {
				if (Temp > 0) {
					Temp *= Q[i + j];
					if (Temp > n) Temp = -1;
				}
			}
		}

		printf(Dfs(0, k, 1) == true ? "TAK\n" : "NIE\n");
	}

	return 0;
}
