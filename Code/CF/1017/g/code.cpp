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
const int MAXN = 2e5 + 10;
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

int dfn[MAXN], size[MAXN], fa[MAXN], son[MAXN], top[MAXN], deep[MAXN], cnt, n, q;

class Edge
{
public:
  int next, to;
} edges[MAXN * 4];
int head[MAXN], eNum;
void addEdge(int from, int to)
{
  edges[eNum] = (Edge) {head[from], to};
  head[from] = eNum++;
}

int tree[MAXN * 4], lazyTag[MAXN * 4], max[MAXN * 4];
void buildTree(int now = 1, int lRange = 0, int rRange = n)
{
  if (lRange == rRange - 1) {
    tree[now] = -1;
    max[now] = -1;
    return ;
  }
  int mid = (lRange + rRange) / 2;
  buildTree(now << 1, lRange, mid);
  buildTree(now << 1 | 1, mid, rRange);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
  max[now] = std::max(max[now << 1 | 1], tree[now << 1 | 1] + max[now << 1]);
}
void pushdown(int now, int lRange, int rRange)
{
  /*
  if (now < 0) {
    std::cout << now << ' ' << lRange << ' ' << rRange;
    exit(0);
  }
  */
  if (lazyTag[now] == 0) return ;
  lazyTag[now << 1] = lazyTag[now << 1 | 1] = -1;
  max[now << 1] = max[now << 1 | 1] = -1;
  int mid = (lRange + rRange) / 2;
  tree[now << 1] = -1 * (mid - lRange);
  tree[now << 1 | 1] = -1 * (rRange - mid);
  lazyTag[now] = 0;
}
void modify(int l, int r, int value, int now = 1, int lRange = 0, int rRange = n)
{
  if (r <= lRange || rRange <= l) return ;
  if (l <= lRange && rRange <= r) {
    tree[now] = (rRange - lRange) * value;
    max[now] = -1;
    lazyTag[now] = value;
    pushdown(now, lRange, rRange);
    return ;
  }
  pushdown(now, lRange, rRange);
  int mid = (lRange + rRange) / 2;
  modify(l, r, value, now << 1, lRange, mid);
  modify(l, r, value, now << 1 | 1, mid, rRange);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
  max[now] = std::max(max[now << 1 | 1], tree[now << 1 | 1] + max[now << 1]);
}
void add(int index, int value, int now = 1, int lRange = 0, int rRange = n)
{
  if (index < lRange || index >= rRange) return ;
  if (lRange == rRange - 1) {
    tree[now] += value;
    max[now] += value;
    return ;
  }
  pushdown(now, lRange, rRange);
  int mid = (lRange + rRange) / 2;
  add(index, value, now << 1, lRange, mid);
  add(index, value, now << 1 | 1, mid, rRange);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
  max[now] = std::max(max[now << 1 | 1], tree[now << 1 | 1] + max[now << 1]);
}
std::pair<int, int> query(int l, int r, int now = 1, int lRange = 0, int rRange = n)
{
  if (r <= lRange || rRange <= l) return std::make_pair(-1e9, -1);
  if (l <= lRange && rRange <= r) {
    //std::cout << lRange << ' ' << rRange << ' ' << l << ' ' << r << ' ' << tree[now] << ' ' << max[now]<< std::endl;
    return std::make_pair(tree[now], max[now]);
  }
  pushdown(now, lRange, rRange);
  int mid = (lRange + rRange) / 2;
  std::pair<int, int> left = query(l, r, now << 1, lRange, mid),
                      right = query(l, r, now << 1 | 1, mid, rRange);
  if (left.first == -1e9) return right;
  if (right.first == -1e9) return left;
  return std::make_pair(left.first + right.first, std::max(right.second, right.first + left.second));
}
void dfs1(int now = 0, int pre = -1)
{
  size[now] = 1;
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    deep[to] = deep[now] + 1;
    dfs1(to, now);
    size[now] += size[to];
    if (son[now] == -1) son[now] = to;
    else son[now] = size[son[now]] > size[to] ? son[now] : to;
  }
}
void dfs2(int now = 0, int pre = 0)
{
  dfn[now] = cnt++;
  top[now] = pre;
  if (son[now] != -1)
    dfs2(son[now], pre);
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == fa[now] || to == son[now]) continue;
    dfs2(to, to);
  }
}

int main() 
{
  _FILE(code);

  memset(son, -1, sizeof(son));
  memset(head, -1, sizeof(head));
  //std::cout << query(0, 5).first << ' ' << query(0, 5).second << std::endl;
  n = gi, q = gi;
  buildTree();
  for (int i = 1; i < n; i++) {
    int to = gi - 1;
    addEdge(to, i);
    fa[i] = to;
  }
  dfs1();
  dfs2();
  while (q--) {
    int mode = gi;
    if (mode == 1) {
      int x = gi - 1;
      add(dfn[x], 1);
    }
    if (mode == 2) {
      int x = gi - 1, bak = x, sum = 0, ans = -0x3f3f3f3f;
      modify(dfn[x], dfn[x] + size[x], -1);
      while (top[x] != 0) {
        std::pair<int, int> tmp = query(dfn[top[x]], dfn[x] + 1);
        ans = std::max(ans, sum + tmp.second);
        sum += tmp.first;
        x = fa[top[x]];
      }
      std::pair<int, int> tmp = query(0, dfn[x] + 1);
      ans = std::max(ans, sum + tmp.second);
      add(dfn[bak], -ans - 1);
    }
    if (mode == 3) {
      int x = gi - 1, sum = 0, ans = -0x3f3f3f3f;
      while (top[x] != 0) {
        std::pair<int, int> tmp = query(dfn[top[x]], dfn[x] + 1);
        ans = std::max(ans, sum + tmp.second);
        sum += tmp.first;
        x = fa[top[x]];
      }
      std::pair<int, int> tmp = query(0, dfn[x] + 1);
      ans = std::max(ans, sum + tmp.second);
      if (ans < 0) 
        std::cout << "white";
      else 
        std::cout << "black";
      std::cout << std::endl;
    }
  }

  return 0;
}

