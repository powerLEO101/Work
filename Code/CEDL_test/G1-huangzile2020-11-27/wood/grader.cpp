#include "wood.h"
#include <algorithm>
#include <stdio.h>
#include <vector>

#define pb push_back

using namespace std;

typedef unsigned long long u64;

static const int N = 2005;
static int n, m, q, cost;
static u64 a[N], p[N][N];

u64 _magic(u64 x, u64 y){
	return x + y;
}
u64 magic(u64 x, u64 y){
	return ++cost, _magic(x, y);
}

void ensure(bool f, const char *str){
	if (!f) {
		fprintf(stderr, "%s\n", str);
		exit(-1);
	}
}

int main(){
	int i, j, k;
	scanf("%d%d%d", &n, &m, &q);
	ensure(n >= 3 && n <= 2000, "Invalid n");
	ensure(q >= 1 && q <= n, "Invalid q");
	ensure(m >= 1 && m <= 30 && (1 << m) <= n, "Invalid m");
	for (i = 0; i < n; ++i) scanf("%llu", a + i);
	for (i = 0; i < n; ++i) {
		p[i][i] = a[i];
		for (j = i + 1; j < n; ++j) p[i][j] = _magic(p[i][j - 1], a[j]);
	}
	init(vector<u64>(a, a + n), m);
	for (i = 1; i <= q; ++i) {
		vector<int> u(m);
		for (j = 0; j < m; ++j) {
			scanf("%d", &u[j]);
			ensure(0 <= u[j] && u[j] < n, "Invalid u");
			for (k = 0; k < j; ++k) ensure(u[j] != u[k], "Invalid u");
		}
		u64 res = query(u), ans;
		bool first = true;
		u.pb(-1), u.pb(n);
		sort(u.begin(), u.end());
		for (j = 1; j < u.size(); ++j) if (u[j] - u[j - 1] > 1) {
			if (!first) ans = _magic(ans, p[u[j - 1] + 1][u[j] - 1]);
			else ans = p[u[j - 1] + 1][u[j] - 1], first = false;
		}
		ensure(res == ans, "Wrong Answer");
	}
	printf("Accepted answer: queries count = %d\n", cost);
}
