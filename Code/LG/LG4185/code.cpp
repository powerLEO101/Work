/**************************
  * Author : Leo101
  * Problem : LG P4185 [USACO18JAN]MooTube G
  * Tags : 并查集
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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

int answer[MAXN];

class Edge
{
public:
	int from, to, value;
} edges[MAXN];
int operator< (const Edge& a, const Edge& b)
{
	return a.value > b.value;
}

class Query
{
public:
	int len, p, index;
} query[MAXN];
int operator< (const Query& a, const Query& b)
{
	return a.len > b.len;
}

int fa[MAXN], size[MAXN];
int getFa(int u)
{ return fa[u] == u ? u : fa[u] = getFa(fa[u]); }

int main()
{
	_FILE(code);

	int n = gi, Q = gi;
	for (int i = 1; i < n; i++) {
		edges[i - 1].from = gi - 1;
		edges[i - 1].to = gi - 1;
		edges[i - 1].value = gi;
	}
	std::sort(edges, edges + n);
	for (int i = 0; i < Q; i++) {
		query[i].len = gi;
		query[i].p = gi - 1;
		query[i].index = i;
	}
	std::sort(query, query + Q);
	for (int i = 0; i < n; i++) {
		fa[i] = i;
		size[i] = 1;
	}
	int index = 0;
	while (query[index].len > edges[0].value) index++;
	for (int i = 0; i < n - 1; i++) {
		int from = edges[i].from, to = edges[i].to, value = edges[i].value;
		size[getFa(from)] += size[getFa(to)];
		size[getFa(to)] = 0;
		fa[getFa(to)] = getFa(from);
		while (edges[i].value != edges[i + 1].value && query[index].len <= value && query[index].len > edges[i + 1].value) {
			answer[query[index].index] = size[getFa(query[index].p)] - 1;
			index++;
		}
	}

	for (int i = 0; i < Q; i++)
		std::cout << answer[i] << std::endl;

	return 0;
}
