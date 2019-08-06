/**************************
  * Author : Leo101
  * Problem : Luogu3195 [HNOI2008]玩具装箱TOY
  * Tags : dp, 斜率优化
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int MAXN = 100000;
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

int queue[MAXN], n, L;
double dp[MAXN], sum[MAXN];

double a(int i) 
{
	if (i == n) return 0;
	return sum[i] + i + 1;
}
double b(int i) 
{
	return a(i) + L + 1;
}
double X(int i) {return b(i);}
double Y(int i) {return dp[i] + b(i) * b(i);}
double slope(int i, int j)
{ return (Y(i) - Y(j)) / (X(i) - X(j)); }

signed main()
{
	_FILE(code);

	n = gi, L = gi;
	for (int i = 0; i < n; i++) {
		if (i == 0) sum[i] = gi;
		else sum[i] = sum[i - 1] + gi;
	}

	int head = 0, tail = 1;
	queue[head] = n;
	for (int i = 0; i < n; i++) {
		while (head + 1 < tail && slope(queue[head], queue[head + 1]) < 2 * a(i))
			head++;
		dp[i] = dp[queue[head]] + (a(i) - b(queue[head])) * (a(i) - b(queue[head]));
		while (head + 1 < tail && slope(queue[tail - 2], queue[tail - 1]) > slope(queue[tail - 2], i))
			tail--;
		queue[tail++] = i;
	}

	std :: cout << (long long) dp[n - 1];

	return 0;
}
