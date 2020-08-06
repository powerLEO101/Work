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
#define int long long
const int MAXN = 5e4 + 10, MOD = 1e9 + 7;
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

int S[MAXN][303], C[303][303];

signed main() 
{
  _FILE(code);

  C[0][0] = 1;
  for (int i = 1; i < 203; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
  }
  S[0][0] = 1;
  for (int i = 1; i < 5e4; i++) {
    for (int j = 1; j <= 203; j++)
      S[i][j] = (S[i - 1][j - 1] + S[i - 1][j] * (i - 1)) % MOD;
  }
  int T = gi;
  while (T--) {
    int n = gi, A = gi, B = gi;
    std::cout << S[n - 1][A + B - 2] * C[A + B - 2][A - 1] % MOD << std::endl;
  }

  return 0;
}
