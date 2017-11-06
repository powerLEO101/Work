#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
#define MID ((root->l+roor->r)/2)
int get_int()
{
	int x = 0 , y = 1;char ch = getchar();
	while ( ( ch < '0' || ch > '9' ) && ch != '-' ) ch = getchar();
	if ( ch == '-' ) y = -1,ch = getchar();
	while ( ch <= '9' && ch >= '0') x = x * 10 + ch - '0',ch = getchar();
	return x * y;
}

class Node
{
public:
	int Val,l,r;
	Node* l_son r_son;
Node()
{
	Val = l = r = 0;
	l_son = r_son = NULL;
}* Segment_tree = new Node;

void Build(Node* root)
{
	if(root->r==root->l+1)
	{
		root->Val = gi;
		return;
	}
	root->l_son = new Node;
	root->r_son = new Node;
	root->l_son->l = root->l;
	root->l_son->r = MID;
	root->r_son->l = MID;
	root->r_son->r = root->r;
	Build(root->l_son);Build(root->r_son);
	root->Val = root->l_son->Val+root->r_son->Val;
}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi,P = gi;
	Segment_tree->l = 0;
	Segment_tree->r = n;
	Build(Segment_tree);
	for(int i = 0;i<m;i++)
	{
		int Mode = gi;
		if(Mode==1)
		{
			
		}
	}
	return 0;
}
