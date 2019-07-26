#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 5000;
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

int dp[MAXN];

class Data
{
public:
	int a, b;
} num[MAXN];
bool operator< (const Data &a, const Data &b)
{
	return a.a + a.b < b.a + b.b; 
}

int main()
{
	_FILE(c);

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;

	int n = gi;
	for (int i = 0; i < n; i++) {
		num[i].a = gi;
		num[i].b = gi;
		dp[0] += num[i].a;
	}
	int m = gi, answer = 0;

	std :: sort(num, num + n);

	for (int i = 0; i < n; i++) {
		for (int j = answer; j >= 0; j--) {
			if ((num[i].b + dp[j]) >= m) 
				dp[j + 1] = std :: max(dp[j + 1], dp[j] - num[i].a);
			if (dp[answer + 1] >= 0) answer++;
		}
	}

	printf("%d", answer);

	return 0;
}
