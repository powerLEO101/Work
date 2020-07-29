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
const int MAXN = 4000, MAXM = 9000000;
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

bool vis[MAXN], dead[MAXN];

class Edge
{
public:
  int next, to;
} edges[MAXM];
int head[MAXN], eNum;
void addEdge(int from, int to)
{
  edges[eNum] = (Edge) {head[from], to};
  head[from] = eNum++;
}

int main() 
{
	_FILE(code);

  memset(head, -1, sizeof(head));
  int n = gi, m = gi;
  for (int i = 0; i < m; i++) {
    int from = gi - 1, to = gi - 1;
    addEdge(from, to);
    addEdge(to, from);
  }
  for (int i = 0; i < n; i++) {
    if (dead[i] == true) continue;
    memset(vis, 0, sizeof(vis));
    for (int j = head[i]; j != -1; j = edges[j].next) {
      int to = edges[j].to;
      vis[to] = true;
    }
    vis[i] = true;
    for (int j = 0; j < n; j++) {
      if (vis[j] == true || dead[j] == true) continue;
      dead[i] = true;
      dead[j] = true;
      break;
    }
  }
  int cnt = n / 3;
  for (int i = 0; i < n; i++) {
    if (dead[i] == true) continue;
    std::cout << i + 1 << ' ';
    cnt--;
    if (cnt == 0) return 0;
  }

	return 0;
}
