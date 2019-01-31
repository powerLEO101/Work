/**************************
  * Writer : Leo101
  * Problem : Luogu P3919 【模板】可持久化数组（可持久化线段树/平衡树） 
  * Tags : 主席树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 1e6;
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
	int Value;
	Node* l_son,* r_son;
Node() {
	Value = 0;
	l_son = r_son = NULL;
}
}* Root[Max_N];
void Build(Node* Root, int l, int r)
{
	/*Judge*/
	if (l == r - 1) {
		Root -> Value = gi;
		return ;
	}
	
	/*Prepare_sons*/
	Root -> l_son = new Node;
	Root -> r_son = new Node;

	/*Build_next*/
	Build(Root -> l_son, l, (l + r) / 2); Build(Root -> r_son, (l + r) / 2, r);
}
Node* Modify(Node* Root, int Index, int Value, int l, int r)
{
	/*Judge*/
	if (l == r - 1) {
		Node* New = new Node;
		New -> Value = Value;
		return New;
	}

	/*Get_next*/
	Node* New = new Node;
	New -> l_son = Root -> l_son;
	New -> r_son = Root -> r_son;
	int Mid = (l + r) / 2;
	if (Index < Mid) New -> l_son = Modify(Root -> l_son, Index, Value, l, (l + r) / 2);
	else New -> r_son = Modify(Root -> r_son, Index, Value, (l + r) / 2, r);

	return New;
}
int Query(Node* Root, int k, int l, int r)
{
	if (l == r - 1) return Root -> Value;
	int Mid = (l + r) / 2;
	if (k < Mid) return Query(Root -> l_son, k, l, (l + r) / 2);
	else return Query(Root -> r_son, k, (l + r) / 2, r);
}

int main()
{
	File(code);

	int n = gi, m = gi;
	
	Root[0] = new Node;
	Build(Root[0], 0, n);
	for (int i = 1; i <= m; i++) {
		int v = gi, Mode = gi;
		if (Mode == 1) {
			int Index = gi - 1, Value = gi;
			Root[i] = Modify(Root[v], Index, Value, 0, n);
		} else {
			int Index = gi - 1;
			Root[i] = Root[v];
			printf("%d\n", Query(Root[v], Index, 0, n));
		}
	}

	return 0;
}
