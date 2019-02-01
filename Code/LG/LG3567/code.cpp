/**************************
  * Writer : Leo101
  * Problem : Luogu P3567 [POI2014]KUR-Couriers
  * Tags : 主席树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int Max_N = 5e5 + 5;
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

int n, m;
int Count = 0;

class Node
{
public:
	int Val;
	Node* l_son,* r_son;
Node() {
	Val = 0;
	l_son = r_son = NULL;
}
}* Root[Max_N];
int Get(Node* Root) {return Root == NULL ? 0 : Root -> Val;}
Node* l_son(Node* Root) {return Root == NULL ? NULL : Root -> l_son;}
Node* r_son(Node* Root) {return Root == NULL ? NULL : Root -> r_son;}
Node* Modify(Node* Root, int Index, int l = 0, int r = Count)
{
	Node* New = new Node;
	if (l == r - 1) {
		New -> Val = Get(Root) + 1;
		return New;
	}

	int Mid = (l + r) / 2;
	New -> l_son = l_son(Root);
	New -> r_son = r_son(Root);
	if (Index < Mid) New -> l_son = Modify(New -> l_son, Index, l, Mid);
	else New -> r_son = Modify(New -> r_son, Index, Mid, r);
	New -> Val = Get(New -> l_son) + Get(New -> r_son);
	
	return New;
}
int Query(Node* Root1, Node* Root2, int Value, int l = 0, int r = Count)
{
	if (l == r - 1) return l;

	int Mid = (l + r) / 2;
	int l_Val = Get(l_son(Root2)) - Get(l_son(Root1));
	int r_Val = Get(r_son(Root2)) - Get(r_son(Root1));
	if (l_Val * 2 > Value) return Query(l_son(Root1), l_son(Root2), Value, l, Mid);
	if (r_Val * 2 > Value) return Query(r_son(Root1), r_son(Root2), Value, Mid, r);
	return n;
}

class Data
{
public:
	int Index, Val;
} Temp[Max_N];
bool operator< (const Data& a, const Data& b)
{
	return a.Val < b.Val;
}

int Num[Max_N], Rnk[Max_N];
int main()
{
	File(code);

	/*Input*/
	n = gi, m = gi;
	for (int i = 0; i < n; i++) {
		Temp[i].Val = gi;
		Temp[i].Index = i;
	}
	
	/*Data_Prepare*/
	std::sort(Temp, Temp + n);
	for (int i = 0; i < n; i++) {
		Num[Temp[i].Index] = Count;
		Rnk[Count] = Temp[i].Val;
		if (Temp[i].Val != Temp[i + 1].Val) Count++;
	}

	/*Build_Tree*/
	for (int i = 0; i < n; i++) {
		if (i != 0) Root[i] = Root[i - 1];
		Root[i] = Modify(Root[i], Num[i]);
	}

	for (int i = 0; i < m; i++) {
		int l = gi - 1, r = gi - 1;
		if (l == 0) printf("%d\n", Rnk[Query(NULL, Root[r], r - l + 1)]);
		else printf("%d\n", Rnk[Query(Root[l - 1], Root[r], r - l + 1)]);
	}

	return 0;
}
