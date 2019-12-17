/**************************
  * Author : Zile Huang
  * Problem : 20191215Problem 1. MooBuzz
  * Tags : 数论，模拟
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
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

signed main()
{
	_FILE(moobuzz);

	int n = gi, answer = ((n / 15) * 7) / 15 * 15 + n - (n % 15);

	//std :: cout << answer << std :: endl;
	

	int temp = (n / 15) * 7 / 15 * 15, count = n % 15 + ((n / 15) * 7) % 15;;
	while (temp >= 15) {
		answer += (temp / 15 * 7) / 15 * 15;
		count += (temp / 15 * 7) % 15;
		temp = (temp / 15 * 7) / 15 * 15 + (temp % 15); 
	}

	//std :: cout << count << std :: endl;
	count += temp;
	//std :: cout << answer;

	while (count--) {
		answer++;
		while (answer % 15 == 0 || answer % 5 == 0 || answer % 3 == 0)
			answer++;
	}

	std :: cout << answer;

	return 0;
}
