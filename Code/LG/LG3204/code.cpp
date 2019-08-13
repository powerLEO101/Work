/**************************
 * Author : Leo101
 * Problem : Luogu3204 [HNOI2010]公交线路
 * Tags : dp, 矩阵快速幂
 **************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin);freopen(#s".out", "w", stdout)
#define MOD 30031
const int MAXP = 127;
int get_int() {
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

int start[MAXP];

class Matrix {
  int value[MAXP][MAXP];
public:
  int * operator[] (int index);
  Matrix operator^ (int num);
  Matrix() {
    memset(value, 0, sizeof(value));
  }
} ans, trans;
int * Matrix::operator[] (int index) {
  return value[index];
}
Matrix operator* (Matrix lhs, Matrix rhs) {
  Matrix ans;
  for (int i = 0; i < MAXP; ++i) {
    for (int j = 0; j < MAXP; ++j) {
      for (int k = 0; k < MAXP; ++k) {
        (ans[i][k] += lhs[i][j] * rhs[j][k]) %= MOD;
      }
    }
  }
  return ans;
}
Matrix operator*= (Matrix& lhs, Matrix rhs) {
  lhs = lhs * rhs;
  return lhs;
}
Matrix Matrix::operator^ (int num) {
  Matrix ans = *this, base = *this;
  num--;
  while (num != 0) {
    if ((num & 1) == 1)
      ans = ans * base;
    base = base * base;
    num >>= 1;
  }
  return ans;
}

int getValue(int x) {
  int ans = 0;
  while (x != 0) {
    ans += x & 1;
    x >>= 1;
  }
  return ans;
}

int main() {
  _FILE(code);

  int n = gi, k = gi, p = gi, end = 0, cnt = 0;
  for (int i = 1 << (p - 1); i < 1 << p; ++i) {
    if (getValue(i) == k) {
      start[cnt++] = i;
      if (i == ((1 << k) - 1) << (p - k)) {
        ans[0][cnt - 1] = 1;
        end = cnt - 1;
      }
    }
  }
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < cnt; ++j) {
      if (getValue(((start[i] ^ (1 << (p - 1))) << 1) ^ start[j]) == 1) {
        trans[i][j] = 1;
      }
    }
  }

  ans = ans * (trans ^ (n - k));
  
  std::cout << ans[0][end];

  return 0;
}
