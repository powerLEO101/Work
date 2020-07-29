/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 2e6 + 10;
int get_int() 
{
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

int ans[MAXN], vis[MAXN];

class Edge
{
public:
  int next, to;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to)
{
  edges[eNum] = (Edge) {head[from], to};
  head[from] = eNum++;
}

void dfs(int now, int dis = 2, int pre = -1)
{
  vis[now] = true;
  if (dis == 0) return ;
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    dfs(to, dis - 1, now);
  }
}

int main() 
{
	_FILE(code);

  memset(head, -1, sizeof(head));
  int n = gi, m = gi, k = gi;
  for (int i = 0; i < m; i++) {
    int from = gi - 1, to = gi - 1;
    addEdge(from, to);
    addEdge(to, from);
  }
  int tot = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == true) continue;
    dfs(i);
    ans[tot++] = i;
  }
  std::cout << tot << std::endl;
  for (int i = 0; i < tot; i++)
    std::cout << ans[i] + 1 << ' ';

	return 0;
}
