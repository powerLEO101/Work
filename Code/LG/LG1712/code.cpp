/**************************
  * Writer : Leo101
  * Problem : Luogu 1712 [NOI2016]区间
  * Tags : 线段树, 离散化
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 1000000
#define INF 0x3f3f3f3f
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
	int l, r, Value, Add_mark;
	Node* l_son,* r_son;
Node() {
	l = r = Value = Add_mark =0;
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
void Push_Down(Node* Root)
{
	if (Root -> Add_mark == 0) return ;
	Root -> l_son -> Value += Root -> Add_mark;
	Root -> r_son -> Value += Root -> Add_mark;
	Root -> l_son -> Add_mark += Root -> Add_mark;
	Root -> r_son -> Add_mark += Root -> Add_mark;
	Root -> Add_mark = 0;
}
void Modify(int l, int r, int Value, Node* Root = Tree)
{
	if (Root -> r <= l || r <= Root -> l) return ;
	if (l <= Root -> l && Root -> r <= r) {
		Root -> Value += Value;
		Root -> Add_mark += Value;
		return ;
	}
	Push_Down(Root);
	Modify(l, r, Value, Root -> l_son); Modify(l, r, Value, Root -> r_son);
	Root -> Value = std::max(Root -> l_son -> Value, Root -> r_son -> Value);
}
int Query(int l, int r, Node* Root = Tree)
{
	if (Root -> r <= l || r <= Root -> l) return -INF;
	if (l <= Root -> l && Root -> r <= r) return Root -> Value;
	Push_Down(Root);
	return std::max(Query(l, r, Root -> l_son),
			Query(l, r, Root -> r_son));
}

class Interval
{
public:
	int l, r, Length;
}I[_];
bool operator< (const Interval& a, const Interval& b)
{
	return a.Length < b.Length;
}

class Data
{
public:
	int Val, Index;
}p[_ << 1];
bool operator< (const Data& a, const Data& b)
{
	return a.Val < b.Val;
}

int main()
{
	File(code);

	Tree -> l = 0, Tree -> r = 600000;
	Build();

	int n = gi, m = gi, Cur = 0;
	for (int i = 0; i < n; i++) {
		I[i].l = gi, I[i].r = gi, I[i].Length = I[i].r - I[i].l;
		
		p[Cur++] = (Data){I[i].l, i};
		p[Cur++] = (Data){I[i].r, i};
		
		I[i].l = I[i].r = -1;
	}

	std::sort(p, p + Cur);

	int num = 0;

	for (int i = 0; i < Cur; i++) {
		int Index = p[i].Index;
		if (I[Index].l == -1) {
			I[Index].l = num;
		} else {
			I[Index].r = num + 1;
		} if (p[i].Val != p[i + 1].Val) num++;
	}

	int Ans = INF, l = 0; 

	std::sort(I, I + n);

	for (int i = 0; i < n; i++) {
		Modify(I[i].l, I[i].r, 1);
		
		while (Tree -> Value == m) {
			Modify(I[l].l, I[l].r, -1);
			Ans = std::min(Ans, I[i].Length - I[l].Length);
			l++;
		}
	}

	if (Ans == INF) printf("-1");
	else printf("%d", Ans);

	return 0;
}
