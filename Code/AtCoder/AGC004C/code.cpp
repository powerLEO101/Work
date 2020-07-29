#include <iostream>
#include <cstdio>
#include <cstring>

const int MAXN = 500;

int n, m;
char a[MAXN + 2][MAXN + 2], b[MAXN + 2][MAXN + 2];

int main() {
  // freopen("code.in", "r", stdin);
  // freopen("code.out", "w", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i] + 1);
    for (int j = 1; j <= m; ++j) b[i][j] = a[i][j];
  }
  for (int i = 1; i <= n; i += 2) for (int j = 1; j < m; ++j) a[i][j] = '#';
  for (int i = 1; i <= m; ++i) a[i][1] = '#';
  for (int i = 2; i <= n; i += 2) for (int j = 2; j <= m; ++j) b[i][j] = '#';
  for (int i = 1; i <= m; ++i) b[i][m] = '#';
  for (int i = 1; i <= n; ++i) printf("%s\n", a[i] + 1);
  printf("\n");
  for (int i = 1; i <= n; ++i) printf("%s\n", b[i] + 1);
  return 0;
}
