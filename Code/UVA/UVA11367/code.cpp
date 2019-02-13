/**************************
  * Writer : Leo101
  * Problem : Luogu UVA11367 Full Tank?
  * Tags : 优先队列Bfs
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
const int Max_N = 2001, Max_M = 10001;
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
	int Next, To, Value;
}Edges[Max_M << 1];
int Head[Max_N], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

class Node
{
public:
	int City, Fuel, Val;
}Heap[Max_N];
bool operator< (const Node& a, const Node& b)
{ return a.Val > b.Val; }
int H_num;
void Insert(int City, int Fuel, int Val)
{
	Heap[H_num++] = (Node) {City, Fuel, Val};
	std :: push_heap(Heap, Heap + H_num);
}
Node Delete()
{
	std :: pop_heap(Heap, Heap + H_num);
	return Heap[--H_num];
}

int Cost[Max_N], Dp[Max_N][101];
bool Vis[Max_N][101];

int Bfs(int c, int s, int t)
{
	memset(Dp, 0x3f, sizeof(Dp));
	memset(Vis, 0, sizeof(Vis));
	H_num = 0; Insert(s, 0, 0);
	Dp[s][0] = 0;

	while (H_num != 0) {
		Node Now = Delete();
		Vis[Now.City][Now.Fuel] = true;
		if (Now.Fuel != c && Vis[Now.City][Now.Fuel + 1] == false &&\
		Dp[Now.City][Now.Fuel] + Cost[Now.City] < Dp[Now.City][Now.Fuel + 1]) {
			Insert(Now.City, Now.Fuel + 1, Dp[Now.City][Now.Fuel] + Cost[Now.City]);
			Dp[Now.City][Now.Fuel + 1] = Dp[Now.City][Now.Fuel] + Cost[Now.City];
		}
		
		for_edge(i, Now.City) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if ((Now.Fuel - Value < 0) || Vis[To][Now.Fuel - Value] == true ||\
			Dp[Now.City][Now.Fuel] < Dp[To][Now.Fuel - Value])
				continue;
			Dp[To][Now.Fuel - Value] = Dp[Now.City][Now.Fuel];
			if (To == t) return Now.Val;
			Insert(To, Now.Fuel - Value, Now.Val);
		}
	}
	return -1;
}

int main()
{
	File(code);

	/*Prepare*/
	memset(Head, -1, sizeof(Head));

	/*Input*/
	int n = gi, m = gi;
	for (int i = 0; i < n; i++) Cost[i] = gi;
	for (int i = 0; i < m; i++) {
		int From = gi, To = gi, Value = gi;
		Add_edge(From, To, Value); Add_edge(To, From, Value);
	}

	/*Input & Get_ans*/
	int Q = gi;
	while (Q--) {
		int c = gi, s = gi, t = gi;
		int Answer = Bfs(c, s, t);
		if (Answer == -1) printf("impossible\n");
		else printf("%d\n", Answer);
	}

	return 0;
}
