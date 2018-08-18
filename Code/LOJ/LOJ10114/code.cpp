#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 30000
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
}* Tree = new Node;
void Build(Node* Root = Tree)
{
	if (Root -> r == Root -> l + 1)
		return;
	Root -> l_son = new Node;
	Root -> r_son = new Node;
	Root -> l_son -> l = Root -> l;
	Root -> l_son -> r = (Root -> l + Root -> r) / 2;
	Root -> r_son -> l = (Root -> l + Root -> r) / 2;
	Root -> r_son -> r = Root -> r;
	Build(Root -> l_son);
	Build(Root -> r_son);
}
void Change(int Index, int Val, Node* Root = Tree)
{
	if (Root -> r <= Index || Index < Root -> l) return;
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

int Ans[_];
int main()
{
	File(code);
	Tree -> l = 0;
	Tree -> r = 32005;
	Build();
	int n = gi;
	for (int i = 0; i < n; i++) {
		int Index = gi,Temp = gi;
		Ans[Query(0,Index + 1)]++;
		Change(Index, 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", Ans[i]);
	return 0;
}
