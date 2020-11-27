#include "wood.h"
#include <algorithm>
#include <vector>
#include <set>

const int N = 2005;
std::vector<unsigned long long> b;

int book[N][12];

void init(std::vector<unsigned long long> a, int m){
	b = a;
	// -------
	/*
	int n = a.size();
	memset(book, -1, sizeof(book));
	for (int i = 0; i < n; i++)
		book[i][0] = a[i];
	for (int i = 0; i < n; i += 2) {
		if (i + 1 >= n) continue;
		book[i][1] = magic(book[i][0], book[i + 1][0]);
	}
	for (int i = 0; i < n; i += 4) {
		if (i + 3 >= n) continue;
		book[i][2] = magic(book[i][1], book[i + 2][1]);
	}

	*/
	// 耗子尾汁
}

unsigned long long query(std::vector<int> u){
	unsigned long long res = 0;
	bool first = true;
	std::set<int> o(u.begin(), u.end());
	for (int x = 0; x < b.size(); ++x) if (!o.count(x)) {
		if (first) res = b[x], first = false;
		else res = magic(res, b[x]);
	}
	return res;
}
