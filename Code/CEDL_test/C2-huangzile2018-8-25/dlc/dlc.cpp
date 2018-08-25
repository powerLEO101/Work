#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1000010
#define INF 0x3f3f3f3f
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

int l[_], r[_], n;

void Get5pts()
{
	printf("%d", n);
}

void Get10pts()
{
	int Max = -INF;
	for (int i = 0; i < n; i++) {
		int Max_Len = 1, Now = l[i];
		for (int j = i + 1; j < n; j++)
			if (r[j] >= Now) {
				Now = std::max(Now, l[j]);
				Max_Len++;
			}
		Max = std::max(Max, Max_Len);
	}
	printf("%d", Max);
}

int main()
{
	File(dlc);
	n = gi;
	bool Flag = false;
	for (int i = 0; i < n; i++) {
		l[i] = gi, r[i] = gi;
		if (i == 0) continue;
		if (l[i] != l[i - 1]) Flag = true;
	}
	if (Flag == false) Get5pts();
	else if (n <= 5000) Get10pts();
	return 0;
}
