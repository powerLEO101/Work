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

int visP[MAXN], vis[MAXN], ans[MAXN], l[MAXN], r[MAXN], count[MAXN], cnt;
class Tmp
{
public:
	int value, pos;
} tmp[MAXN];
int operator< (const Tmp& a, const Tmp& b)
{
	return a.value < b.value;
}

class Edge
{
public:
	int next, to, value;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to, int value)
{
	edges[eNum] = (Edge) {head[from], to, value};
	head[from] = eNum++;
}

void dfs(int now)
{
	visP[now] = 1;
	for (int &i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to, value = edges[i].value;
		if (vis[i] != 1) {
			vis[i] = vis[i ^ 1] = 1;
			ans[value] = now < to;
			dfs(to);
		}
	}
}

int main()
{
	_FILE(code);
	memset(head, -1, sizeof(head));

	int n = gi;
	for (int i = 0; i < n; i++) {
		tmp[cnt++] = (Tmp){gi, i};
		tmp[cnt++] = (Tmp){gi + 1, i};
	}
	std::sort(tmp, tmp + cnt);
	memset(l, -1, sizeof(l));
	memset(r, -1, sizeof(r));
	int vNow = -1, pre = -1;
	for (int i = 0; i < cnt; i++) {
		if (tmp[i].value != pre) vNow++;
		pre = tmp[i].value;
		if (l[tmp[i].pos] == -1)
			l[tmp[i].pos] = vNow;
		else 
			r[tmp[i].pos] = vNow;
		count[vNow]++;
	}
	for (int i = 0; i < n; i++) {
		addEdge(l[i], r[i], i);
		addEdge(r[i], l[i], i);
	}
	pre = -1;
	for (int i = 0; i <= vNow; i++) {
		if (count[i] & 1) {
			if (pre != -1) {
				addEdge(i, pre, n);
				addEdge(pre, i, n);
				count[i]++;
				count[pre]++;
				pre = -1;
			} else
				pre = i;
		}
	}
	for (int i = 0; i <= vNow; i++) {
		if (visP[i] == 0)
			dfs(i);
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << ' ';
	}

	return 0;
}
