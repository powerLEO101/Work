/**************************
  * Author : Leo101
  * Problem : Luogu1903 [国家集训队]数颜色 / 维护队列
  * Tags : 莫队
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int LIMIT = 5000000;
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

int block, ans, nowTime, nowL, nowR;
int count[LIMIT], num[LIMIT], answer[LIMIT];

class Query
{
public:
	int l, r, time, id;
} query[LIMIT];
bool operator< (const Query& a, const Query& b)
{
	if (a.l / block == b.l / block) {
		if (a.r / block == b.r / block) return a.time < b.time;
		else return a.r < b.r;
	} else {
		return a.l < b.l;
	}
}

class Modify
{
public:
	int before, after, id;
} modification[LIMIT];

void add(int x)
{
	count[x]++;
	if (count[x] == 1) ans++;
}
void del(int x)
{
	count[x]--;
	if (count[x] == 0) ans--;
}
void redo(int x)
{
	int index = modification[x].id;
	if (nowL <= index && index < nowR)
		del(modification[x].before);
	num[modification[x].id] = modification[x].after;
	if (nowL <= index && index < nowR)
		add(modification[x].after);
}
void undo(int x)
{
	int index = modification[x].id;
	if (nowL <= index && index < nowR)
		del(modification[x].after);
	num[modification[x].id] = modification[x].before;
	if (nowL <= index && index < nowR)
		add(modification[x].before);
}

int main()
{
	_FILE(code);

	int n = gi, T = gi;
	block = sqrt(n);
	for (int i = 0; i < n; i++) num[i] = gi;
	int indexQuery = 0, indexModify = 0;
	while (T--) {
		char type;
		std :: cin >> type;
		int l = gi - 1, r = gi;
		if (type == 'Q') {
			query[indexQuery].l = l, query[indexQuery].r = r;
			query[indexQuery].time = indexModify;
			query[indexQuery].id = indexQuery;
			indexQuery++;
		} else {
			modification[++indexModify].before = num[l];
			modification[indexModify].after = r;
			modification[indexModify].id = l;
			num[l] = r;
		}
	}

	std :: sort(query, query + indexQuery);

	nowTime = indexModify, nowL = 0, nowR = 0;
	for (int i = 0; i < indexQuery; i++) {
		while (nowL < query[i].l) del(num[nowL++]);
		while (nowL > query[i].l) add(num[--nowL]);
		while (nowR < query[i].r) add(num[nowR++]);
		while (nowR > query[i].r) del(num[--nowR]);
		while (nowTime < query[i].time) redo(++nowTime);
		while (nowTime > query[i].time) undo(nowTime--);
		answer[query[i].id] = ans;
	}

	for (int i = 0; i < indexQuery; i++)
		printf("%d\n", answer[i]);

	return 0;
}
