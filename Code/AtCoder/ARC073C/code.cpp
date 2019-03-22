/**************************
  * Writer : Leo101
  * Problem : ARC073C Ball Coloring
  * Tags : 贪心
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 3e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

std :: multiset<int> left, right;

class Data
{
public:
	int x, y;
} num[MAXN];
bool operator< (const Data& a, const Data &b)
{ return a.x < b.x; } 

long long getAns()
{ return 1ll * (*left.rbegin() - *left.begin()) * (*right.rbegin() - *right.begin()); }

int main()
{
	_FILE(code);

	int n = gi;
	for (int i = 0; i < n; i++) {
		int x = gi, y = gi;
		if (x > y) std :: swap(x, y);
		num[i].x = x, num[i].y = y;
		left.insert(x); right.insert(y);
	}

	std :: sort(num, num + n);
	long long ans = getAns();

	for (int i = 0; i < n; i++) {
		int x = num[i].x, y = num[i].y;
		left.erase(left.find(x)); right.insert(x);
		right.erase(right.find(y)); left.insert(y);
		ans = std :: min(ans, getAns());
	}

	printf("%lld\n", ans);

	return 0;
}
