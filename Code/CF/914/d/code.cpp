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
const int MAXN = 3e6;
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

int n;

int gcd(int x, int y)
{
  return y == 0 ? x : gcd(y, x % y);
}

int tree[MAXN];
void buildTree(int now = 1, int lRange = 0, int rRange = n)
{
  if (lRange == rRange - 1) {
    tree[now] = gi;
    return ;
  }
  int mid = (lRange + rRange) / 2;
  buildTree(now << 1, lRange, mid);
  buildTree(now << 1 | 1, mid, rRange);
  tree[now] = gcd(tree[now << 1], tree[now << 1 | 1]);
}
void modify(int index, int value, int now = 1, int lRange = 0, int rRange = n)
{
  if (index < lRange || index >= rRange) return ;
  if (lRange == rRange - 1) {
    tree[now] = value;
    return ;
  }
  int mid = (lRange + rRange) / 2;
  modify(index, value, now << 1, lRange, mid);
  modify(index, value, now << 1 | 1, mid, rRange);
  tree[now] = gcd(tree[now << 1], tree[now << 1 | 1]);
}
int query(int l, int r, int x, int now = 1, int lRange = 0, int rRange = n)
{
  if (r <= lRange || rRange <= l) return 0;
  if (lRange == rRange - 1) return 1;
  int mid = (lRange + rRange) / 2;
  int ans = 0;
  if (tree[now << 1] % x != 0) 
    ans += query(l, r, x, now << 1, lRange, mid);
  if (ans >= 2) return ans;
  if (tree[now << 1 | 1] % x != 0)
    ans += query(l, r, x, now << 1 | 1, mid, rRange);
  return ans;
}

int main() 
{
  _FILE(code);

  n = gi;
  buildTree();
  int m = gi;
  while (m--) {
    int mode = gi;
    if (mode == 1) {
      int l = gi - 1, r = gi, x = gi;
      int tmp = query(l, r, x);
      if (tmp <= 1) printf("YES\n");
      else printf("NO\n");
    }
    if (mode == 2) {
      int index = gi - 1, value = gi;
      modify(index, value);
    }
  }

  return 0;
}
