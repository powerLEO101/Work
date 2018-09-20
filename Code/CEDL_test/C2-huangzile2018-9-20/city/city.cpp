#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 310
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, m, Cnt, Num[_ * _], a[_], Ans[_][_];
bool Vis[_ * _];

void Check(int x)
{
	int a1_a2 = Num[0], a1_a3 = Num[1], a2_a3 = Num[x];
	memset(Vis, false, sizeof(Vis));
	memset(a, 0, sizeof(a));

	Vis[0] = Vis[1] = Vis[x] = true;
	a[0] = (a1_a2 + a1_a3 - a2_a3) / 2,
	a[1] = (a1_a2 + a2_a3 - a1_a3) / 2,
	a[2] = (a2_a3 + a1_a3 - a1_a2) / 2;

	int Index = 2;
	for (int i = 3; i < n ; i++) {
		while (Vis[Index] == true && Index < m) Index++;
		if (Index == m) return;

		a[i] = Num[Index] - a[0];
		Vis[Index] = true;

		for (int j = 1; j < i; j++) {
			if (a[j] > a[i]) return;
			int Value = a[j] + a[i];
			int p = std::lower_bound(Num, Num + m, Value) - Num;
			if (Num[p] != Value) return;
			
			int Temp = p;
			while (Temp < m && Num[Temp] == Num[p] && Vis[Temp] == true) Temp++;
			if (Num[Temp] != Num[p] || Vis[Temp] == true) return;
			
			Vis[Temp] = true;
		}
	}

	for (int i = 0; i < n; i++) 
		Ans[Cnt][i] = a[i];
	Cnt++;
}

int main()
{
	File(city);

	n = gi, m = n * (n - 1) / 2;
	for (int i = 0; i < m; i++) Num[i] = gi;

	std::sort(Num, Num + m);

	for (int i = 2; i < m;) {
		Check(i);
		int Temp = i;
		while (Num[Temp] == Num[i] && i < m) Temp++;
		i = Temp;
	}
	
	printf("%d\n", Cnt);
	for (int i = 0; i < Cnt; i++) {
		for (int j = 0; j < n; j++) printf("%d ", Ans[i][j]);
		printf("\n");
	}
	return 0;
}
