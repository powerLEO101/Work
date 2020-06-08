/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 6e6;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int dX[4] = {0, 0, 1, -1}, dY[4] = {1, -1, 0, 0};

class EdgeTmp
{
public:
	int from, to, value;
};
std::vector<EdgeTmp> Edges[5000];
int operator< (const EdgeTmp& a, const EdgeTmp& b)
{
	return a.value > b.value;
}
int eNumTmp;

int map[2001][2001], vis[2001][2001];
std::vector<std::pair<int, int> > occupation[2001][2001];
std::queue<int> qX, qY, qDis, qS;
void getEdges()
{
	while (!qX.empty()) {
		int nowX = qX.front(), nowY = qY.front(), nowDis = qDis.front() + 1, nowS = qS.front();
		qX.pop(); qY.pop(); qDis.pop(); qS.pop();
		for (int i = 0; i < 4; i++) {
			int tmpX = nowX + dX[i], tmpY = nowY + dY[i];
			if (tmpX == -1 || tmpY == -1 || map[tmpX][tmpY] == 0) continue;
			if (!occupation[tmpX][tmpY].empty()) {
				if ((occupation[tmpX][tmpY].begin())->first != nowS)
					for (auto it : occupation[tmpX][tmpY]) {
						Edges[it.second + nowDis - 1].push_back((EdgeTmp){it.first, nowS, it.second + nowDis - 1});
					}
			} else {
				occupation[tmpX][tmpY].push_back(std::make_pair(nowS, nowDis));
				qX.push(tmpX); qY.push(tmpY); qDis.push(nowDis); qS.push(nowS);
			}
		}
	}
}

int fa[MAXN], value[MAXN];
int getFa(int u) {return fa[u] == u ? u : fa[u] = getFa(fa[u]);}

class Edge
{
public:
	int next, to;
} edges[MAXN];
int head[MAXN], eNum, nNum;
void addEdge(int from, int to)
{
	edges[eNum] = (Edge) {head[from], to};
	head[from] = eNum++;
}

// Old Code 
int Up[MAXN][21], Deep[MAXN];
bool Vis[MAXN];
void Dfs(int Now, int Pre = -1)
{
	Vis[Now] = true;
	for (int i = head[Now]; i != -1; i = edges[i].next) {
		int To = edges[i].to;
		if (To == Pre) continue;
		Up[To][0] = Now;
		Deep[To] = Deep[Now] + 1;
		Dfs(To, Now);
	}
}
void Move(int& u, int& v)
{
	if (Deep[u] < Deep[v]) std::swap(u, v);
	for (int i = 20; i >= 0; i--)
		if (Deep[Up[u][i]] >= Deep[v])
			u = Up[u][i];
}
int Query(int u, int v)
{
	Move(u, v);
	for (int i = 20; i >= 0; i--)
		if (Up[u][i] != Up[v][i])
			u = Up[u][i], v = Up[v][i];
	return u == v ? u : Up[u][0];
}
// Old Code

int main()
{
	_FILE(code);

	memset(head, -1, sizeof(head));
	int n = gi, m = gi, p = gi, q = gi;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char ch;
			std::cin >> ch;
			if (ch == '.') map[i][j] = 1;
		}
	for (int i = 0; i < p; i++) {
		qX.push(gi - 1);
		qY.push(gi - 1);
		qDis.push(0);
		qS.push(i);
	}
	nNum = p;
	getEdges();
	for (int i = 0; i < MAXN; i++)
		fa[i] = i;
	for (int i = 0; i < 4100; i++) {
		if (Edges[i].empty()) continue;
		for (auto it : Edges[i]) {
			int from = getFa(it.from), to = getFa(it.to), val = it.value;
			if (from == to) continue;
			fa[from] = fa[to] = nNum;
			addEdge(from, nNum);
			addEdge(nNum, from);
			addEdge(to, nNum);
			addEdge(nNum, to);
			value[nNum++] = val;
		}
	}

	for (int i = nNum - 1; i >= 0; i--) {
		if (Vis[i] == 0) {
			Up[i][0] = i;
			Dfs(i);
		}
	}
	for (int j = 1; j < 21; j++)
		for (int i = 0; i < nNum; i++)
			Up[i][j] = Up[Up[i][j - 1]][j - 1];

	while (q--) {
		int from = gi - 1, to = gi - 1;
		std::cout << value[Query(from, to)] << std::endl;
	}

	return 0;
}
