/**************************
 * Author : Leo101
 * Problem : Luogu2605 [ZJOI2010]基站选址
 * Tags : dp, 线段树
 **************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin);freopen(#s".out", "w", stdout)
#define INF 0x3f3f3f3f
#define int long long
const int MAXN = 1e5;
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

int n, K;
int d[MAXN], s[MAXN], c[MAXN], w[MAXN];
int st[MAXN], ed[MAXN], dp[MAXN];

int binarySearchL(int index, int value)
{
  int l = 0, r = index + 1, ans = index;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (d[index] - d[mid] >= value) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return ans;
}
int binarySearchR(int index, int value)
{
  int l = index, r = n, ans = index;
  while (l < r - 1) {
    int mid = (l + r) / 2;
    if (d[mid] - d[index] >= value) {
      ans = mid;
      r = mid;
    } else {
      l = mid;
    }
  }
  return ans;
}

class Edge
{
public:
  int next, to;
} edges[MAXN];
int head[MAXN], edgesNum;
void addEdge(int from, int to)
{
  edges[edgesNum] = (Edge) {head[from], to};
  head[from] = edgesNum++;
}

class Node
{
  public:
    int value, tag;
} nodes[MAXN << 1];
void buildTree(int l = 0, int r = n, int root = 1)
{
  nodes[root].tag = 0;
  if (l == r - 1) {
    nodes[root].value = dp[l];
    nodes[root].tag = 0;
    return ;
  }
  int mid = (l + r) / 2;
  buildTree(l, mid, root << 1);
  buildTree(mid, r, root << 1 | 1);
  nodes[root].value = std :: min(nodes[root << 1].value,\
                                 nodes[root << 1 | 1].value);
}
void pushDown(int root)
{
  if (nodes[root].tag == 0) return ;
  nodes[root << 1].value += nodes[root].tag;
  nodes[root << 1 | 1].value += nodes[root].tag;
  nodes[root << 1].tag += nodes[root].tag;
  nodes[root << 1 | 1].tag += nodes[root].tag;
  nodes[root].tag = 0;
}
void modifyTree(int qL, int qR, int value, int l = 0, int r = n, int root = 1)
{
  if (qR <= qL) return ;
  if (qR <= l || r <= qL) return ;
  if (qL <= l && r <= qR) {
    nodes[root].value += value;
    nodes[root].tag += value;
    return ;
  }
  pushDown(root);
  int mid = (l + r) / 2;
  modifyTree(qL, qR, value, l, mid, root << 1);
  modifyTree(qL, qR, value, mid, r, root << 1 | 1);
  nodes[root].value = std :: min(nodes[root << 1].value,\
                                 nodes[root << 1 | 1].value);
}
int queryTree(int qL, int qR, int l = 0, int r = n, int root = 1)
{
  if (qR <= qL) return INF;
  if (qR <= l || r <= qL) return INF;
  if (qL <= l && r <= qR) return nodes[root].value;
  pushDown(root);
  int mid = (l + r) / 2;
  return std :: min(queryTree(qL, qR, l, mid, root << 1),\
                    queryTree(qL, qR, mid, r, root << 1 | 1));
}

signed main()
{
  _FILE(code);

  memset(head, -1, sizeof(head));

  n = gi, K = gi + 1;
  for (int i = 1; i < n; ++i) d[i] = gi;
  for (int i = 0; i < n; ++i) c[i] = gi;
  for (int i = 0; i < n; ++i) s[i] = gi;
  for (int i = 0; i < n; ++i) w[i] = gi;
  d[n] = w[n] = INF;
  n++;

  for (int i = 0; i < n; ++i) {
    // st[i] = binarySearchL(i, s[i]);
    // ed[i] = binarySearchR(i, s[i]);
    st[i] = std :: lower_bound(d, d + n, d[i] - s[i]) - d;
    ed[i] = std :: lower_bound(d, d + n, d[i] + s[i]) - d;
    if (d[ed[i]] > d[i] + s[i]) ed[i]--;
    addEdge(ed[i], i);
  }

  int total = 0;
  for (int i = 0; i < n; ++i) {
    dp[i] = total + c[i];
    for (int j = head[i]; j != -1; j = edges[j].next) {
      int to = edges[j].to;
      total += w[to];
    }
  }

  int ans = dp[n - 1];
  for (int j = 2; j <= K; ++j) {
    buildTree();
    for (int i = 0; i < j - 1; i++) dp[i] = INF;
    for (int i = j - 1; i < n; ++i) {
      dp[i] = queryTree(j - 2, i) + c[i];
      for (int k = head[i]; k != -1; k = edges[k].next) {
        int to = edges[k].to;
        modifyTree(0, st[to], w[to]);
      }
    }
    ans = std :: min(ans, dp[n - 1]);
  }

  std :: cout << ans;

  return 0;
}
