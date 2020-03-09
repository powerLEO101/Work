/**************************
  * Author : Leo101
  * Problem : BZOJ1001 [BeiJing2006]狼抓兔子
  * Tags : 网络流最小割
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 2e6, MAXN2 = 8e6;
int get_int() {
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int n, m, s, t;
int depth[MAXN], cur[MAXN];

int convert(int x, int y) {
  return x * m + y;
}

class Edge {
public:
  int next, to, value;
} edges[MAXN2];
int head[MAXN], eNum;
void addEdge(int from, int to, int value) {
  edges[eNum] = (Edge) {head[from], to, value};
  head[from] = eNum++;
}

int bfs() {
  std::queue<int> Q;
  memset(depth, -1, sizeof(depth));
  depth[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int now = Q.front();
    Q.pop();
    for (int i = head[now]; i != -1; i = edges[i].next) {
      int to = edges[i].to, value = edges[i].value;
      if (value <= 0 or depth[to] != -1) continue;
      depth[to] = depth[now] + 1;
      Q.push(to);
    }
  }
  if (depth[t] == -1) return false;
  return true;
}
int dfs(int now, int flow) {
  if (now == t) return flow;
  int total = 0;
  for (int &i = cur[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to, value = edges[i].value;
    if (depth[to] != depth[now] + 1 or value <= 0) continue;
    int ret = dfs(to, std::min(flow, value));
    if (ret > 0) {
      edges[i].value -= ret;
      edges[i ^ 1].value += ret;
      total += ret;
      flow -= ret;
    }
    if (flow == 0) break;
  }
  return total;
}
int Dinic() {
  int ans = 0;
  while (bfs()) {
    for (int i = s; i <= t; i++) cur[i] = head[i];
    ans += dfs(s, 0x3f3f3f3f);
  }
  return ans;
}

int main() {
	_FILE(code);

  memset(head, -1, sizeof(head));

  n = gi, m = gi;
  s = 0, t = convert(n - 1, m - 1);
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int value = gi;
      addEdge(convert(i, j - 1), convert(i, j), value);
      addEdge(convert(i, j), convert(i, j - 1), value);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int value = gi;
      addEdge(convert(i - 1, j), convert(i, j), value);
      addEdge(convert(i, j), convert(i - 1, j), value);
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int value = gi;
      addEdge(convert(i - 1, j - 1), convert(i, j), value);
      addEdge(convert(i, j), convert(i - 1, j - 1), value);
    }
  }

  printf("%d", Dinic());

	return 0;
}
