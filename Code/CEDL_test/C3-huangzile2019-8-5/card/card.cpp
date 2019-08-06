#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2e5;
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

class Data
{
public:
	int a, b;
} num[MAXN], tmp[MAXN];
int count[MAXN];
bool operator< (const Data& a, const Data& b)
{
	return a.b < b.b;
}

int main()
{
	_FILE(card);
	
	int n = gi;
	for (int i = 0; i < n; i++)
		num[i].a = gi, num[i].b = gi;
	for (int i = 0; i < n; i++) 
		tmp[i].a = i,
		tmp[i].b = num[i].a;
	std :: sort(tmp, tmp + n);
	int c = 0;
	for (int i = 0; i < n; i++) {
		num[tmp[i].a].a = c;
		if (tmp[i].b != tmp[i + 1].b) c++;
	}
	std :: sort(num, num + n);

	for (int i = 1; i < n; i++) {
		if (num[i].a == num[i - 1].a && num[i].b == num[i - 1].b) 
			num[i].a = ++c;
	}

	int l = 0, ans = 0x3f3f3f3f;
	for (int r = 0; r < n; r++) {
		count[num[r].a]++;
		while (num[r].b - num[l].b + 1 > n)
			count[num[l++].a]--;
		ans = std :: min(ans, n - count[num[r].a]);
	}

	std :: cout << ans;
	
	return 0;
}
