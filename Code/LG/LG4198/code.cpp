/**************************
  * Writer : Leo101
  * Problem : Luogu 4198 楼房重建
  * Tags : 线段树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
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
	int l, r, Length;
	double Value;
	Node* l_son,* r_son;
Node() {
	l = r = Value = Length = 0;
	l_son = r_son = NULL;
}
}* Tree = new Node;
void Build(Node* Root = Tree)
{
	if (Root -> l + 1 == Root -> r) return ;
	Root -> l_son = new Node;
	Root -> r_son = new Node;
	Root -> l_son -> l = Root -> l;
	Root -> l_son -> r = (Root -> l + Root -> r) / 2;
	Root -> r_son -> l = (Root -> l + Root -> r) / 2;
	Root -> r_son -> r = Root -> r;
	Build(Root -> l_son); Build(Root -> r_son);
}
int Push_up(double Value, Node* Root)
{
	if (Root -> l + 1 == Root -> r) return Root -> Value > Value;
	if (Root -> l_son -> Value <= Value) return Push_up(Value, Root -> r_son);
	if (Root -> l_son -> Value > Value) 
		return Push_up(Value, Root -> l_son) + Root -> Length -\
		       Root -> l_son -> Length;
}
void Modify(int Index, double Value, Node* Root = Tree)
{
	if (Root -> l > Index || Root -> r <= Index) return ;
	if (Root -> l + 1 == Root -> r) {
		Root -> Value = Value;
		return ;
	}
	Modify(Index, Value, Root -> l_son);
	Modify(Index, Value, Root -> r_son);
	Root -> Value = std::max(Root -> l_son -> Value,\
				 Root -> r_son -> Value);
	Root -> Length = Root -> l_son -> Length +\
			 Push_up(Root -> l_son -> Value, Root -> r_son);
}

int main()
{
	File(code);

	Tree -> l = 0, Tree -> r = 200000;
	Build();

	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int x = gi, y = gi;
		Modify(x, y * 1.0 / x);
		printf("%d\n", Tree -> Length);
	}

	return 0;
}
