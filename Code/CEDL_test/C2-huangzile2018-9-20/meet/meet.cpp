#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1001
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

class Node
{
public:
	int c, h;

	bool operator< (const Node& a) const {
		return h == a.h ? c < a.c : h < a.h;
	}
}Nodes[_];

int Num[_];

int main()
{
	File(meet);

	int n = gi;
	for (int i = 1; i <= n; i++) Nodes[i].c = gi;
	for (int i = 1; i <= n; i++) Nodes[i].h = gi;
	std::sort(Nodes + 1, Nodes + n + 1);

	int T = gi, Ans = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int Sum = Nodes[r].h - Nodes[l].h + Nodes[r].c + (l != r ? Nodes[l].c : 0),
			    Count = (l == r ? 1 : 2);
			if (Sum >= T) continue;
			for (int i = l + 1; i <= r - 1; i++) Num[i - l] = Nodes[i].c;
			if (r - l - 1 >= 1) std::sort(Num + 1, Num + r - l);
			int i = 1;
			while (Sum + Num[i] <= T && i <= r - l - 1) Sum += Num[i], i++, Count++;
			Ans = std::max(Ans, Count);
		}
	}

	printf("%d", Ans);
	
	return 0;
}
