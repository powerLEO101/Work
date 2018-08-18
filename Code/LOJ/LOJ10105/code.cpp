#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i,x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 2000000
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

class Edge
{
public:
	int Next,To;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To)
{
	Edges[E_num] = (Edge){Head[From], To};
	Head[From] = E_num++;
}

int Type, In[_], Out[_], Ans[_], Tot;
bool Vis[_];
void Euler(int Now)
{
	for (int& i = Head[Now]; i != -1; i = Edges[i].Next) {
		int Temp = Type == 1 ? i / 2 : i, y = 1;
		if (Type == 1)
			y = i % 2 == 1 ? -1 : 1;
		if (Vis[Temp] == true) continue;
		Vis[Temp] = true;
		Euler(Edges[i].To);
		Ans[Tot++] = (Temp + 1) * y;
	}
}

int main()
{
	File(code);
	Type = gi;
	int n = gi, m = gi;
	memset(Head, -1, sizeof(Head));
	for (int i = 0; i < m; i++)
	{
		int From = gi, To = gi;
		Add_edge(From, To);
		if (Type == 1)
			Add_edge(To, From);
	}
	if (Type == 1) {
		for (int i = 1; i <= n; i++)
			for_edge (j, i) {
				int To = Edges[j].To;
				In[To]++;
			}
		for (int i = 1; i <= n; i++)
			if ((In[i] % 2) != 0) {
				printf("NO");
				return 0;
			}
	} else {
		for (int i = 1; i <= n; i++)
			for_edge (j, i) {
				int To = Edges[j].To;
				Out[i]++;
				In[To]++;
			}
		for (int i = 1; i <= n; i++)
			if(In[i] != Out[i]) {
				printf("NO");
				return 0;
			}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		if (Head[i] == -1)
			continue;
		Euler(i);
		break;
	}
	if (Tot != m) {
		 printf("NO");
		 return 0;
	}
	for (int i = m - 1; i >= 0; i--)
		printf("%d ", Ans[i]);
	return 0;
}
