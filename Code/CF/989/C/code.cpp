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

int num[4];

int main() 
{
	_FILE(code);

  std::cin >> num[3] >> num[0] >> num[1] >> num[2];
  std::cout << "44 49\n";
  for (int i = 0; i < 4; i++) {
    char ch = 'A' + i, ex = i == 3 ? 'A' : ch + 1;
    for (int j = 0; j < 5; j++, std::cout << ch << std::endl) {
      for (int i = 0; i < 49; i++) std::cout << ch;
      std::cout << std::endl;
      for (int k = 0; k < 24; k++) std::cout << ch << (--num[i] > 0 ? ex : ch);
    }
    for (int i = 0; i < 49; i++) std::cout << ch;
    std::cout << std::endl;
  }

	return 0;
}
