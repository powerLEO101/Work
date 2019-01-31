/**************************
  * Writer : Leo101
  * Problem : Luogu P3834 【模板】可持久化线段树 1（主席树）
  * Tags : 主席树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 200001;
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

class num
{
public:
	int Index, Val;
}Temp[Max_N];
bool operator< (const num& a, const num& b)
{
	return a.Val < b.Val;
}

int Num[Max_N];

class Node
{
public:
	int l, r, Value;
	Node* l_son,* r_son;
Node() {
	l = r = Value = 0;
	l_son = r_son = NULL;
}
}* Root[Max_N];
void Build(Node* Root)
{
	if (Root -> l == Root -> r - 1) return ;

	Root -> l_son = new Node;
	Root -> r_son = new Node;
	Root -> l_son -> l = Root -> l;
	Root -> l_son -> r = (Root -> l + Root -> r) / 2;
	Root -> r_son -> l = (Root -> l + Root -> r) / 2;
	Root -> r_son -> r = Root -> r;
	Build(Root -> l_son); Build(Root -> r_son);
}
Node* Modify(Node* Root, int Value)
{
	if (Root -> l == Root -> r - 1) {
		Node *tmp = new Node;
		tmp -> l = Root -> l;
		tmp -> r = Root -> r;
		tmp -> Value = Root -> Value + 1;
		return tmp;
	}

	Node* New = new Node;
	//New -> Value = Root -> Value + 1;
	New -> l_son = Root -> l_son;
	New -> r_son = Root -> r_son;
	New -> l = Root -> l; New -> r = Root -> r;
	int Mid = (Root -> l + Root -> r) / 2;
	if (Value < Mid) New -> l_son = Modify(Root -> l_son, Value);
	else New -> r_son = Modify(Root -> r_son, Value);

	New -> Value = New -> l_son -> Value + New -> r_son -> Value;	

	return New;
}
int Query(Node* Root1, Node* Root2, int k)
{
	if (Root1 -> l == Root1 -> r - 1) return Root1 -> l;
	
	int x = Root2 -> l_son -> Value -\
		Root1 -> l_son -> Value;
	if (x > k) return Query(Root1 -> l_son, Root2 -> l_son, k);
	else return Query(Root1 -> r_son, Root2 -> r_son, k - x);
}

int main()
{
	File(code);

	/*Input & Prepare*/
	int n = gi, m = gi;
	for (int i = 0; i < n; i++) Temp[i].Val = gi, Temp[i].Index = i;
	std::sort(Temp, Temp + n);
	int Count = 0;
	for (int i = 0; i < n; i++) {
		Num[Temp[i].Index] = Count;
		Count++;
	}

	/*Build*/
	Root[n] = new Node;
	Root[n] -> l = 0; Root[n] -> r = n + 5;
	Build(Root[n]);
	for (int i = 0; i < n; i++) {
		if (i == 0) Root[i] = Modify(Root[n], Num[i]);
		else Root[i] = Modify(Root[i - 1], Num[i]);
	}

	/*Input & Get_ans*/
	for (int i = 0; i < m; i++) {
		int l = gi - 1, r = gi - 1, k = gi - 1;
		if (l - 1 >=  0) 
			printf("%d\n", Temp[Query(Root[l - 1], Root[r], k)].Val);
		else 
			printf("%d\n", Temp[Query(Root[n], Root[r], k)].Val);
	}

	return 0;
}
