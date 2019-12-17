/**************************
  * Author : Zile Huang
  * Problem : 20191215Problem 2. Meetings
  * Tags : 二分查找，转换
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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

int n, l, countLeft, countRight;

class Node 
{
public:
	int index, w, v;
} nodes[MAXN];
class Data
{
public:
	int id, index;
} left[MAXN], right[MAXN];

int operator< (const Data& a, const Data& b)
{
	return a.index < b.index;
}

int main()
{
	_FILE(meetings);
	
	n = gi, l = gi;
	for (int i = 0; i < n; i++) {
		nodes[i].index = gi;
		nodes[i].w = gi;
		nodes[i].v = gi;
	}

	for (int i = 0; i < n; i++) {
		if (nodes[i].v == -1) {
			left[countLeft++] = (Data) {i, nodes[i].index};
		} else {
			eight[countRight++] = (Data) {i, nodes[i].index};
		}
	}
	std :: sort(left, left + countLeft);
	std :: sort(right, right + countRight);

	int indexL = 0, indexR = countRight - 1;
	while (indexL < countLeft && indexR >= 0) {
	}

	return 0;
}
