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

int check(int now)
{
}

int main() 
{
  _FILE(code);

  int T = gi;
  while (T--) {
    std::cin >> S0 >> S;
    int n = S0.size(), m = S.size();
    if (n < m) {
      std::cout << 0;
      continue;
    }
    p[0] = 1;
    for (int i = 1; i <= n; i++)
      p[i] = p[i - 1] * base;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
      f[i] = f[i - 1] * base + S0[i - 1];
    g[0] = 1;
    for (int i = 1; i <= m; i++)
      g[i] = g[i - 1] * base + S[i - 1];
    int ans = 0;
    for (int i = 1; i + m - 1 <= n; i++) {
      if (check(i - 1)) ans++;
    }
  }

  return 0;
}
