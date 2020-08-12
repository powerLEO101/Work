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

int num[MAXN], bookL[MAXN], bookR[MAXN], block[MAXN], ans[MAXN], res, qCnt;

class Query
{
public:
  int l, r, index, opt;
} Q[MAXN];
int operator< (const Query& a, const Query& b)
{
  if (block[a.l] == block[b.l]) 
    return block[a.l] & 1 ? a.r < b.r : a.r > b.r;
  return a.l < b.l;
}

void insertR(int value)
{
  bookR[value]++;
  res += bookL[value];
}
void insertL(int value)
{
  bookL[value]++;
  res += bookR[value];
}
void removeR(int value)
{
  bookR[value]--;
  res -= bookL[value];
}
void removeL(int value)
{
  bookL[value]--;
  res -= bookR[value];
}

int main() 
{
  _FILE(code);

  int n = gi, blockBase = sqrt(n);
  for (int i = 1; i <= n; i++)
    num[i] = gi;
  for (int i = 0; i <= n; i++)
    block[i] = i / blockBase;
  int m = gi;
  for (int i = 0; i < m; i++) {
    int l1 = gi, r1 = gi, l2 = gi, r2 = gi;
    Q[qCnt++] = (Query) {r1, r2, i, 1};
    Q[qCnt++] = (Query) {r1, l2 - 1, i, 2};
    Q[qCnt++] = (Query) {l1 - 1, r2, i, 3};
    Q[qCnt++] = (Query) {l1 - 1, l2 - 1, i, 4};
  }
  for (int i = 0; i < qCnt; i++) {
    if (Q[i].l > Q[i].r) 
      std::swap(Q[i].l, Q[i].r);
  }
  std::sort(Q, Q + qCnt);
  int lNow = 0, rNow = 0;
  for (int i = 0; i < qCnt; i++) {
    int l = Q[i].l, r = Q[i].r, index = Q[i].index, opt = Q[i].opt;
    while (rNow < r) insertR(num[++rNow]);
    while (lNow < l) insertL(num[++lNow]);
    while (lNow > l) removeL(num[lNow--]);
    while (rNow > r) removeR(num[rNow--]);
    if (opt == 1 || opt == 4)
      ans[index] += res;
    else
      ans[index] -= res;
  }
  for (int i = 0; i < m; i++)
    std::cout << ans[i] << std::endl;

  return 0;
}

