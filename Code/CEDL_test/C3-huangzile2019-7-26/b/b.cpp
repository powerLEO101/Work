#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 5e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int pre[MAXN]['z' + 1], f[MAXN];

int main()
{
	_FILE(b);

	std :: string str;
	std :: cin >> str;
	int n = str.size();

	for (int i = 'a'; i <= 'z'; i++) pre[n][i] = n;
	memset(f, 0x3f, sizeof(f));
	f[n + 1] = 0; f[n] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 'a'; j <= 'z'; j++)
			pre[i][j] = pre[i + 1][j];
		pre[i][str[i]] = i;
	}
	
	for (int i = n - 1; i >= 0; i--)
		for (int j = 'a'; j <= 'z'; j++)
			f[i] = std :: min(f[i], f[pre[i][j] + 1] + 1);



	int now = 0;
	for (int i = 0; i < f[0]; i++)
		for (int j = 'a'; j <= 'z'; j++) {
			if (f[now] == f[pre[now][j] + 1] + 1) {
				printf("%c", j);
				now = pre[now][j] + 1;
				break;
			}
		}

	return 0;
}
