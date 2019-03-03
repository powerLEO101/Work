/**************************
  * Writer : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int main()
{
	File(c);

	std :: string Str;
	std :: cin >> Str;

	int Len = Str.size(), Ans = 0;
	if (Len == 0) {
		printf("0");
		return 0;
	}
	std :: stack<int> Stack;
	Stack.push(Str[0] - '0');
	for (int i = 1; i < Len; i++) {
		int Now = Str[i] - '0';
		if (Stack.empty()) Stack.push(Now);
		else if (Now != Stack.top()) {
			Stack.pop();
			Ans += 2;
		} else {
			Stack.push(Now);
		}
	}

	printf("%d", Ans);

	return 0;
}

