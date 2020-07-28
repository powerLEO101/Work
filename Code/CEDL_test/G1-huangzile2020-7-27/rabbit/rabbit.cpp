/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 3e5;
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

int flag, vis[MAXN], dist[MAXN], path[MAXN];

class Edge
{
public:
  int next, to, value, qaq;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to, int value)
{
  edges[eNum] = (Edge) {head[from], to, value, 0};
  head[from] = eNum++;
}

void dijkstra()
{
  memset(dist, 0x3f, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  std::priority_queue<std::pair<int, int> > Q;
  dist[0] = 0;
  Q.push(std::make_pair(0, 0));
  while (!Q.empty()) {
    int now = Q.top().second; Q.pop();
    if (vis[now] == true) continue;
    vis[now] = true;
    for (int i = head[now]; i != -1; i = edges[i].next) {
      int to = edges[i].to, value = edges[i].value;
      if (dist[to] <= dist[now] + value || edges[i].qaq == 1) continue;
      dist[to] = dist[now] + value;
      if (flag == 1) path[to] = i;
      Q.push(std::make_pair(-dist[to], to));
    }
  }
}

int main() 
{
	_FILE(rabbit);

  memset(head, -1, sizeof(head));

  int n = gi, m = gi;
  for (int i = 0; i < m; i++) {
    int from = gi - 1, to = gi - 1, value = gi;
    addEdge(from, to, value);
    addEdge(to, from, value);
  }
  flag = 1;
  dijkstra();
  flag = 0;
  for (int i = 1; i < n; i++) {
    edges[path[i]].qaq = edges[path[i] ^ 1].qaq = 1;
    dijkstra();
    if (dist[i] == 0x3f3f3f3f) std::cout << -1 << std::endl;
    else std::cout << dist[i] << std::endl;
    edges[path[i]].qaq = edges[path[i] ^ 1].qaq = 0;
  }

	return 0;
}
