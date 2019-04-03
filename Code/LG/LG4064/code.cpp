/**************************
  * Author : Leo101
  * Problem : Luogu P4064 [JXOI2017]加法
  * Tags : 贪心，二分答案
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <functional>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 3e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

std :: multiset<int, std :: greater<int> > Set;
int n, m, a, K;
int num[MAXN], need[MAXN], bit[MAXN];

class Data
{
public:
	int l, r;
} interval[MAXN];
bool operator< (const Data &a, const Data &b)
{ return a.l < b.l; }

void modifyInterval(int l, int r)
{
	for (int i = l; i <= n; i += i & (-i)) 
		bit[i] += 1;
	for (int i = r + 1; i <= n; i += i & (-i))
		bit[i] -= 1;
}
int queryNode(int index)
{
	int ret = 0;
	for (; index != 0; index -= index & (-index))
		ret += bit[index];
	return ret;
}

bool check(int mid)
{
	while (!Set.empty()) Set.erase(Set.begin());
	memset(bit, 0, sizeof(bit));

	for (int i = 1; i <= n; i++) 
		need[i] = mid <= num[i] ? -1 : (mid - num[i] - 1) / a + 1;

	int j = 0, res = 0;
	for (int i = 1; i <= n; i++) {
		if (need[i] == -1) continue;
		while (j < m && interval[j].l <= i) 
			Set.insert(interval[j++].r);
		// if (Set.size() < need[i]) return false;
		while (queryNode(i) < need[i]) {
			if (++res > K || Set.empty()) return false;
			modifyInterval(i, *Set.begin());
			Set.erase(Set.begin());
		}
	}
	return true;
}

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		n = gi, m = gi, K = gi, a = gi;
		for (int i = 1; i <= n; i++) num[i] = gi;
		for (int i = 0; i < m; i++) {
			interval[i].l = gi;
			interval[i].r = gi;
		}
		std :: sort(interval, interval + m);

		int l = 0, r = 1e9, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid) == true) {
				l = mid + 1;
				ans = mid;
			} else {
				r = mid - 1;
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}
