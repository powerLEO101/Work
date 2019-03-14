/**************************
  * Writer : Leo101
  * Problem : Luogu P3369 【模板】普通平衡树
  * Tags : Treap
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MOD = 1e9 + 7;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

int randInt()
{
	 static int seed = 19260817;
	 return seed = (int) ((((seed ^ 998244353) + 19260817ll) * 19890604ll) % MOD);
}

class Node
{
public:
	int cnt, val, rnk, size;
	Node* lSon, rSon;
Node() {
	rnk = randInt();
	cnt = size = 1;
	lSon = rSon = NULL;
}
}* Treap = NULL;
void updateSize(Node* root)
{ root -> size = root -> lSon -> size + root -> rSon -> size + root -> cnt; }
int getRnk(Node* root)
{ return root == NULL ? 0 : root -> rnk; }
void zigNode(Node* &root)
{
	Node* tmp = root -> lSon;
	root -> lSon = tmp -> rSon; tmp -> rSon = root; root = tmp;
	updateSize(root -> lSon); updateSize(root);
}
void zagNode(Node* &root)
{
	Node* tmp = root -> rSon;
	root -> rSon = tmp -> lSon; tmp -> lSon = root; root = tmp;
	updateSize(root -> rSon); updateSize(root);
}
void Insert(int val, Node* &root = Treap)
{
	if (root == NULL) {
		root = new Node;
		root -> val = val;
		return ;
	}
	if (val == root -> val) {
		root -> cnt++;
		updateSize(root);
		return ;
	}
	if (val < root -> val) {
		Insert(val, root -> lSon);
		if (root -> lSon -> rnk > root -> rnk) zigNode(root);
	} else {
		Insert(val, root -> rSon);
		if (root -> rSon -> rnk < root -> rnk) zagNode(root);
	}
	updateSize(root);
}
void Remove(int val, Node* &root = Treap)
{
	if (root == NULL) return ;
	if (val == root -> val) {
		if (root -> cnt > 1) {
			root -> cnt--;
			updateSize(root);
		} else {
			if (root -> lSon == NULL && root -> rSon == NULL) {
				delete root;
				return ;
			}
			if (root -> rSon == NULL || getRnk(root -> lSon) > getRnk(root -> rSon))
		}
	}
}
int getRankByVal(int val, Node* root = Treap)
{
	if (root == NULL) return 0;
	if (val == root -> val) return root -> lSon -> size + 1;
	if (val < root -> val) return getRankByVal(val, Treap -> lSon);
	return getRankByVal(val, root -> rSon) + root -> lSon -> size + root -> cnt;
}
int getValByRank(int rank, Node* root = Treap)
{
	if (root == NULL) return -1;
	if (rank <= root -> lSon -> size) return getValByRank(rank, root -> lSon);
	if (rank <= root -> lSon -> size + root -> cnt) return root -> val;
	return getValByRank(rank - root -> lSon -> size - root -> size, root -> rSon);
}
int getPre(int val, Node* root = Treap)
{
	Node* ans = NULL;
	while (root != NULL) {
		if (val == root -> val) {
			if (root -> lSon != NULL) {
				ans = root -> lSon;
				while (ans -> rSon != NULL) ans = ans -> rSon;
			}
			break;
		}
		if (root -> val < val) {
			if (ans == NULL) ans = root;
			else if (ans -> val < root -> val) ans = root;
		}
		root = val < root -> val ? root -> lSon : root -> rSon;
	}
	return ans == NULL ? -1 : ans -> val;
}
int getNext(int val, Node* root = Treap)
{
	Node* ans = NULL;
	while (root != NULL) {
		if (val == root -> val) {
			if (root -> rSon != NULL) {
				ans = root -> rSon;
				while (ans -> lSon != NULL) ans = ans -> lSon;
			}
			break;
		}
		if (root -> val > val) {
			if (ans == NULL) ans = root;
			else if (ans -> val > root -> val) ans = root;
		}
		root = val < root -> val ? root -> lSon : root -> rSon;
	}
	return ans == NULL ? -1 : ans -> val;
}

int main()
{
	_FILE(code);



	return 0;
}
