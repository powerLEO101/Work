/**************************
 * Author : Leo101
 * Problem :
 * Tags :
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <vector>
#include <cmath>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int LIM = 300, MAXN = 1e5;
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

int block[MAXN + 5], num[MAXN + 5], count[MAXN + 5], pre[MAXN + 5], maxL[MAXN + 5], ans[MAXN + 5];
std::bitset<100005> bs1, bs2;
std::vector<int> Ql[LIM + 1], Qr[LIM + 1], Qi[LIM + 1];

class Data
{
public:
  int l, r, x, index, opt;
} Q[MAXN];
bool operator< (const Data& a, const Data& b)
{
  if (block[a.l] == block[b.l]) 
    return block[a.l] & 1 ? a.r < b.r : a.r > b.r;
  return a.l < b.l;
}
int cnt;

void insert(int value)
{ 
  if (!count[value]) bs1[value] = 1, bs2[MAXN - value] = 1; 
  count[value]++;
}
void remove(int value)
{
  count[value]--;
  if (count[value] == 0)
    bs1[value] = 0, bs2[MAXN - value] = 0;
}

int main() 
{
  _FILE(code);

  int n = gi, m = gi, blockBase = sqrt(n);
  for (int i = 0; i < n; i++)
    block[i] = i / blockBase;
  for (int i = 0; i < n; i++)
    num[i] = gi;
  for (int i = 0; i < m; i++) {
    int opt = gi, l = gi - 1, r = gi - 1, x = gi;
    if (opt == 4 && x <= LIM) {
      Ql[x].push_back(l);
      Qr[x].push_back(r);
      Qi[x].push_back(i);
    } else {
      Q[cnt++] = (Data){l, r, x, i, opt};
    }
  }
  // normal cases below
  std::sort(Q, Q + cnt);
  int nowL = 0, nowR = -1;
  for (int i = 0; i < cnt; i++) {
    int l = Q[i].l, r = Q[i].r, x = Q[i].x;
    while (nowR < r) insert(num[++nowR]);
    while (nowR > r) remove(num[nowR--]);
    while (nowL < l) remove(num[nowL++]);
    while (nowL > l) insert(num[--nowL]);
    if (Q[i].opt == 1)
      ans[Q[i].index] = ((bs1 << x) & bs1).any();
    if (Q[i].opt == 2)
      ans[Q[i].index] = ((bs1 << (MAXN - x)) & bs2).any();
    if (Q[i].opt == 3) {
      int flag = 0;
      for (int j = 1; j * j <= x; j++) {
        if (x % j == 0 && bs1[j] == 1 && bs1[x / j] == 1) {
          flag = 1;
          break;
        }
      }
      if (flag == 1) 
        ans[Q[i].index] = 1;
      else 
        ans[Q[i].index] = 0;
    }
    if (Q[i].opt == 4) {
      int flag = 0;
      for (int j = 1; j * x <= MAXN; j++) {
        if (bs1[j] == 1 && bs1[j * x] == 1) {
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        ans[Q[i].index] = 1;
      else
        ans[Q[i].index] = 0;
    }
  }
  // big division cases below
  for (int x = 1; x <= LIM; x++) {
    if (Qi[x].empty()) continue;
    int l = -1;
    memset(pre, -1, sizeof(pre));
    memset(maxL, -1, sizeof(maxL));
    for (int i = 0; i < n; i++) {
      int value = num[i];
      pre[value] = i;
      if (value * x <= MAXN)
        l = std::max(l, pre[value * x]);
      if (value % x == 0)
        l = std::max(l, pre[value / x]);
      maxL[i] = l;
    }
    for (int i = 0; i < Qi[x].size(); i++)
      ans[Qi[x][i]] = maxL[Qr[x][i]] >= Ql[x][i];
  }
  for (int i = 0; i < m; i++)
    puts(ans[i] == 1 ? "yuno" : "yumi");

  return 0;
}
