/**************************
  * Writer : Leo101
  * Problem : BZOJ3714 [PA2014]Kuglarz
  * Tags : 最小生成树, 前缀和 
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 4000010
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (ch <= '9' && ch >= '0') x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}

class Edge
{
public:
	int From, To, Value;
}Edges[_];
bool operator< (const Edge& a, const Edge& b)
{
	return a.Value < b.Value;
}
int E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num++] = (Edge){From, To, Value};
}

int Father[4010];
void init() {for (int i = 0; i < 2010; i++) Father[i] = i;}
int Get_father(int u) {return Father[u] == u ? u : Father[u] = Get_father(Father[u]);}

int main()
{
	File(code);

	init();

	int n = gi;
	long long Ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) 
			Add_edge(i - 1, j, gi);

	std::sort(Edges, Edges + E_num);
	
	int Cnt = 0;

	for (int i = 0; i < E_num; i++) {
		int From = Get_father(Edges[i].From),
		    To = Get_father(Edges[i].To),
		    Value = Edges[i].Value;
		if (From == To) continue;
		Father[From] = To;
		Ans += Value;
		Cnt++;
		if (Cnt == n) break;
	}

	printf("%lld", Ans);

	return 0;
}
