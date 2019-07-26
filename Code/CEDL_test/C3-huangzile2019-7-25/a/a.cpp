#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int LIMIT = 5e5;
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

int value[LIMIT][21], up[LIMIT][21], count[LIMIT], sum[LIMIT], w[LIMIT];

class Edge
{
public:
	int next, to;
} edges[LIMIT];
int head[LIMIT], eNum;
void addEdge(int from, int to)
{
	edges[eNum] = (Edge) {head[from], to};
	head[from] = eNum++;
}

int getNode(int u, int val)
{
	for (int i = 20; i >= 0; i--) {
		if (val - value[u][i] >= 0) {
			val -= value[u][i];
			u = up[u][i];
		}
	}
	return u;
}

void getSum(int now)
{
	sum[now] = count[now];
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		getSum(to);
		sum[now] += sum[to];
	}
}

signed main()
{
	_FILE(a);

	memset(head, -1, sizeof(head));

	int n = gi;
	for (int i = 0; i < n; i++) w[i] = gi;
	for (int i = 1; i < n; i++) {
		int to = gi - 1, val = gi;	
		addEdge(to, i);
		up[i][0] = to;
		value[i][0] = val;
	}

	for (int j = 1; j < 21; j++)
		for (int i = 0; i < n; i++)
			up[i][j] = up[up[i][j - 1]][j - 1],
			value[i][j] = value[i][j - 1] + value[up[i][j - 1]][j - 1];


	for (int i = 1; i < n; i++) {
		int node = getNode(i, w[i]);
		count[up[i][0]]++;
		if (node != 0) count[up[node][0]]--;
	}

	getSum(0);

	for (int i = 0; i < n; i++) printf("%lld ", sum[i]);


	return 0;
}
