/**************************
 * Author : Leo101
 * Problem :
 * Tags :
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 4e5 + 10;
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

int st[MAXN], ed[MAXN], rnk[MAXN], deep[MAXN], num[MAXN], block[MAXN], ans[MAXN], vis[MAXN], son[MAXN], size[MAXN], fa[MAXN],top[MAXN], cnt = 1;

class Data
{
public:
  int index, value;
} tmp[MAXN];
int operator< (const Data& a, const Data& b)
{
  return a.value < b.value;
}

class Edge
{
public:
  int next, to;
} edges[MAXN];
int head[MAXN], eNum = 1;
void addEdge(int from, int to)
{
  edges[eNum] = (Edge) {head[from], to};
  head[from] = eNum++;
}

void dfs(int now = 1, int pre = 0)
{
  fa[now] = pre;
  deep[now] = deep[pre] + 1;
  st[now] = cnt++;
  rnk[st[now]] = now;
  size[now] = 1;
  for (int i = head[now]; i != 0; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    dfs(to, now);
    size[now] += size[to];
    if (son[now] == 0) son[now] = to;
    else son[now] = size[son[now]] > size[to] ? son[now] : to;
  }
  ed[now] = cnt++;
  rnk[ed[now]] = now;
}
void dfs1(int now = 1, int pre = 1)
{
  top[now] = pre;
  if (son[now] != 0)
    dfs1(son[now], pre);
  for (int i = head[now]; i != 0; i = edges[i].next) {
    int to = edges[i].to;
    if (to == fa[now] || to == son[now])
      continue;
    dfs1(to, to);
  }
}

class Query
{
public:
  int from, to, index, lca, lBlock, rBlock;
} Q[MAXN];
int operator< (const Query& a, const Query& b)
{
  if (a.lBlock == b.lBlock) 
    return a.lBlock & 1 ? a.to < b.to : a.to > b.to;
  return a.from < b.from;
}

int LCA(int u, int v)
{
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) std::swap(u, v);
    u = fa[top[u]];
  }
  if (deep[u] < deep[v]) std::swap(u, v);
  return v;
}

int book[MAXN], res;
void insert(int value)
{
  if (book[value] == 0)
    res++;
  book[value]++;
}
void remove(int value)
{
  book[value]--;
  if (book[value] == 0)
    res--;
}
void work(int value)
{
  vis[value] == 1 ? remove(num[value]) : insert(num[value]);
  vis[value] ^= 1;
}

int main() 
{
  _FILE(code);

  int n = gi, m = gi, blockBase = n * 2 / sqrt(m * 2 / 3);
  for (int i = 1; i <= n; i++) {
    tmp[i].index = i;
    tmp[i].value = gi;
  }
  std::sort(tmp + 1, tmp + n + 1);
  int tmpValue = 0;
  for (int i = 1; i <= n; i++) {
    num[tmp[i].index] = tmpValue;
    if (tmp[i].value != tmp[i + 1].value)
      tmpValue++;
  }
  for (int i = 1; i < n; i++) {
    int from = gi, to = gi;
    addEdge(from, to);
    addEdge(to, from);
  }
  dfs();
  dfs1();
  for (int i = 1; i <= m; i++) {
    int from = gi, to = gi;
    int lca = LCA(from, to);
    if (st[from] > st[to]) 
      std::swap(from, to);
    if (lca == from || lca == to) {
      Q[i].from = st[from];
      Q[i].to = st[to];
      Q[i].index = i;
      Q[i].lca = -1;
      Q[i].lBlock = st[from] / blockBase;
      Q[i].rBlock = st[to] / blockBase;
    } else {
      Q[i].from = ed[from];
      Q[i].to = st[to];
      Q[i].index = i;
      Q[i].lca = lca;
      Q[i].lBlock = ed[from] / blockBase;
      Q[i].rBlock = st[to] / blockBase;
    }
  }
  std::sort(Q + 1, Q + m + 1);
  int lNow = 1, rNow = 0;
  for (int i = 1; i <= m; i++) {
    int l = Q[i].from, r = Q[i].to, index = Q[i].index, lca = Q[i].lca;
    while (lNow > l) work(rnk[--lNow]);
    while (rNow < r) work(rnk[++rNow]);
    while (lNow < l) work(rnk[lNow++]);
    while (rNow > r) work(rnk[rNow--]);
    if (lca != -1)
      work(lca);
    ans[index] = res;
    if (lca != -1)
      work(lca);
  }
  for (int i = 1; i <= m; i++)
    std::cout << ans[i] << std::endl;

  return 0;
}
