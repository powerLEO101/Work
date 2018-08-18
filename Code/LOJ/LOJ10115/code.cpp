#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

class Node
{
public:
	Node* l_son,* r_son;
	int l, r, Value;
Node() {
	l_son = r_son = NULL;
	l = r = Value = 0;
}
}* Left = new Node,* Right = new Node;
void Build(Node* Root)
{
	if (Root -> r == Root -> l + 1) return;
	Root -> l_son = new Node;
	Root -> r_son = new Node;
	Root -> l_son -> l = Root -> l;
	Root -> l_son -> r = (Root -> l + Root -> r) / 2;
	Root -> r_son -> l = (Root -> l + Root -> r) / 2;
	Root -> r_son -> r = Root -> r;
	Build(Root -> l_son);
	Build(Root -> r_son);
}
void Change(int Index, int Val, Node* Root)
{
	if (Root -> r <= Index || Root -> l > Index) return;
	if (Root -> r == Root -> l + 1) {
		Root -> Value += Val;
		return;
	}
	Change(Index, Val, Root -> l_son);
	Change(Index, Val, Root -> r_son);
	Root -> Value = Root -> l_son -> Value +\
			Root -> r_son -> Value;
}
int Query(int l, int r, Node* Root)
{
	if (Root -> r <= l || r <= Root -> l) return 0;
	if (l <= Root -> l && Root -> r <= r) return Root -> Value;
	return Query(l, r, Root -> l_son) +\
		Query(l, r, Root -> r_son);
}

int main()
{
	File(code);
	Left -> l = Right -> l = 0;
	Left -> r = Right -> r = 50001;
	Build(Left);
	Build(Right);
	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int Mod = gi;
		if (Mod == 1) {
			int l = gi, r = gi;
			Change(l, 1, Left);
			Change(r, 1, Right);
		} else {
			int l = gi, r = gi;
			printf("%d\n", Query(0, r + 1, Left) - Query(0, l, Right));
		}
	}
	return 0;
}
