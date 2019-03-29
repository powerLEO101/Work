/**************************
  * Writer : Leo101
  * Problem : Luogu P4390 [BOI2007]Mokia 摩基亚
  * Tags : cdq
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

class Data
{
public:
	int tim, x, y, size, val;
}
bool operator< (const Data &a, const Data &b)
{
	if (a.tim > b.tim) return true;
	if (a.tim == b.tim && a.x < b.x) return true;
	if (a.tim == b.tim && a.x == b.x && a.y < b.y) return true;
	return false;
}

void modify(int index, int val)
{
	for (; index <= w; index = index + (index & (-index)))
		bit[index] += val;
}
void query(int index)
{
	int ret = 0;
	for (; index > 0; index = index - (index & (-index)))
		ret += bit[index];
	return ret;
}

void CDQ(int l, int r)
{
	if (l == r - 1) return ;
	int mid = (l + r) / 2;
	CDQ(l, mid);
	CDQ(mid, r);

	int p1 = l, p2 = mid;
	while (p1 < mid && p2 < r) {
		if (
	}
}

int main()
{
	_FILE(code);



	return 0;
}
