/**************************
  * Writer : Leo101
  * Problem : Luogu P4197 Peaks
  * Tags : 主席树
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
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

class E
{
public:
	int From, To, Value;
} edges[Max_M];
bool operator< (const E& a, const E& b)
{
	return a.Value < b.Value;
}
int e_num;
void Add_edge(int From, int To, int Value)
{
	edges[e_num++] = (E) {From, To, Value};
}

int Father[Max_N], Up[Max_N][21];
void Init_Father() {for (int i = 0; i < Max_N; i++) Father[i] = i;}
int Get_father(int u) {return Fahter[u] == u ? u : Fahter[u] = Get_father(Father[u]);}
int Cnt, Val[Max_N];
void Ex_Kruskal(int m = e_num)
{
	std::sort(edges, edges + m);
	for (int i = 0 ; i < m; i++) {
		int From = edges[i].From, To = edges[i].To, Value = edges[i].Value;
		From = Get_father(From); To = Get_father(To);
		if (From == To) continue;
		Father[From] = Father[To] = Cnt;
		Up[From][0] = Up[To][0] = Cnt;
		Val[Cnt++] = Value;
	}
}

int main()
{
	File(code);

	/*Input & Build_Graph*/
	int n = gi, m = gi, Q = gi;
	for (int i = 0; i < n; i++) {
		Num[i] = gi;
	}
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		New_edge(From, To, Value);
	}

	/*Ex_Kruskal*/
	Cnt = n;
	Ex_Kruskal();
	

	return 0;
}
