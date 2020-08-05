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
const int MAXN = 2e6;
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

int actL[MAXN], actR[MAXN], act[MAXN], n, m, q;

int tree[MAXN], tag[MAXN], num[MAXN];
void buildTree(int val, int now = 1, int lRange = 0, int rRange = n)
{
  if (lRange == rRange - 1) {
    tree[now] = num[lRange] > val;
    tag[now] = -1;
    return ;
  }
  int mid = (lRange + rRange) / 2;
  buildTree(val, now << 1, lRange, mid);
  buildTree(val, now << 1 | 1, mid, rRange);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
  tag[now] = -1;
}
void pushdown(int now, int lRange, int rRange)
{
  if (tag[now] == -1) return ;
  int mid = (lRange + rRange) / 2;
  tree[now << 1] = tag[now] * (mid - lRange);
  tree[now << 1 | 1] = tag[now] * (rRange - mid);
  tag[now << 1] = tag[now];
  tag[now << 1 | 1] = tag[now];
  tag[now] = -1;
}
void modify(int l, int r, int val, int now = 1, int lRange = 0, int rRange = n)
{
  if (r <= lRange || rRange <= l) return ;
  if (l <= lRange && rRange <= r) {
    tree[now] = val * (rRange - lRange);
    tag[now] = val;
  }
  pushdown(now, lRange, rRange);
  int mid = (lRange + rRange) / 2;
  modify(l, r, val, now << 1, lRange, mid);
  modify(l, r, val, now << 1 | 1, mid, rRange);
  tree[now] = tree[now << 1] + tree[now << 1 | 1];
}
int query(int l, int r, int now = 1, int lRange = 0, int rRange = n)
{
  if (r <= lRange || rRange <= l) return 0;
  if (l <= lRange && rRange <= r)
    return tree[now];
  pushdown(now, lRange, rRange);
  int mid = (lRange + rRange) / 2;
  return query(l, r, now << 1, lRange, mid) + 
  query(l, r, now << 1 | 1, mid, rRange);
}

int check(int val)
{
  buildTree(val);
  for (int i = 0; i < m; i++) {
    int tmp = query(actL[i], actR[i]);
    if (act[i] == 0) {
      modify(actR[i] - tmp, actR[i], 1);
      modify(actL[i], actR[i] - tmp, 0);
    } else {
      modify(actL[i], actL[i] + tmp, 1);
      modify(actL[i] + tmp, actR[i], 0);
    }
  }
  return query(q, q + 1);
}

int main() 
{
  _FILE(code);

  n = gi, m = gi;
  for (int i = 0; i < n; i++)
    num[i] = gi;
  for (int i = 0; i < m; i++) {
    act[i] = gi;
    actL[i] = gi - 1;
    actR[i] = gi;
  }
  q = gi - 1;
  int l = 0, r = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (check(mid) == true) l = mid + 1;
    else r = mid - 1;
  }
  std::cout << l;

  return 0;
}
