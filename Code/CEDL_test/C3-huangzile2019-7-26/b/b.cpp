#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bits/stdc++.h>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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

int a[1000];

int main()
{
	_FILE(b);

	std :: string str;
	std :: cin >> str;

	for (int i = 0; i < str.size(); i++) a[str[i]] = 1;
	for (int i = 'a'; i <= 'z'; i++) {
		if (a[i] == 0) {
			std :: cout << (char)i;
			return 0;
		}
	}


	return 0;
}
