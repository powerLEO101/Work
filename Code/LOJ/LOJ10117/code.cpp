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
	int l, r, Value, Add_mark;
Node() {
	l_son = r_son = NULL;
	l = r = Value = Add_mark = 0;
}
}* Tree = new Node;
void Build(Node* Root = Tree)
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
void Push_Down(Node* Root)
{
	if (Root -> Add_mark == 0) return;
	Root -> l_son -> Add_mark += Root -> Add_mark;
	Root -> r_son -> Add_mark += Root -> Add_mark;
	Root -> l_son -> Value += Root -> Add_mark *\
				  (Root -> l_son -> r -\
				   Root -> l_son -> l);
	Root -> r_son -> Value += Root -> Add_mark *\
				  (Root -> r_son -> r -\
				   Root -> r_son -> l);
	Root -> Add_mark = 0;
}
void Modify(int l, int r, int Val, Node* Root = Tree)
{
	if (r <= Root -> l || Root -> r <= l) return;
	if (l <= Root -> l && Root -> r <= r) {
		Root -> Value += Val * (Root -> r - Root -> l);
		Root -> Add_mark += Val;
		return;
	}
	Push_Down(Root);
	Modify(l, r, Val, Root -> l_son);
	Modify(l, r, Val, Root -> r_son);
	Root -> Value = Root -> l_son -> Value +\
			Root -> r_son -> Value;
}
int Query(int l, int r, Node* Root = Tree)
{
	if (r <= Root -> l || Root -> r <= l) return 0;
	if (l <= Root -> l && Root -> r <= r)
		return Root -> Value;
	Push_Down(Root);
	return Query(l, r, Root -> l_son)+\
		Query(l, r, Root -> r_son);
}

int main()
{
	File(code);
	int n = gi, m = gi;
	Tree -> l = 0;
	Tree -> r = 100001;
	Build();
	for (int i = 0; i < m; i++) {
		int Mod = gi;
		if (Mod == 1) {
			int l = gi,r = gi;
			Modify(l, r + 1, 1);
		} else {
			int Index = gi;
			printf("%d\n", Query(Index, Index + 1) % 2);
		}
	}
	return 0;
}
