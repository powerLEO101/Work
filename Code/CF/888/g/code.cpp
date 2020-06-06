/**************************
  * Author : Leo101
  * Problem : CF888G Xor-MST
  * Tags : trie, b最短路
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define int long long
const int MAXN = 8e6;
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

int trie[MAXN][2], num[MAXN], cnt = 1;
void insert(int value, int now = 0, int nowBit = 31)
{
	if (nowBit == -1) return ;
	int nowValue = (value >> nowBit) & 1;
	if (trie[now][nowValue] == 0)
		trie[now][nowValue] = cnt++;
	insert(value, trie[now][nowValue], nowBit - 1);
}
int query(int nowL, int nowR, int nowBit = 31)
{
	if (nowBit == -1) return 0;
	int ansL = -1, ansR = -1;
	if (trie[nowL][0] != 0 && trie[nowR][0] != 0) 
		ansL = query(trie[nowL][0], trie[nowR][0], nowBit - 1);
	if (trie[nowL][1] != 0 && trie[nowR][1] != 0)
		ansR = query(trie[nowL][1], trie[nowR][1], nowBit - 1);
	if (ansL != -1 && ansR != -1)
		return std::min(ansL, ansR);
	if (ansL != -1) return ansL;
	if (ansR != -1) return ansR;
	if (trie[nowL][0] != 0 && trie[nowR][1] != 0) 
		ansL = query(trie[nowL][0], trie[nowR][1], nowBit - 1) + (1ll << nowBit);
	if (trie[nowL][1] != 0 && trie[nowR][0] != 0)
		ansR = query(trie[nowL][1], trie[nowR][0], nowBit - 1) + (1ll << nowBit);
	if (ansL != -1 && ansR != -1)
		return std::min(ansL, ansR);
	if (ansL != -1) return ansL;
	if (ansR != -1) return ansR;
}

int getAns(int now = 0, int nowBit = 31)
{
	if (nowBit == -1) return 0;
	int ret = 0;
	if (trie[now][0] != 0 && trie[now][1] != 0)
		ret += query(trie[now][0], trie[now][1], nowBit - 1) + (1ll << nowBit);
	if (trie[now][0] != 0)
		ret += getAns(trie[now][0], nowBit - 1);
	if (trie[now][1] != 0)
		ret += getAns(trie[now][1], nowBit - 1);
	return ret;
}

signed main()
{
	_FILE(code);

	int n = gi;
	for (int i = 0; i < n; i++) num[i] = gi;
	for (int i = 0; i < n; i++)
		insert(num[i]);
	std::cout << getAns();

	return 0;
}
