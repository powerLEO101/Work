#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int LIMIT = 2700000; 
const int MOD = 998244353;
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

int num[LIMIT], len;
int dp[5000000];

struct Queue {
	struct Node {
		int num, step;
		Node() : num(0) {}
		Node(int x) : num(x) {}
	} q[LIMIT << 1 | 1];
	int head, tail;
	Queue() : head(1), tail(0) {}
	void push(int x) {
		q[++tail] = Node(x);
	}
	void pop() {
		++head;
	}
	Node front() {
		return q[head];
	}
	void clear() {
		head = 1;
		tail = 0;
	}
	bool empty() {
		return head > tail;
	}
} Q;


void bfs()
{
	memset(dp, -1, sizeof(dp));
	Q.clear();
	Q.push(0);
	dp[0] = 0;
	while (!Q.empty()) {
		int now = Q.front().num;
		Q.pop();
		for (int i = 0; i < len; i++) {
			int val = now ^ num[i];
			if (dp[val] != -1) continue;
			Q.push(now ^ num[i]);
			dp[val] = dp[now] + 1;
		}
	}
}

signed main()
{
	_FILE(a);
	
	int T = gi;
	for (len = 0; len < 19; len++)
		num[len] = 1 << len;
	while (T--) {
		int n = gi, q = gi;
		long long ans = 0;
		len = 19;
		for (int i = 0; i < n; i++)
			num[len++] = gi;
		bfs();
		for (int i = 1; i <= q; i++) {
			int value = gi ^ gi;
			(ans += 1ll * i * dp[value]) %= MOD;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
