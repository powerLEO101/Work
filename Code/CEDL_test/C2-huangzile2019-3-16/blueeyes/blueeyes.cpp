#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int INF = 0x3f3f3f3f;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, k, ans;
std :: string num;

bool getAns1()
{
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] == '0') cnt++;
		if (num[i] == '1' && cnt + 1 == k) {
			ans = i + 1;
			return true;
		}
		if (cnt == k) {
			ans = i + 1;
			return true;
		}
	}
	if (cnt + 1 == k) {
		ans = n + 1;
		return true;
	}
	return false;
}
bool getAns2()
{
	bool flag = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] == '1' && flag == false) {
			flag = true;
			continue;
		}
		if (num[i] == '1') cnt++;
		if (num[i] == '0' && cnt + 1 == k) {
			ans = std :: min(ans, i + 1);
			return true;
		}
		if (cnt == k) {
			ans = std :: min(ans, i + 1);
			return true;
		}
	}
	if (cnt + 1 == k) {
		ans = std :: min(ans, n + 1);
		return true;
	}
	return false;
}

int main()
{
	_FILE(blueeyes);

	int T = gi;
	while (T--) {
		ans = INF;
		n = gi, k = gi;
		std :: cin >> num;
		bool flag1 = getAns1();
		bool flag2 = getAns2();
		bool flag = flag1 | flag2;
		if (flag == false) printf("Blue Eyes White Drogon\n");
		else printf("Exodia Flame\n%d\n", ans);
	}

	return 0;
}
