/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int MAXN = 2e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

class Edge
{
public:
	int from, to, value;
} edges[MAXN];
bool operator< (const Edge& a, const Edge& b) 
{
	return a.value < b.value;
}
int eNum;

int f[MAXN], v[MAXN];
int find(int u)
{
	return f[u] == u ? u : f[u] = find(f[u]);
}

signed main()
{
	_FILE(code);

	memset(v, 0x3f, sizeof(v));
	int n = gi, q = gi;
	while (q--) {
		int from = gi, to = gi, val = gi;
		edges[eNum++] = (Edge) {from, to, val};
		v[from] = std::min(v[from], val + 1);
		v[to] = std::min(v[to], val + 2);
	}
	for (int i = 0; i < n; i++) {
		v[(i + 1) % n] = std::min(v[(i + 1) % n], v[i] + 2);
	}
	for (int i = 0; i < n; i++) {
		v[(i + 1) % n] = std::min(v[(i + 1) % n], v[i] + 2);
	}
	for (int i = 0; i < n; i++) f[i] = i;
	for (int i = 0; i < n; i++)
		edges[eNum++] = (Edge) {i, (i + 1) % n, v[i]};
	std::sort(edges, edges + eNum);
	int answer = 0;
	for (int i = 0; i < eNum; i++) {
		int from = edges[i].from, to = edges[i].to, value = edges[i].value;
		if (find(from) == find(to)) continue;
		f[find(from)] = find(to);
		answer += value;
	}
	std::cout << answer;

	return 0;
}
