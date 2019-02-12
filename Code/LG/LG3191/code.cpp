/**************************
  * Writer : Leo101
  * Problem : Luogu P3191 [HNOI2007]紧急疏散EVACUATE
  * Tags : 网络流，二分答案，广度优先搜索
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
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

int n, m, S, T;
int Gox[4] = {0, 0, 1, -1}, Goy[4] = {1, -1, 0, 0};
int Dis[Max_N * Max_N][Max_N * Max_N];
std :: vector<int> T;

class Node { public: int x, y; };
class Edge
{
public:
	int Next, To, Value;
}Edges[Max_N * Max_N * 10];
int Head[Max_N * Max_N * 10], E_num;
void Add_edge(int From, int To, int Value)
{
	Edges[E_num] = (Edge) {Head[From], To, Value};
	Head[From] = E_num++;
}

int Hash(Node Val) { return Val.x * m + Val.y; }
int UnHash(int Val) { return (Node) {Val / m, Val % m}; }

void Get_dis(int Now, int K, int Val = 0)
{
	if (Dis[K][Now] == -1) return ;
	Dis[K][Now] = Val;
	
	Node Tmp = UnHash(Now);
	for (int i = 0; i < 4; i++) {
		int Nowx = Tmp.x + Gox[i], Nowy = Tmp.y + Goy[i];
		if (Nowx >= 0 && Nowy >= 0 && Nowx <= n && Nowy <= m) continue;
		Get_dis(Hash((Node) {Nowx, Nowy}), K, Val + 1);
	}
}

void Build(int Mid)
{
	/*Reset*/
	memset(Head, -1, sizeof(Head));
	E_num = 0;

	for (
}
int Dinic()

int main()
{
	File(code);

	/*Prepare*/
	memset(Dis, -1, sizeof(Dis));

	/*Input & Get_S*/
	n = gi, m = gi;
	S = Max_N * Max_N * 10 - 1, T = Max_N * Max_N * 10 - 2;
	int Count = 0;
	for (int i = 0; i < n; i++) scanf("%s", Map[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j] == '.') Count++;
			if (Map[i][j] == 'D') T.push_back(Hash(i, j));
		}
	}

	/*Get_Dis*/
	for (auto it = T.begin(); it != T.end(); it++) {
		Get_dis(*it, it - T.begin());
	}

	/*Binary_Search*/
	int l = 0, r = 1e9, Ans = -1;
	while (l <= r) {
		int Mid = (l + r) / 2;
		Build(Mid);
		if (Dinic() == Count) r = Mid - 1, Answer = Mid;
		else l = Mid + 1;
	}

	Answer == -1 ? printf("impossible") : printf("%d", Answer);

	return 0;
}
