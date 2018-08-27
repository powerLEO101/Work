#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 30000
inline char gc(){
	static char buf[1<<6],*p1=buf,*p2=buf;
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<6,stdin),p1==p2)?EOF:*p1++;

}
int get_int()
{
	int x = 0, y = 1; char ch = gc();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = gc();
	if (ch == '-') y = -1,ch = gc();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = gc();
	}
	return x * y;
}

class Edge
{
public:
	int Next, To, Value;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

bool Dfs(int Now, int Target, int Count = 0, int Value = 0)
{
	if (Now == Target) {
		while (Value < 0) Value += Count;
		printf("%d\n", Value);
		return true;
	}
	for_edge(i, Now) {
		int To = Edges[i].To, Val = Edges[i].Value;
		if (Dfs(To, Target, Count + 1, Val + Value) == true) return true;
	}
	return false;
}

int main()
{
	File(earth);
	int T = gi;
	while (T--) {
		memset(Head, -1, sizeof(Head));
		E_num = 0;
		int n = gi, m = gi;
		for (int i = 0; i < m; i++) {
			int From = gi, To = gi, Value = gi;
			Add_edge(From, To, Value);
		}
		if (Dfs(1, n) == false)printf("-1\n");
	}
	return 0;
}
