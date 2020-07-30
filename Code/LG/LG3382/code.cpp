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
double eps = 0.00000001;
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
double l, r, num[20];

double pow(double x, int y)
{
  double ans = 1;
  while (y--)
    ans *= x;
  return ans;
}
double fun(double x)
{
  double ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += num[i] * pow(x, i);
  }
  return ans;
}

int main() 
{
	_FILE(code);

  n = gi;
  std::cin >> l >> r;
  for (int i = n; i >= 0; i--)
    std::cin >> num[i];
  while ((r - l) > eps) {
    double p = l + (r - l) / 3, q = r - (r - l) / 3;
    double fP = fun(p), fQ = fun(q);
    if (fP < fQ) {
      l = p;
    } else {
      r = q;
    }
  }
  printf("%.5f", l);

	return 0;
}
