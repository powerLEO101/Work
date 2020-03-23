/**************************
  * Writer : Leo101
  * Problem : CF1042A Benches
  * Tags : 暴力
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)

int s[110];
int main(){
	File(code);
	int n, m;
	scanf("%d %d",& n,& m);
	for (int i = 0; i < n; i++) scanf("%d",& s[i]);
	std::sort(s, s + n);
	int mm = m;
	for (int i = 0; i < n; i++) mm -= s[n - 1] - s[i]; 
	if (mm <= 0) printf("%d ", s[n - 1]);
	else printf("%d ", mm % n ? s[n - 1] + mm / n + 1 : s[n - 1] + mm / n);
	printf("%d", s[n - 1] + m);
	return 0;
}
