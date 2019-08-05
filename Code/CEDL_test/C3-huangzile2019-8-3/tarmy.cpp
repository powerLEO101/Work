#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 1e5 + 20;
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

int l, r;
int count[MAXN], SQRT[MAXN * 10], cnt, num[MAXN];
long long sum[MAXN];

int add(int x)
{
	if (x == 0 || x == 1) return true;
	int number = x, flag = 1;
	for (int i = 2; i <= SQRT[x]; i++) {
		if ((number % i == 0) && count[i] != 0) flag = 0, cnt++;
		if (number % i == 0) count[i]++;
		while (number % i == 0)
			number /= i;
		if (number == 1) break;
	}
	if (number != 1) {
		if (count[number] != 0) flag = 0, cnt++;
		count[number]++;
	}
	return flag;
}
int del(int x)
{
	if (x == 0 || x == 1) return false;
	int number = x;
	for (int i = 2; i <= SQRT[x]; i++) {
		if (number % i == 0) {
			count[i]--;
			if (count[i] == 1) cnt--;
		}
		while (number % i == 0) 
			number /= i;
		if (number == 1) break;
	}
	if (number != 1) {
		if (count[number] == 2) cnt--;
		count[number]--;
	}
	return cnt == 0;
}

int main()
{
	_FILE(tarmy);

	for (int i = 1; i < 1000; i++)	{
		for (int j = i * i; j < (i + 1) * (i + 1); j++)
			SQRT[j] = i;
	}
	SQRT[1000000] = 1000;

	int n = gi, k = gi;
	for (int i = 0; i < n; i++) num[i] = gi;
	for (int i = 0; i < n; i++)
		sum[i + 1] = sum[i] + num[i];
	
	l = 0;
	add(num[l]);
	int ans = 0;
	for (r = 1; r < n; r++) {
		if (add(num[r]) == false) {
			while (del(num[l++]) == false);
		}
		if (sum[r + 1] - sum[l] >= k) 
			ans = std :: max(ans, r - l + 1);
	}

	std :: cout << ans;

	return 0;
}
