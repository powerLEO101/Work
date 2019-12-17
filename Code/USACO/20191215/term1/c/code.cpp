/**************************
  * Author : Zile Huang
  * Problem : 20191215Problem 3. Livestock Lineup
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

std :: string a[10], b[10];

std :: string ans[10] = {"none"}, map[10] = {"Beatrice","Sue","Belinda","Bessie","Betsy","Blue","Bella","Buttercup"};

int check(int num)
{
	for (int i = 0; i < 8; i++) {
		if (map[i] == a[num]) {
			if (i != 0 && map[i - 1] == b[num]) return true;
			if (map[i + 1] == b[num]) return true;
			return false;
		}
	}
}

int bigger(std :: string x, std :: string y)
{
	int length = std :: min(x.size(), y.size());
	for (int i = 0; i < length; i++) {
		if (x[i] == y[i]) continue;
		if (x[i] > y[i]) return true;
		if (x[i] < y[i]) return false;
	}
	return x.size() > y.size();
}
int update_answer()
{
	if (ans[0] == "none") {
		for (int i = 0; i < 10; i++) ans[i] = map[i];
		return 0;
	}
	for (int i = 0; i < 8; i++) {
		if (ans[i] == map[i]) continue;
		if (bigger(ans[i], map[i])) break;
		if (bigger(map[i], ans[i])) return 0;
	}
	for (int i = 0; i < 10; i++) ans[i] = map[i];
}

int main()
{
	_FILE(lineup);

	int n = gi;
	for (int i = 0; i < n; i++) {
		std :: cin >> a[i] >> b[i] >> b[i] >> b[i] >> b[i] >> b[i];
	}

	for (int i = 0; i < 200000; i++) {
		std :: random_shuffle(map, map + 8);
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (check(i) == false) {
				flag = 1;
				//std :: cout << i;
				break;
			}
		}
		if (flag == 0) {
			update_answer();
		}
	}
	for (int i = 0; i < 8; i++) map[i] = ans[i];
	for (int i = 0; i < 8; i++) std :: cout << ans[i] << std :: endl;

	return 0;
}
