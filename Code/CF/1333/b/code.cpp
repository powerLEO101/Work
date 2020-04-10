/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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

int num1[100005], num2[100005];

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int n = gi;
		for (int i = 0; i < n; i++) num1[i] = gi;
		for (int i = 0; i < n; i++) num2[i] = gi;
		int sub = 0, add = 0, flag = 0, sub1 = 0, add1 = 0;
		for (int i = 0; i < n; i++, sub |= sub1, add |= add1) {
			if (num1[i] == -1) sub1 = 1;
			if (num1[i] == 1) add1 = 1;
			if (num1[i] == num2[i]) continue;
			if (num2[i] > num1[i] && add == 1) continue;
			if (num2[i] < num1[i] && sub == 1) continue;
			flag = 1;
			std::cout << "NO";
			break;
		}
		if (flag == 0) {
			std::cout << "YES";
		}
		std::cout << std::endl;
	}

	return 0;
}
