#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#define zjp_shadow

#define For(i, l, r) for( int i = (l), i##end = (int)(r); i <= i##end; ++i)
#define Fordown(i, r, l) for( int i = (r), i##end = (int)(l); i >= i##end; --i)
#define Set(a, v) memset(a, v, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(a))
#define debug(x) cout << #x << ": " << (x) << endl
#define DEBUG(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back

using namespace std;

template<typename T> inline bool chkmin(T &a, T b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, T b) { return b > a ? a = b, 1 : 0; }

inline int read() {
	int x(0), sgn(1); char ch(getchar());
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') sgn = -1;
	for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
	return x * sgn;
}

void File() {
#ifdef zjp_shadow
	freopen ("code.in", "r", stdin);
	freopen ("AC_code.out", "w", stdout);
#endif
}

const int N = 1010, inf = 0x7f7f7f7f;

int n, P[N], minv[N], col[N];

int pos = 1;
stack<int> S[2];

inline void out(char ch) {
	putchar (ch); putchar (' ');
}

inline bool Pop(int id) {
	if (!S[id].empty() && S[id].top() == pos) {
		out(id ? 'd' : 'b'), S[id].pop(), ++ pos;
		return true;
	}
	return false;
}

inline void Push(int cur, int id) {
	if (id == 1) { while(Pop(0)); }
	while (!S[id].empty() && S[id].top() < cur)
		if (!Pop(id)) Pop(id ^ 1);
	if (id == 1) { while(Pop(0)); }
	S[id].push(cur); out(id ? 'c' : 'a');
}

vector<int> G[N];

int main () {

	File(); 
	n = read();

	For (i, 1, n)
		P[i] = read();

	minv[n + 1] = n + 1;
	Fordown (i, n, 1)
		minv[i] = min(minv[i + 1], P[i]);

	For (i, 1, n) For (j, i + 1, n) 
		if (minv[j + 1] < P[i] && P[i] < P[j]) {
			G[i].pb(j), G[j].pb(i), col[i] = col[j] = -1;
		}

	for (int i = 1; i <= n; i++) printf("%d ", col[i]);
	printf("\n");

	For (i, 1, n) if (!~col[i]) {
		queue<int> Q; Q.push(i); col[i] = 0;
		while (!Q.empty()) {
			int u = Q.front(); Q.pop();
			for (int v : G[u]) {
				if (~col[v] && col[v] != (col[u] ^ 1)) return puts("0"), 0;
				if (!~col[v]) Q.push(v);
				col[v] = col[u] ^ 1;
			}
		}
	}

	memset(col, 0, sizeof(col));
	for (int i = 1; i <= n; i++)
		printf("%d ", col[i]);

	For (i, 1, n)
		Push(P[i], col[i]);

	bool flag = true;
	while (flag) {
		flag = false;
		while(Pop(0)) flag = true;
		while(Pop(1)) flag = true;
	}

	return 0;

}
