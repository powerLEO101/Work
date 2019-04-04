/**************************
  * Author : Leo101
  * Problem : 
  * Tags : 
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bits/stdc++.h>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MAXN = 15;
int get_int()
{
	return (rand() % MAXN) + 1;
}

int main()
{
	freopen("code.in", "w", stdout);

	srand(time(0));

	int n = gi;
	printf("%d\n", n);
	for (int i = 1; i < n; i++) printf("%d ", gi);
	printf("\n");
	for (int i = 0; i < n; i++) printf("%d ", gi);

	return 0;
}

