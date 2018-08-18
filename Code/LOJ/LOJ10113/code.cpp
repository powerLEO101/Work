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
	int Value, l, r;
Node() {
	l_son = r_son = NULL;
	Value = l = r = 0;
}
}* Tree = new Node;
void Build(Node* Root = Tree)
{
	if (Root -> r == Root -> l + 1) {
		Root -> Value = gi;
		return;
	}
	Root -> l_son = new Node;
	Root -> r_son = new Node;
	Root -> l_son -> l = Root -> l;
	Root -> l_son -> r = (Root -> l + Root -> r) / 2;
	Root -> r_son -> l = (Root -> l + Root -> r) / 2;
	Root -> r_son -> r = Root -> r;
	Build(Root -> l_son);
	Build(Root -> r_son);
	Root -> Value = Root -> l_son -> Value +\
			Root -> r_son -> Value;
}
void Change(int Index, int Val, Node* Root = Tree)
{
	if (Index < Root -> l || Index >= Root -> r) return;
	if (Root -> r == Root -> l + 1) {
		Root -> Value += Val;
		return;
	}
	Change(Index, Val, Root -> l_son);
	Change(Index, Val, Root -> r_son);
	Root -> Value = Root -> l_son -> Value +\
			Root -> r_son -> Value;
}
int Query(int l, int r, Node* Root = Tree)
{
	if (r <= Root -> l || Root -> r <= l) return 0;
	if (l <= Root -> l && Root -> r <= r) return Root -> Value;
	return Query(l, r, Root -> l_son) +\
		Query(l, r, Root -> r_son);
}

int main()
{
	File(code);
	int n = gi, m = gi;
	Tree -> l = 0;
	Tree -> r = n;
	Build();
	for (int i = 0; i < m; i++) {
		int Mod = gi;
		if (Mod == 0) {
			int l = gi - 1,r = gi;
			printf("%d\n", Query(l, r));
		} else {
			int Index = gi - 1,Val = gi;
			Change(Index, Val);
		}
	}
	return 0;
}
