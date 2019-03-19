/**************************
  * Writer : Leo101
  * Problem : AT2558 Many Moves
  * Tags : 线段树优化dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long LL;
#define int LL
const int MAXN = 3e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int n, Q, A, B;
int num[MAXN];

class Node
{
public:
	int val, tag;
	Node* lSon,* rSon;
Node() {
	val = INF;
	tag = 0;
	lSon = rSon = NULL;
}
}* root[2] = {NULL, NULL};
void build(int l, int r, Node* &root)
{
	if (root == NULL) root = new Node;
	if (l == r - 1) return ;
	int mid = (l + r) / 2;
	build(l, mid, root -> lSon);
	build(mid, r, root -> rSon);
}
void pushdown(Node* root)
{
	if (root -> tag == 0) return ;
	root -> lSon -> tag += root -> tag;
	root -> rSon -> tag += root -> tag;
	root -> lSon -> val += root -> tag;
	root -> rSon -> val += root -> tag;
	root -> tag = 0;
}
void modifyInterval(int ml, int mr, int val, int l, int r, Node* root)
{
	if (mr <= l || r <= ml) return ;
	if (ml <= l && r <= mr) {
		root -> val += val;
		root -> tag += val;
		return ;
	}
	pushdown(root);
	int mid = (l + r) / 2;
	modifyInterval(ml, mr, val, l, mid, root -> lSon);
	modifyInterval(ml, mr, val, mid, r, root -> rSon);
	root -> val = std :: min(root -> lSon -> val, root -> rSon -> val);
}
void modifyNode(int index, int val, int l, int r, Node* root)
{
	if (index < l || index >= r) return ;
	if (l == r - 1) {
		root -> val = val;
		return ;
	}
	pushdown(root);
	int mid = (l + r) / 2;
	modifyNode(index, val, l, mid, root -> lSon);
	modifyNode(index, val, mid, r, root -> rSon);
	root -> val = std :: min(root -> lSon -> val, root -> rSon -> val);
}
int query(int ml, int mr, int l, int r, Node* root)
{
	if (mr <= l || r <= ml) return INF;
	if (ml <= l && r <= mr) return root -> val;
	pushdown(root);
	int mid = (l + r) / 2;
	return std :: min(query(ml, mr, l, mid, root -> lSon),\
			  query(ml, mr, mid, r, root -> rSon));
}

int ABS(int u)
{ return u < 0 ? -u : u; }
signed main()
{
	_FILE(code);

	n = gi, Q = gi, A = gi, B = gi;
	for (int i = 0; i < Q; i++) num[i] = gi;
	build(0, n + 2, root[0]);
	build(0, n + 2, root[1]);
	modifyNode(A, ABS(B - num[0]) + A, 0, n + 2, root[0]);
	modifyNode(B, ABS(A - num[0]) + B, 0, n + 2, root[0]);
	modifyNode(A, ABS(B - num[0]) - A, 0, n + 2, root[1]);
	modifyNode(B, ABS(A - num[0]) - B, 0, n + 2, root[1]);
	for (int i = 1; i < Q; i++) {
		int tmp = std :: min(query(num[i], n + 1, 0, n + 2, root[0]) - num[i],\
				     query(1, num[i], 0, n + 2, root[1]) + num[i]);
		modifyInterval(1, n + 1, ABS(num[i] - num[i - 1]), 0, n + 2, root[0]);
		modifyInterval(1, n + 1, ABS(num[i] - num[i - 1]), 0, n + 2, root[1]);
		modifyNode(num[i - 1], tmp + num[i - 1], 0, n + 2, root[0]);
		modifyNode(num[i - 1], tmp - num[i - 1], 0, n + 2, root[1]);
	}

	int ans = INF;
	for (int i = 1; i <= n; i++)
		ans = std :: min(ans, query(i, i + 1, 0, n + 2, root[1]) + i);

	printf("%lld", ans);

	return 0;
}
