/**************************
 * Author : Leo101
 * Problem : Luogu P1074 靶形数独
 * Tags : dfs
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}
const int value[9][9] = {
	{6, 6, 6, 6, 6, 6, 6, 6, 6},
	{6, 7, 7, 7, 7, 7, 7, 7, 6},
	{6, 7, 8, 8, 8, 8, 8, 7, 6},
	{6, 7, 8, 9, 9, 9, 8, 7, 6},
	{6, 7, 8, 9, 10, 9, 8, 7, 6},
	{6, 7, 8, 9, 9, 9, 8, 7, 6},
	{6, 7, 8, 8, 8, 8, 8, 7, 6},
	{6, 7, 7, 7, 7, 7, 7, 7, 6},
	{6, 6, 6, 6, 6, 6, 6, 6, 6},
};
bool vis1[10][10], vis2[10][10], vis3[10][10];
int num[10][10], re[10], ans = -1;

class Data
{
	public:
		int num, val;
} k[10];
bool operator< (const Data &a, const Data &b)
{
	return a.num < b.num;
}

int get(int i, int j)
{ return i / 3 * 3 + j / 3; }
void dfs(int x, int y, int weight, int count = 9)
{
	if (count == 0) {
		ans = std :: max(ans, weight);
		return ;
	}
	if (y + 1 == 9) count--;
	if (num[x][y] != 0) {
		dfs(y + 1 == 9 ? k[re[x] + 1].val : x, y + 1 == 9 ? 0 : y + 1, weight, count);
		return ;
	}
	for (int i = 1; i <= 9; i++) {
		if (vis1[x][i] == true || vis2[y][i] == true || vis3[get(x, y)][i] == true)
			continue;
		vis1[x][i] = vis2[y][i] = vis3[get(x, y)][i] = true;
		dfs(y + 1 == 9 ? k[re[x] + 1].val : x, y + 1 == 9 ? 0 : y + 1, weight + value[x][y] * i, count);
		vis1[x][i] = vis2[y][i] = vis3[get(x, y)][i] = false;
	}
}

int main()
{
	_FILE(code);
	int pre = 0;
	for (int i = 0; i < 9; i++) {
		k[i].val = i;
		for (int j = 0; j < 9; j++) {
			num[i][j] = gi;
			if (num[i][j] == 0) {
				k[i].num++;
				continue;
			}
			vis1[i][num[i][j]] = true;
			vis2[j][num[i][j]] = true;
			vis3[get(i, j)][num[i][j]] = true;
			pre += num[i][j] * value[i][j];

		}
	}

	std :: sort(k, k + 9);
	for (int i = 0; i < 9; i++)
		re[k[i].val] = i;
	dfs(k[0].val, 0, pre);

	printf("%d", ans);

	return 0;
}
