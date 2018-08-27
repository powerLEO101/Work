#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1000
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int Father[_], Vis[_], Flag[_], Ans[_];
std::stack< int > Down[_];
class Node
{
public:
	int u, id;
};
std::vector< Node > Start[_];

int main()
{
	File(message);
	int n = gi, m = gi;
	for (int i = 1; i <= n; i++) Father[i] = gi;
	for (int i = 0; i < m; i++) {
		int u = gi, t = gi;
		Start[t].push_back((Node){u, i});
	}
	for (int i = 0; i < _; i++) Vis[i] = 1;
	for (int t = 1; t <= 200; t++) {
		bool f = false;
		for (int i = 0; i < m; i++)
			if (Vis[i] != 2) {
				f = true;
				break;
			}
		if (f == false) {
			break;
		}
		for (int i = 0; i < m; i++) {
			if (Vis[i] != 3) continue;
			Down[i].pop();
			if (Down[i].empty()) Vis[i] = 2, Ans[i] = t;
			else Flag[Down[i].top()] = false;
		}
		for (int i = 0; i < Start[t].size(); i++) {
			int u = Start[t][i].u, id = Start[t][i].id;
			if (Flag[u] == true)
				Vis[id] = 2, Ans[id] = t;
			else {
				Down[id].push(u);
				Vis[id] = 0;
			}
		}
		for (int i = 0; i < m; i++) {
			if (Vis[i] != 0) continue;
			if (Flag[Father[Down[i].top()]] == true) {
				Vis[i] = 3;
				Down[i].push(Father[Down[i].top()]);
			}
			else if (Down[i].top() == 0) {
				Vis[i] = 3;
				Down[i].push(0);
			}
			else {
				Flag[Down[i].top()] = true;
				Down[i].push(Father[Down[i].top()]);
			}
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n", Ans[i]);
	return 0;
}
