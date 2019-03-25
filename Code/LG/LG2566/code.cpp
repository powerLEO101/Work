/**************************
 * Writer : Leo101
 * Problem : CF375C Circling Round Treasures
 * Tags : dp，有环的dp
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define INF 0x3f3f3f
const int MAXN = 30;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x * y;
}
char getChar()
{
	char ch = getchar();
	while (!isdigit(ch) && ch != '#') ch = getchar();
	return ch;
}

int n, m, stx, sty, cnt;
int sum[1 << 11], goX[4] = {0, 0, 1, -1}, goY[4] = {1, -1, 0, 0};
int treasureX[MAXN], treasureY[MAXN], value[MAXN], dp[MAXN][MAXN][1 << 11];
char ch[MAXN][MAXN];

bool check(int x, int y, int x1, int y1, int i)
{
	if (x < x1 && x1 == treasureX[i] && y1 < treasureY[i]) return true;
	if (x > x1 && x == treasureX[i] && y < treasureY[i]) return true;
	return false;
}
int getAns()
{
	int ans = 0;
	std :: queue<int> queueX, queueY, queueValue;
	queueX.push(stx);
	queueY.push(sty);
	queueValue.push(0);
	memset(dp, -1, sizeof(dp));
	dp[stx][sty][0] = 0;

	while (!queueX.empty()) {
		int nowX = queueX.front(), nowY = queueY.front(), nowValue = queueValue.front();
		if (nowX == stx && nowY == sty)
			ans = std :: max(ans, sum[nowValue] - dp[nowX][nowY][nowValue]);
		for (int i = 0; i < 4; i++) {
			int toX = nowX + goX[i], toY = nowY + goY[i];
			if (toX == n || toY == m || toX == -1 || toY == -1) continue;
			if (ch[toX][toY] != '0') continue;
			int tmp = nowValue;
			for (int i = 0; i < cnt; i++) {
				if (check(nowX, nowY, toX, toY, i) == false) continue;
				tmp ^= 1 << i;
			}
			if (dp[toX][toY][tmp] == -1) {
				dp[toX][toY][tmp] = dp[nowX][nowY][nowValue] + 1;
				queueX.push(toX);
				queueY.push(toY);
				queueValue.push(tmp);
			}
		}
		queueX.pop(); queueY.pop(); queueValue.pop();
	}

	return ans;
}

int main()
{
	_FILE(code);

	n = gi, m = gi;
	cnt = gi;
	for (int i = 0; i < cnt; i++) value[i] = gi;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ch[i][j] = getChar();
			if (isdigit(ch[i][j]) && ch[i][j] != '0') {
				treasureX[ch[i][j] - '0' - 1] = i;
				treasureY[ch[i][j] - '0' - 1] = j;
			}
		}
	}

	for (int i = 0; i < (1 << cnt); i++)
		for (int j = 0; j < cnt; j++)
			if ((i >> j) & 1) 
				sum[i] += value[j];

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ch[i][j] == '0') {
				stx = i; sty = j;
				ans = std :: max(ans, getAns());
			}
	printf("%d", ans);

	return 0;
}
