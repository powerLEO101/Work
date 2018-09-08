// luogu-judger-enable-o2
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 4000005
#define for_edge(i, x) for (int i = Head[x]; i != -1; i = Edges[i].Next)
#define INF 0x3f3f3f3f
long long get_int()
{
	long long x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
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
}Edges[_];
int Head[_], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge){Head[From], To, Value};
	Head[From] = E_num++;
}

long long Dist[_], Vis[_], Num[_];

void SPFA()
{
	memset(Dist, 0x3f, sizeof(Dist));
	memset(Vis, 0, sizeof(Vis));
	std::queue<int> Q;
	Q.push(0);
	Dist[0] = 0;
	Vis[0] = true;
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
	memset(Head, -1, sizeof(Head));
	int n = gi;
	long long Bmin = gi - 1, Bmax = gi, Min = INF;
	for (int i = 0; i < n; i++) {
		Num[i] = gi;
		Min = std::min(Min, Num[i]);
	}
	std::sort(Num, Num + n);
	for (int i = 0; i < Min; i++)
		for (int j = 1; j < n; j++)
			Add_edge(i, (i + Num[j]) % Min, Num[j]);
	SPFA();
	long long Ans = 0;
	for (int i = 0; i < Min; i++) {
		if (Dist[i] <= Bmin) Ans -= (Bmin - Dist[i]) / Min + 1;
		if (Dist[i] <= Bmax) Ans += (Bmax - Dist[i]) / Min + 1;
	}
	printf("%lld", Ans);
	return 0;
}
