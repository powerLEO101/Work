/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 1e6;
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

int n, k, countX, countY;

int tree[MAXN];
int lowbit(int x)
{ return x & (-x); }
void insert(int index, int value)
{
	for(; index <= MAXN; index += lowbit(index))
		tree[index] += value;
}
int query(int index)
{
	int ret = 0;
	for (; index > 0; index -= lowbit(index))
		ret += tree[index];
	return ret;
}

class Temp
{
public:
	int value, index;
} tmpX[MAXN], tmpY[MAXN];
int operator< (const Temp& a, const Temp& b)
{
	return a.value < b.value;
}

class Node
{
public:
	int x, y, z;
	std::list<Node>::iterator listIndex;
} node[MAXN];
int cmpX(const Node& a, const Node& b)
{
	return a.x < b.x;
}
int cmpY(const Node& a, const Node& b)
{
	return a.y < b.y;
}

std::list<Node> color[MAXN];

int getAns(int mode)
{
	memset(tree, 0, sizeof(tree));
	int ans = 0;
	if (mode == 1) {
		for (int i = 0; i < n; i++) 
			node[i].y = -node[i].y;
	}
	for (int i = 0; i < k; i++)
		color[i].clear();
	std::sort(node, node + n, cmpX);
	for (int i = 0; i < n; i++) {
		node[i].listIndex = color[node[i].z].insert(color[node[i].z].end(), node[i]);
		insert(node[i].x, 1);
	}
	std::sort(node, node + n, cmpY);
	for (int i = 0; i < k; i++) {
		int last = 0;
		for (auto it : color[i]) {
			if (last == -1) {
				last = it.x;
				continue;
			}
			ans = std::max(ans, query(it.x - 1) - query(last));
			last = it.x;
		}
		ans = std::max(ans, query(n) - query(last));
	}
	int point = 0;
	for (int i = 0; i < n; i++) {
		int fixedY = node[i].y;
		while (node[point].y == fixedY)
			insert(node[point++].x, -1);
		int l, r;
		auto tmp1 = node[i].listIndex, tmp2 = node[i].listIndex;
		if (node[i].listIndex != color[node[i].z].begin()) {
			tmp1--;
			l = tmp1->x;
		} else
			l = 0;
		tmp2++;
		if (tmp2 != color[node[i].z].end()) {
			r = (tmp2->x) - 1;
		} else
			r = n;
		ans = std::max(ans, query(r) - query(l));
		color[node[i].z].erase(node[i].listIndex);
	}
	return ans;
}

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int ans = 0;
		n = gi, k = gi;
		for (int i = 0; i < n; i++) {
			tmpX[i].value = gi;
			tmpX[i].index = i;
			tmpY[i].value = gi;
			tmpY[i].index = i;
			node[i].z = gi - 1;
		}
		std::sort(tmpX, tmpX + n);
		std::sort(tmpY, tmpY + n);
		countX = 1, countY = 1;
		for (int i = 0; i < n; i++) {
			node[tmpX[i].index].x = countX;
			if (tmpX[i].value != tmpX[i + 1].value)
				countX++;
			node[tmpY[i].index].y = countY;
			if (tmpY[i].value != tmpY[i + 1].value)
				countY++;
		}
		ans = std::max(getAns(0), getAns(1));
		std::cout << ans << std::endl;
	}

	return 0;
}

