/**************************
  * Writer : Leo101
  * Problem : P1438 无聊的数列
  * Tags : 线段树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 200000;
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

int n, m, Num[Max_N];

class Node
{
public:
	long long Val, Tag;
	Node* l_son,* r_son;
Node() {
	Val = Tag = 0;
	l_son = r_son = NULL;
}
}* Seg_Tree = NULL;
void Build(int l = 0, int r = n, Node* &Root = Seg_Tree)
{
	Root = new Node;
	if (l == r - 1) {
		Root -> Val = (l == 0 ? Num[l] : Num[l] - Num[l - 1]);
		return ;
	}
	int Mid = (l + r) / 2;
	Build(l, Mid, Root -> l_son); 
	Build(Mid, r, Root -> r_son);
	Root -> Val = Root -> l_son -> Val +\
		      Root -> r_son -> Val;
}
void Pushdown(int l, int r, Node* Root)
{
	if (Root -> Tag == 0) return ; 
	Root -> l_son -> Tag += Root -> Tag;
	Root -> r_son -> Tag += Root -> Tag;
	int Mid = (l + r) / 2;
	Root -> l_son -> Val += (Mid - l) * Root -> Tag;
	Root -> r_son -> Val += (r - Mid) * Root -> Tag;
	Root -> Tag = 0;
}
void Modify(int Ml, int Mr, long long Val, int l = 0, int r = n, Node* Root = Seg_Tree)
{
	if (Mr <= l || r <= Ml) return ;
	if (Ml <= l && r <= Mr) {
		Root -> Val += Val * (r - l);
		Root -> Tag += Val;
		return ;
	}
	int Mid = (l + r) / 2;
	Pushdown(l, r, Root);
	Modify(Ml, Mr, Val, l, Mid, Root -> l_son);
	Modify(Ml, Mr, Val, Mid, r, Root -> r_son);
	Root -> Val = Root -> l_son -> Val +\
		      Root -> r_son -> Val;
}
long long Query(int Ql, int Qr, int l = 0, int r = n, Node* Root = Seg_Tree)
{
	if (Qr <= l || r <= Ql) return 0;
	if (Ql <= l && r <= Qr) return Root -> Val;
	int Mid = (l + r) / 2;
	Pushdown(l, r, Root);
	return Query(Ql, Qr, l, Mid, Root -> l_son) +\
	       Query(Ql, Qr, Mid, r, Root -> r_son);
}

int main()
{
	File(code);

	n = gi, m = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;
	Build();

	for (int i = 0; i < m; i++) {
		int Type = gi;
		if (Type == 1) {
			long long l = gi - 1, r = gi, k = gi, d = gi;
			Modify(l, l + 1, k);
			if (l != r - 1) Modify(l + 1, r, d);
			if (r != n) Modify(r, r + 1, -((r - l - 1) * d + k));
		} else {
			int k = gi;
			printf("%lld\n", Query(0, k));
		}
	}
	
	return 0;
}
