/**************************
  * Writer : Leo101
  * Problem : Luogu 3129 [USACO15DEC]高低卡(白金)High Card Low Card (Platinum)
  * Tags : 贪心
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <set>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 200005
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

std::set<int> s1;
std::set<int> s2;
bool Vis[_];
int Sur[_], Low[_], a[_];

int main()
{
	File(code);

	int n = gi;
	for (int i = 0; i < n; i++) {
		a[i] = gi;
		Vis[a[i]] = true;
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (Vis[i] == true) continue;
		s1.insert(i);
		s2.insert(-i);
	}

	for (int i = 0; i < n; i++) {
		std::set<int>::iterator it = s1.lower_bound(a[i]);
		if (it == s1.end()) {
			Sur[i] = Sur[std::max(i - 1, 0)];
			continue;
		}
		Sur[i] = Sur[std::max(i - 1, 0)] + 1;
		s1.erase(it);
	}
	for (int i = n - 1; i >= 0; i--) {
		std::set<int>::iterator it = s2.lower_bound(-a[i]);
		if (it == s2.end()) {
			Low[i] = Low[i + 1];
			continue;
		}
		Low[i] = Low[i + 1] + 1;
		s2.erase(it);
	}

	int Ans = Low[0];
	for (int i = 0; i < n; i++)
		Ans = std::max(Ans, Sur[i] + Low[i + 1]);
	printf("%d", Ans);

	return 0;
}
