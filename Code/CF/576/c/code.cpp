/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
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

int cmp1(const std::pair<int, int> a, const std::pair<int, int> b)
{
  return a.second < b.second;
}
int cmp2(const std::pair<int, int> a, const std::pair<int, int> b)
{
  return a.second > b.second;
}

std::vector<std::pair<int, int> > numA[10000];

int main() 
{
	_FILE(code);

  int n = gi;
  for (int i = 0; i < n; i++) {
    int a = gi, b = gi;
    numA[a / 1000].push_back(std::make_pair(i + 1, b));
  }
  for (int i = 0; i <= 1000; i++) {
    if (i & 1) {
      std::sort(numA[i].begin(), numA[i].end(), cmp1);
    } else {
      std::sort(numA[i].begin(), numA[i].end(), cmp2);
    }
  }
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j < numA[i].size(); j++)
      std::cout << numA[i][j].first << ' ';
  }

	return 0;
}
