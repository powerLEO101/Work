/**************************
  * Writer : Leo101
  * Problem : Luogu P1083 借教室
  * Tags : Segment Tree
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define INF 0x3f3f3f3f
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
	long long Value;
	int  l, r, Tag;
	Node* l_son,* r_son;
Node() {
	Value = l = r = Tag = 0;
	l_son = r_son = NULL;
}
}* Tree = new Node;
void Build(Node* Root = Tree)
{
	if (Root -> r == Root -> l + 1) {
		Root -> Value = gi;
		return ;
	}
	Root -> l_son = new Node;
	Root -> r_son = new Node;
	Root -> l_son -> l = Root -> l;
	Root -> l_son -> r = (Root -> l + Root -> r) / 2;
	Root -> r_son -> l = (Root -> l + Root -> r) / 2;
	Root -> r_son -> r = Root -> r;
	Build(Root -> l_son); Build(Root -> r_son);
	Root -> Value = std::min(Root -> l_son -> Value, Root -> r_son -> Value);
}
void Push_Down(Node* Root)
{
	if (Root -> Tag == 0) return ;
	Root -> l_son -> Tag += Root -> Tag;
	Root -> l_son -> Value += Root -> Tag;
	Root -> r_son -> Tag += Root -> Tag;
	Root -> r_son -> Value += Root -> Tag;
	Root -> Tag = 0;
}
void Modify(int l, int r, int Value, Node* Root = Tree)
{
	if (Root -> l >= r || l >= Root -> r) return ;
	if (l <= Root -> l && Root -> r <= r) {
		Root -> Value += Value;
		Root -> Tag += Value;
		return ;
	}
	Push_Down(Root);
	Modify(l, r, Value, Root -> l_son);
	Modify(l, r, Value, Root -> r_son);
	Root -> Value = std::min(Root -> l_son -> Value, Root -> r_son -> Value);
}
int Query(int l, int r, Node* Root = Tree)
{
	if (Root -> l >= r || l >= Root -> r) return INF;
	if (l <= Root -> l && Root -> r <= r) return Root -> Value;
	Push_Down(Root);
	return std::min(Query(l, r, Root -> l_son), Query(l, r, Root -> r_son));
}

int main()
{
	File(code);

	int n = gi, m = gi;
	Tree -> l = 0, Tree -> r = n;
	Build();
	
	for (int i = 0; i < m; i++) {
		int Val = gi, l = gi - 1, r = gi;
		Modify(l, r, -Val);
		if (Tree -> Value < 0) {
			printf("-1\n%d", i + 1);
			return 0;
		}
	}

	printf("0");

	return 0;
}
