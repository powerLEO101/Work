/**************************
  * Author : Zile Huang
  * Problem : 20191215Problem 2. Where Am I?
  * Tags : 模拟
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
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

std :: string str;
int length;

int check(int x)
{
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length; j++) {
			int flag = true;
			for (int k = 0; k < x; k++) {
				if (str[i + k] != str[j + k]) {
					flag = false;
					break;
				}
			}
			if (flag == true) return false;
		}
	}
	return true;
}

int main()
{
	_FILE(whereami);

	length = gi;
	std :: cin >> str;
	
	for (int answer = 1; answer <= length; answer++) {
		if (check(answer) == false) continue;
		std :: cout << answer;
		return 0;
	}

	std :: cout << "none";

	return 0;
}
