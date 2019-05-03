/**************************
  * Author : Leo101
  * Problem : Luogu P1071 潜伏者
  * Tags : 模拟
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

std :: string str1, str2, str3;
char map[200], remap[200];

int main()
{
	_FILE(code);

	std :: cin >> str1 >> str2 >> str3;

	for (auto it1 = str1.begin(), it2 = str2.begin(); it1 != str1.end(); it1++, it2++) {
		if (map[*it1] != 0 && map[*it1] != *it2) {
			printf("Failed");
			return 0;
		}
		if (remap[*it2] != 0 && remap[*it2] != *it1) {
			printf("Failed");
			return 0;
		}
		map[*it1] = *it2;
		remap[*it2] = *it1;
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		if (map[i] == 0) {
			printf("Failed");
			return 0;
		}
	}
	for (auto it = str3.begin(); it != str3.end(); it++)
		printf("%c", map[*it]);

	return 0;
}
