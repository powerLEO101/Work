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

//int ans[50], num[50];

int main()
{
	std :: string s;
	int T = gi;
	while (T--) {
		/*
		memset(ans, 0, sizeof(ans));
		memset(num, 0, sizeof(num));
		std :: cin >> s;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			num[i + 1] = s[i] - '0';
		}
		int add = 0;
		for (int i = 1; i <= size; i++) {
			ans[i] = num[i] + add;
			int backup = i;
			while (ans[i] >= 10) {
				int temp = ans[i] / 10;
				ans[i - 1] += temp;
				ans[i] %= 10;
				ans[i] += temp;
				i--;
			}
			i = backup;
			add = ans[i];
		}
		if (ans[0] != 0) printf("%d", ans[0]);
		for (int i = 1; i <= size; i++) 
			printf("%d", ans[i]);
		printf("\n");
		*/
		/*
		long long num, ans = 0;
		std :: cin >> num;
		while (num != 0) {
			for (long long i = 1e10; i != 0; i /= 10) {
				if (num / i != 0) {
					long long temp = num;
					std :: cout << num / i * i << std :: endl;
					ans += num / i * i;
					num = temp / i * i / 10;
				}
			}
			num /= 10;
		}
		std :: cout << ans << std :: endl;
		*/
		long long num, ans = 0;
		std :: cin >> num;
		while (num / 10 != 0) {
			ans += num - (num % 10);
			num = (num / 10) + (num % 10);
		}
		std :: cout << ans + num<< std :: endl;
	}
	return 0;
}
