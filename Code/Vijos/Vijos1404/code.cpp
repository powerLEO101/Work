/**************************
  * Writer : Leo101
  * Problem : Vijos1404 遭遇战
  * Tags : 最短路, 图论
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 5000000
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
	int Next, To, Value;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

int Dist[_];
bool Vis[_];

void SPFA(int S)
{
	std::queue<int> Q;
	Q.push(S);

	Vis[S] = true;
	memset(Dist, 0x3f, sizeof(Dist));
	Dist[S] = 0;

	while (!Q.empty()) {
		int Now = Q.front();Q.pop();
		for_edge(i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			if (Dist[To] <= Dist[Now] + Value) continue;
			Dist[To] = Dist[Now] + Value;
			if (Vis[To] == false) {
				Vis[To] = true;
				Q.push(To);
			}
		}
		Vis[Now] = false;
	}
}

int main()
{
	File(code);
	
	memset(Head, -1, sizeof(Head));

	int n = gi, S = gi, E = gi;
	for (int i = 0; i < n; i++) {
		int From = std::max(S, gi), To = std::min(E + 1, gi + 1), Value = gi;
		Add_edge(From, To, Value);
	}

	for (int i = S; i <= E; i++) Add_edge(i + 1, i, 0);

	SPFA(S);

	if (Dist[E + 1] == 0x3f3f3f3f) printf("-1");
	else printf("%d", Dist[E + 1]);

	return 0;
}
