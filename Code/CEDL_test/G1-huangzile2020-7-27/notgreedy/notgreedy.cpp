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
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 1e6 + 1;
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

std::bitset<1000001> f[2];

int main() 
{
	_FILE(notgreedy);

  int n = gi;
  int index = 0;
  f[index][0] = 1;
  for (int i = 1; i <= n; i++) {
    int a = gi, b = gi;
    f[index ^ 1].reset();
    for (int j = a; j <= b; j++) {
      f[index ^ 1] |= (f[index] << j * j);
    }
    index ^= 1;
  }

  int ans = 0;
  for (int i = 0; i < MAXN; i++) 
    if (f[index][i]) ans++;
  std::cout << ans;

	return 0;
}
