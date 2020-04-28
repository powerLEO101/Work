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

int num[1000001], vis[100], next[1000001];
char ans[1000001];

int main()
{
	_FILE(code);

	int n = gi;
	for (int i = 1; i <= n; i++) {
		num[i] = gi;
		next[i] = i - num[i];
	}
	ans[0] = 'a';
	for (int i = 1; i <= n; i++) {
		if (next[i] != 0) {
			ans[i] = ans[next[i]];
		} else {
			memset(vis, 0, sizeof(vis));
			int now = next[i - 1];
			do {
				vis[ans[now + 1] - 'a'] = 1;
				now = next[now];
			} while (now != 0);
			vis[ans[now + 1] - 'a'] = 1;
			for (int j = 0; j < 26; j++) {
				if (vis[j] == false) {
					ans[i] = j + 'a';
					break;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << ans[i];
	}

	return 0;
}
