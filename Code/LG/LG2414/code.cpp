/**************************
  * Author : Leo101
  * Problem :
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 2e5+1;
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

int fail[MAXN], dfnIn[MAXN], dfnOut[MAXN], ans[MAXN], pos[MAXN], fa[MAXN];
std::vector< std::pair<int, int> > query[MAXN];

int tree[MAXN], nodesNum = 1;
int lowbit(int x)
{ return x & (-x); }
void insert(int x, int v)
{
	while (x <= nodesNum) {
		tree[x] += v;
		x += lowbit(x);
	}
}
int sum(int x)
{
	int ret = 0;
	while (x > 0) {
		ret += tree[x];
		x -= lowbit(x);
	}
	return ret;
}

class Edge
{
public:
	int next, to;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to)
{
	edges[eNum] = (Edge){head[from], to};
	head[from] = eNum++;
}

int trie[MAXN][26], trieO[MAXN][26], endPoint[MAXN];

void insertTrie(std::string str, int index)
{
	int root = 0;
	for (int i = 0; i < str.size(); i++) {
		int now = str[i] - 'a';
		if (trie[root][now] == 0)
			trie[root][now] = nodesNum++;
		root = trie[root][now];
	}
	endPoint[root] = 1;
	pos[index] = root;
}

void getFail()
{
	memcpy(trieO, trie, sizeof(trie));
	std::queue<int> Q;
	for (int i = 0; i < 26; i++) {
		if (trie[0][i] == 0) continue;
		Q.push(trie[0][i]);
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		for (int i = 0; i < 26; i++) {
			if (trie[now][i] != 0) {
				Q.push(trie[now][i]);
				fail[trie[now][i]] = trie[fail[now]][i];
			} else {
				trie[now][i] = trie[fail[now]][i];
			}
		}
	}
}

int count = 1;
void dfsFail(int now = 0)
{
	dfnIn[now] = count++;
	for (int i = head[now]; i != -1; i = edges[i].next) {
		int to = edges[i].to;
		dfsFail(to);
	}
	dfnOut[now] = count - 1;
}
void dfsTrie(int now = 0)
{
	insert(dfnIn[now], 1);
	for (auto i : query[now]) {
		int x = i.first, index = i.second;
		ans[index] = sum(dfnOut[pos[x]]) - sum(dfnIn[pos[x]] - 1);
	}
	for (int i = 0; i < 26; i++) {
		if (trieO[now][i] == 0) continue;
		dfsTrie(trieO[now][i]);
	}
	insert(dfnIn[now], -1);
}

int main()
{
	_FILE(code);
	memset(head, -1, sizeof(head));

	std::string str;
	std::cin >> str;
	int cnt = 0, root = 0, pre = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'B') {
			root = fa[root];
			continue;
		}
		if (str[i] == 'P') {
			endPoint[root] = 1;
			pos[cnt++] = root;
			continue;
		}
		int now = str[i] - 'a';
		pre = root;
		if (trie[root][now] == 0) {
			trie[root][now] = nodesNum++;
		}
		fa[trie[root][now]] = root;
		root = trie[root][now];
	}

	getFail();
	for (int i = 1; i < nodesNum; i++)
		addEdge(fail[i], i);

	/*
	for (int i = 0; i < nodesNum; i++) {
		for (int j = 0; j < 26; j++)
			std::cout << trie[i][j] << ' ';
		std::cout << std::endl;
	}
	for (int i = 0; i < nodesNum; i++) 
		std::cout << fail[i] << ' ';
	std::cout << std::endl;
	*/
	int n = gi;
	for (int i = 0; i < n; i++) {
		int x = gi - 1, y = gi - 1;
		query[pos[y]].push_back(std::make_pair(x, i));
	}
	dfsFail();
	/*
	for (int i = 0; i < nodesNum; i++)
		std::cout << dfnIn[i] << ' ' << dfnOut[i] << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << pos[i] << ' ';
	}
	*/
	dfsTrie();

	for (int i = 0; i < n; i++)
		std::cout << ans[i] << std::endl;

	return 0;
}
