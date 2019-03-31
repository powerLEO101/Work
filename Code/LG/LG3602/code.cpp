/**************************
  * Author : Leo101
  * Problem : Luogu P3602 Koishi Loves Segments
  * Tags : dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 4e5 + 9;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

std :: multiset<int> Set;

class Data
{
public:
	int x, y;
} num[MAXN], nodes[MAXN];
bool operator< (const Data &a, const Data &b)
{ return a.x < b.x; }

int main()
{
	_FILE(code);

	int n = gi, m = gi, ans = n;
	for (int i = 0; i < n; i++) 
		num[i].x = gi, num[i].y = gi;
	for (int i = 0; i < m; i++)
		nodes[i].x = gi, nodes[i].y = gi;

	std :: sort(num, num + n);
	std :: sort(nodes, nodes + m);
	
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j < n && num[j].x <= nodes[i].x)
			Set.insert(num[j++].y);
		while (Set.size() != 0 && *Set.begin() < nodes[i].x)
			Set.erase(Set.begin());
		while (Set.size() > nodes[i].y) {
			Set.erase(--Set.end());
			ans--;
		}
	}

	printf("%d", ans);

	return 0;
}
