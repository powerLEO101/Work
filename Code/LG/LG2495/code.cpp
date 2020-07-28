/**************************
 * Author : Leo101
 * Problem :
 * Tags :
 **************************/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <stack>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 3e5;
#define gi get_int()
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
int up[MAXN][21], deep[MAXN], min[MAXN][21], dfn[MAXN], dp[MAXN], num[MAXN], tot;

class Edge
{
  public:
    int next, to, value;
} edges[MAXN], edges1[MAXN];
int head[MAXN], head1[MAXN], eNum, eNum1;
void addEdge(int from, int to, int value)
{
  edges[eNum] = (Edge) {head[from], to, value};
  head[from] = eNum++;
}
void addEdge1(int from, int to, int value)
{
  edges1[eNum1] = (Edge) {head1[from], to, value};
  head1[from] = eNum1++;
}

void dfs(int now, int pre = -1)
{
  dfn[now] = tot++;
  for (int i = head1[now]; i != -1; i = edges1[i].next) {
    int to = edges1[i].to, value = edges1[i].value;
    if (to == pre) continue;
    deep[to] = deep[now] + 1;
    up[to][0] = now;
    min[to][0] = value;
    dfs(to, now);
  }
}

int cmp(const int& a, const int& b)
{
  return dfn[a] < dfn[b];
}

void move(int &u, int &v)
{
  if (deep[u] < deep[v]) std::swap(u, v);
  for (int i = 20; i >= 0; i--) {
    if (deep[up[u][i]] >= deep[v]) {
      u = up[u][i];
    }
  }
}
int LCA(int u, int v)
{
  move(u, v);
  for (int i = 20; i >= 0; i--) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return u == v ? u : up[u][0];
}

void getAns(int now = 0)
{
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to, value = edges[i].value;
    getAns(to);
    if (head[to] == -1) dp[now] += value;
    else dp[now] += std::min(dp[to], value);
  }
}

int getValue(int u, int v)
{
  int ans = 0x3f3f3f3f;
  if (deep[u] < deep[v]) std::swap(u, v);
  for (int i = 20; i >= 0; i--) {
    if (deep[up[u][i]] >= deep[v]) {
      u = up[u][i];
      ans = std::min(ans, min[u][i]);
    }
  }
  return ans;
}
int main() 
{
  _FILE(code);
  return 0;

  memset(head1, -1, sizeof(head1));

  int n = gi;
  for (int i = 1; i < n; i++) {
    int from = gi - 1, to = gi - 1, value = gi;
    addEdge1(from, to, value);
    addEdge1(to, from, value);
  }
  dfs(0);
  for (int j = 1; j < 21; j++)
    for (int i = 0; i < n; i++)
      up[i][j] = up[up[i][j - 1]][j - 1],
      min[i][j] = std::min(min[i][j - 1], min[up[i][j - 1]][j - 1]);
      int m = gi;
      while (m--) {
        eNum = 0;
        memset(head, -1, sizeof(head));
        memset(dp, 0, sizeof(dp));
        int k = gi;
        for (int i = 0; i < k; i++) num[i] = gi;
        std::sort(num, num + k, cmp);
        std::stack<int> S;
        S.push(0);
        for (int i = 0; i < k; i++) {
          int lca = LCA(num[i], S.top());
          while (S.top() != lca) {
            int tmp = S.top();
            S.pop();
            if (dfn[S.top()] < dfn[lca]) {
              S.push(lca);
            }
            addEdge(S.top(), tmp, getValue(S.top(), tmp));
          }
          S.push(num[i]);
        }
        while (S.top() != 0) {
          int tmp = S.top(); S.pop();
          addEdge(S.top(), tmp, getValue(S.top(), tmp));
        }
        getAns();
        std::cout << dp[0];
      }

      return 0;
}
