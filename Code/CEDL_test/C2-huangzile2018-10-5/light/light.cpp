/***************************
  * Writer : Leo101
  * Problem : Test10-5 light
  * Tags : Shortest Path
***************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define _ 3000000
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
	int Next, To, Value, k, l, r;
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value, int k, int l, int r)
{
	Edges[E_num] = (Edge){Head[From], To, Value, k, l, r};
	Head[From] = E_num++;
}

int Dist[_];
bool Vis[_];
void SPFA()
{
	memset(Dist, 0x3f, sizeof(Dist));
	Dist[0] = 0;
	std::queue<int> Q;
	Q.push(0);
	while (!Q.empty()) {
		int Now = Q.front(); Q.pop();
		Vis[Now] = false;
		for_edge (i, Now) {
			int To = Edges[i].To, Value = Edges[i].Value;
			int k = Edges[i].k, l = Edges[i].l, r = Edges[i].r;
			int Ex_Value = 0, Temp = Value;
			if (l <= (Dist[Now] % k) && (Dist[Now] % k) <= r) {
				Temp -= r - (Dist[Now] % k) + 1;
				if (Temp > 0) { 
					Ex_Value += (Temp / (r - l + 1)) * (k - (r - l + 1));
					Ex_Value += Temp % (r - l + 1) == 0 ? 0 : (k - (r - l + 1));
				}
			} else {
				if ((Dist[Now] % k) < l) Ex_Value += l - (Dist[Now] % k);
				if ((Dist[Now] % k) > r) Ex_Value += k - (Dist[Now] % k) + l;
				Ex_Value += (Temp / (r - l + 1)) * (k - (r - l + 1));
				Ex_Value += Temp % (r - l + 1) == 0 ? -(k - (r - l + 1)) : 0;
				if (Temp == 0) Ex_Value += (k - (r - l + 1));
			}
			if (Dist[Now] + Value + Ex_Value >= Dist[To]) continue;
			Dist[To] = Dist[Now] + Value + Ex_Value;
			if (Vis[To] == false) {
				Vis[To] = true;
				Q.push(To);
			}
		}
	}
}

int main()
{
	File(light);

	memset(Head, -1, sizeof(Head));
	memset(Dist, 0x3f, sizeof(Dist));

	int n = gi, m = gi;
	for (int i = 0; i < m; i++) {
		int From = gi - 1, To = gi - 1, Value = gi;
		int k = gi, l = gi, r = gi;
		Add_edge(From, To, Value, k, l, r);
		Add_edge(To, From, Value, k, l, r);
	}

	SPFA();

	for (int i = 0; i < n; i++) printf("%d\n", Dist[i]);

	return 0;
}


