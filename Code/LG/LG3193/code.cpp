/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int MAXN = 100;
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

int n, m, MOD;
int next[MAXN];

class Matrix 
{
public:
	int value[MAXN][MAXN];
	void operator= (const int b)
	{
		for (int i = 0; i < m; i++)
			value[i][i] = b;
	}
Matrix() {
	memset(value, 0, sizeof(value));
}
} matrix;
Matrix operator* (const Matrix& a, const Matrix& b)
{
	Matrix ret;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++) {
				ret.value[i][k] += (a.value[i][j] * b.value[j][k]) % MOD;
				ret.value[i][k] %= MOD;
			}
	return ret;
}
Matrix operator^ (const Matrix& a, int b) 
{
	Matrix ret, tmp;
	ret = 1ll;
	tmp = a;
	while (b != 0) {
		if (b & 1) 
			ret = ret * tmp;
		tmp = tmp * tmp;
		b >>= 1;
	}
	return ret;
}

void get(std::string str)
{
	next[1] = 0;
	int j = 0;
	for (int i = 2; i <= m; i++) {
		while (j != 0 && str[j + 1] != str[i])
			j = next[j];
		if (str[j + 1] == str[i]) j++;
		next[i] = j;
	}
	for (int i = 0; i < m; i++) {
		for (int j = '0'; j <= '9'; j++) {
			int now = i;
			while (now != 0 && str[now + 1] != j)
				now = next[now];
			if (str[now + 1] == j) now++;
			matrix.value[i][now]++;
		}
	}
}

signed main()
{
	_FILE(code);
	n = gi, m = gi, MOD = gi;
	std::string str;
	std::cin >> str;
	str = " " + str;
	get(str);
	matrix = matrix ^ n;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		ans = ans + matrix.value[0][i];
		ans %= MOD;
	}
	std::cout << ans;

	return 0;
}
