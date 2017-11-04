#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define MID (root->l+root->r)/2
#define L_SON root->l_son
#define R_SON root->r_son
#define gi get_int()
long long get_int()
{
	long long x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='0')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	long long Val,l,r,Add_mark;
	Node* l_son,* r_son;
Node()
{
	Val = l = r = Add_mark = 0;
	l_son = r_son = NULL;
}
}* Tree = new Node;
void Build(Node* root)
{
	if(root->l==root->r-1){root->Val = gi;return;}
	L_SON = new Node;
	R_SON = new Node;
	L_SON->l = root->l;
	L_SON->r = MID;
	R_SON->l = MID;
	R_SON->r = root->r;
	Build(L_SON);Build(R_SON);
	root->Val = L_SON->Val+R_SON->Val;
}
void Push_down(Node* root)
{
	if(root->Add_mark==0)return;
	L_SON->Val+=(L_SON->r-L_SON->l)*root->Add_mark;
	R_SON->Val+=(R_SON->r-R_SON->l)*root->Add_mark;
	L_SON->Add_mark+=root->Add_mark;
	R_SON->Add_mark+=root->Add_mark;
	root->Add_mark = 0;
}
void Update(Node* root,long long l,long long r,long long Val)//[)
{
	if(l<=root->l&&r>=root->r)
	{
		root->Val+=(root->r-root->l)*Val;
		root->Add_mark+=Val;
		return;
	}
	if(r<=root->l||root->r<=l)return;
	Push_down(root);
	Update(L_SON,l,r,Val);
	Update(R_SON,l,r,Val);
	root->Val = L_SON->Val+R_SON->Val;
}
long long Query(Node* root,long long l,long long r)
{
	if(l<=root->l&&r>=root->r)return root->Val;
	if(r<=root->l||root->r<=l)return 0;
	Push_down(root);
	return Query(L_SON,l,r)+Query(R_SON,l,r);
}

int main()
{
	long long n = gi,m = gi;
	Tree->l = 0;Tree->r = n;
	Build(Tree);
	for(long long i = 0;i<m;i++)
	{
		long long Mode = gi;
		if(Mode==1)
		{
			int a = gi,b = gi,c = gi;
			Update(Tree,a-1,b,c);
		}
		if(Mode==2)
		{
			long long a = gi,b = gi;
			std::cout<<Query(Tree,a-1,b)<<std::endl;
		}
	}
	return 0;
}
