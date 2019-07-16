/**************************
 * Author : Leo101
 * Problem : 
 * Tags : 
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int LIMIT = 100, MOD = 1e7 + 7;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

long long dp[LIMIT][LIMIT][LIMIT][2], num[LIMIT];
long long ans = 1, length;

long long qPow(long long a, long long b)
{
	long long ret = 1, base = a;
	while (b != 0) {
		if ((b & 1) == 1)
			ans = (ans * base) % MOD;
		base = (base * base) % MOD;
		b >>= 1;
	}
	return ret;
}

long long getAns(int now, int sum, int target, int status)
{
	if (now == 0) return sum == target;
	if (status == 0 && dp[now][sum][target][status] != -1)
		return dp[now][sum][target][status];
	long long limit = status ? num[now] : 1, ret = 0;
	for (int i = 0; i <= limit; i++)
		ret += getAns(now - 1, sum + i, target, status && i == num[now]);
	if (status == 0) dp[now][sum][target][status] = ret;
	return ret;
}

int main()
{
	_FILE(code);
	long long n;
	std :: cin >> n;

	while (n != 0) {
		num[++length] = n % 2;
		n >>= 1;
	}

	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= length; i++) {
		ans = (ans * qPow(i, getAns(length, 0, i, 1))) % MOD;
	}

	std :: cout << ans;

	return 0;
}

