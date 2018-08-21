#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
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
	int l, r;
	long long Value;
	bool Flag;
Node() {
	l_son = r_son = NULL;
	l = r = Value = Flag = 0;
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
void Modify(int l, int r, Node* Root = Tree)
{
	if (r <= Root -> l || Root -> r <= l || Root -> Flag == true) return;
	if (Root -> r == Root -> l + 1) {
		Root -> Value = sqrt(Root -> Value);
		if (Root -> Value <= 1) Root -> Flag = true;
		return;
	}
	Modify(l, r, Root -> l_son);
	Modify(l, r, Root -> r_son);
	Root -> Value = Root -> l_son -> Value +\
			Root -> r_son -> Value;
	Root -> Flag = Root -> l_son -> Flag &\
		       Root -> r_son -> Flag;
}
long long Query(int l, int r, Node* Root = Tree)
{
	if (r <= Root -> l || Root -> r <= l) return 0;
	if (l <= Root -> l && Root -> r <= r) return Root -> Value;
	return Query(l, r, Root -> l_son) +\
		Query(l, r, Root -> r_son);
}

int main()
{
	File(code);
	int n = gi;
	Tree -> l = 0;
	Tree -> r = n;
	Build();
	int m = gi;
	for (int i = 0; i < m; i++) {
		int Mod = gi;
		if (Mod == 1) {
			int l = gi, r = gi;
			if (l > r) std::swap(l, r);
			printf("%lld\n", Query(l - 1, r));
		} else {
			int l = gi, r = gi;
			if (l > r) std::swap(l, r);
			Modify(l - 1, r);
		}
	}
	return 0;
}
