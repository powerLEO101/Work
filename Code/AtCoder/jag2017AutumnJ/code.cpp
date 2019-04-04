/**************************
  * Author : Leo101
  * Problem : Farm Village
  * Tags : 贪心
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
typedef long long LL;
#define int LL
const int MAXN = 200010;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int heap1[MAXN], heap2[MAXN], dist[MAXN], cnt1, cnt2;
int topHeap(int* heap, int &cnt)
{
	return heap[0];
}
int deleteHeap(int* heap, int &cnt)
{
	std :: pop_heap(heap, heap + cnt, std :: greater<int>());
	return heap[--cnt];
}
void insertHeap(int* heap, int val, int &cnt)
{
	heap[cnt++] = val;
	std :: push_heap(heap, heap + cnt, std :: greater<int>());
}

signed main()
{
	_FILE(code);

	int n = gi, ans = 0;
	for (int i = 1; i < n; i++) dist[i] = gi + dist[i - 1];
	for (int i = 0; i < n; i++) {
		int cost = gi;
		for (int j = 0; j < 2; j++) {
			int tmp = topHeap(heap1, cnt1) + dist[i] + cost;
			if (cnt1 != 0 && tmp < 0) {
				deleteHeap(heap1, cnt1); ans += tmp;
				insertHeap(heap1, -dist[i] - cost, cnt1);
				insertHeap(heap2, -dist[i] + cost - tmp, cnt2);
			} else {
				insertHeap(heap2, -dist[i] + cost, cnt2);
			}
		}
		int tmp = deleteHeap(heap2, cnt2) + dist[i];
		ans += tmp;
		insertHeap(heap1, -tmp - dist[i], cnt1);
	}

	printf("%lld\n", ans);

	return 0;
}
