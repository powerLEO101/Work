/**************************
  * Writer : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <bits/stdc++.h>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 15;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int main()
{
	freopen("code.in", "w", stdout);
	
	srand(time(0));
	int n = rand() % MAXN + 1, m = rand() % MAXN + 1, A = rand() % n + 1, B = rand() % n + 1;

	printf("%d %d %d %d", n, m, A, B);
	printf("\n");
	for (int i = 0; i < m; i++) printf("%d ", rand() % n + 1);

	return 0;
}
