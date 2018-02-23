#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>
#include<algorithm>
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

class Node
{
public:
	Node* l_son,*r_son;
	int Val,F;
	Node* Father;
Node()
{
	Father = l_son = r_son = NULL;
	Val = F = 0;
}
}*Skew_heap[100001];
Node* Merge(Node*& A,Node*& B)
{
	if(A==NULL||B==NULL)
		return A==NULL?B:A;
	if(A->Val>B->Val)
		std::swap(A,B);
	A->r_son = Merge(A->r_son,B);
	B->Father = A;
	std::swap(A->l_son,A->r_son);
	return A;
}
void Insert(Node*& A,int Val)
{
	Node* Temp = new Node;
	Temp->Val = Val;
	A = Merge(A,Temp);
}
int Delete(Node*& A)
{
	Node* Temp = A;
	Temp->F = true;
	A = Merge(A->l_son,A->r_son);
	Temp->Father = A;
	return Temp->Val;
}
Node* Get_father(Node* root)
{return root->Father==NULL?root:Get_father(root->Father);}

int main()
{
	freopen("code.in","r",stdin);
	freopen("code.out","w",stdout);
	int n = gi,m = gi;
	for(int i = 0;i<n;i++)
		Insert(Skew_heap[i],gi);
	while(m--)
	{
		int Mode = gi;
		std::cout<<"Mode:"<<Mode<<std::endl;
		std::cout<<"!"<<m<<std::endl;
		if(Mode==1)
		{
			int x = gi-1,y = gi-1;
			std::cout<<"x:"<<x+1<<" "<<"y:"<<y+1<<std::endl;
			Node* Temp1 = Get_father(Skew_heap[x]);
			std::cout<<"$"<<std::endl;
			Node* Temp2 = Get_father(Skew_heap[y]);
			std::cout<<"$"<<std::endl;
			Merge(Temp1,Temp2);
		}
		else
		{
			int x = gi-1;
			if(Skew_heap[x]->F==true)
			{
				std::cout<<"-1";
				continue;
			}
			Node* Temp1 = Get_father(Skew_heap[x]);
			std::cout<<"#"<<Delete(Temp1)<<std::endl;
		}
	}
	return 0;
}
