/**************************
  * Author : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)

int main()
{
	_FILE(tstones);

	unsigned long long T;
	std :: cin >> T;
	while (T--) {
		unsigned long long n, k;
		scanf("%llu %llu",& n,& k);
		if (k >= n) {
			printf("NO\n");
			continue;
		}
		if (n % (k + 1) == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}
