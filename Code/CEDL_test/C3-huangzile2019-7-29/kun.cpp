/**************************
  * Author : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define INF 0x3f3f3f3f
const int LIMIT = 2e6;
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

int num[LIMIT];

int binarySearch(int val, int n)
{
	int l = 0, r = n, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (num[mid] <= val) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	return ans;
}


class Interval
{
public:
	int r, cost;
} itvs[LIMIT];
int operator< (const Interval& a, const Interval& b)
{
	return a.r > b.r;
}

int heap[LIMIT], cnt;
int cmp(int a, int b)
{
	return a > b;
}
void insert(int val)
{
	heap[cnt++] = val;
	std :: push_heap(heap, heap + cnt, cmp);
}
int remove()
{
	if (cnt == 0) {
		printf("JiNiTaiMei!");
		exit(0);
	}
	std :: pop_heap(heap, heap + cnt, cmp);
	return heap[--cnt];
}

int main()
{
	_FILE(kun);

	int n = gi, m = gi;
	for (int i = 0; i < n; i++) num[i] = gi;
	std :: sort(num, num + n);
	num[n] = INF;
	for (int i = 0; i < m; i++) {
		int d = gi, c = gi;
		itvs[i] = (Interval) {d, c};
	}
	std :: sort(itvs, itvs + m);

	int index = 0, ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (index != m && itvs[index].r >= num[i])
			insert(itvs[index++].cost);
		ans += remove();
	}

	std :: cout << ans;

	return 0;
}
