/**************************
  * Author : Leo101
  * Problem : Luogu P1155 双栈排序
  * Tags : 模拟，栈
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 1001, MAXM = 1001 * 1001;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int minValue[MAXN], color[MAXN], num[MAXN], pos = 1;
std :: stack<int> stack[2];

class Edge
{
public:
	int next, to;
} edges[MAXM];
int head[MAXN], edgesNum;
void addEdge(int from, int to)
{
	edges[edgesNum] = (Edge) {head[from], to};
	head[from] = edgesNum++;
}

bool vis[MAXN];
void match(int now)
{
	std :: queue<int> q;
	q.push(now);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edges[i].next) {
			int to = edges[i].to;
			if (~color[to] && color[to] != (color[u] ^ 1)) {
				printf("0");
				exit(0);
			}
			if (!~color[to]) q.push(to);
			color[to] = color[u] ^ 1;
		}
	}
}

bool pop(int col)
{
	if (!stack[col].empty() && stack[col].top() == pos) {
		printf("%c ", col == 1 ? 'd' : 'b');
		stack[col].pop();
		pos++;
		return true;
	}
	return false;
}
bool popUntil(int col)
{
	bool flag = false;
	while (pop(col)) flag = true;
	return flag;
}
void pushIntoStack(int now, int col)
{
	if (col == 1) popUntil(0);
	while (!stack[col].empty() && stack[col].top() < now)
		if (!pop(col)) pop(col ^ 1);
	if (col == 1) popUntil(0);
	stack[col].push(now); 
	printf("%c ", col == 1 ? 'c' : 'a');
}

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));

	int n = gi;
	for (int i = 1; i <= n; i++) num[i] = gi;
	minValue[n + 1] = n + 1;
	for (int i = n; i >= 1; i--)
		minValue[i] = std :: min(minValue[i + 1], num[i]);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if (minValue[j + 1] < num[i] && num[i] < num[j]) {
				addEdge(i, j); addEdge(j, i);
				color[i] = color[j] = -1;
			}

	for (int i = 1; i <= n; i++) {
		if (color[i] != -1) continue;
		color[i] = 0;
		match(i);
	}

	for (int i = 1; i <= n; i++)
		pushIntoStack(num[i], color[i]);

	while (popUntil(0) || popUntil(1)) ;

	return 0;
}
