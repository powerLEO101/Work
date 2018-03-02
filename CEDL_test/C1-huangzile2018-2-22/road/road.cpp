#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define gi get_int()
inline int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Num[100001];

class Node
{
public:
	int Val,Size;
	Node* l_son,* r_son;
Node(int Val)
{
	Val = Val;
	Size = 1;
	l_son = r_son = NULL;
}
};
Node* Stack[100000 << 1];
int Top = -1,l[100000 << 1],r[100000 << 1],Size[100000 << 1];
Node* Merge(Node*& u,Node*& v)
{
	if(u==NULL||v==NULL)return u==NULL?v:u;
	if(u->Val<v->Val)std::swap(u,v);
	u->r_son = Merge(u->r_son,v);
	if(u->l_son==NULL||u->r_son==NULL)
		u->Size = u->l_son==NULL?u->r_son->Size:u->l_son->Size;
	std::swap(u->l_son,u->r_son);
	return u;
}
void Delete(Node*& root)
{
	root = Merge(root->l_son,root->r_son);
}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		Num[i] = gi;
		Stack[++Top] = new Node(Num[i]);
		l[Top] = r[Top] = i;
		Size[Top] = 1;
		if(i==0)continue;
		while(Top!=0&&Stack[Top]->Val<Stack[Top-1]->Val)
		{
			Size[Top-1] += Size[Top];
			r[Top-1] = r[Top];
			Stack[Top-1] = Merge(Stack[Top],Stack[--Top]);
			while(Stack[Top]->Size>((r[Top]-l[Top]+2)/2))Delete(Stack[Top]),Size[Top]--;
		}
	}
	long long Ans = 0;
	for(int i = 0;i<=Top;i++)
	{
		std::cout<<l[i]<<" "<<r[i]<<" "<<Stack[i]->Val<<std::endl;
		for(int j = l[i];j<=r[i];j++)
			Ans+=abs(Stack[i]->Val-Num[j]);
	}
	std::cout<<Ans;
	return 0;
}
