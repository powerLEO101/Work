/**************************
  * Author : Leo101
  * Problem : 1519. Formula 1
  * Tags : dp, 插头dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define int long long
int get_int() 
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int map[50][50];
std::map<int, int> dp[2];

int getStatus(int s, int index) // 获得在s这个四进制数里面，第index位的状态，可以是0 : 没有插头，1 : 有左括号插头, 2 : 有右括号插头
{
  return (s >> (index << 1)) & 3;
}
int getStatusChanged(int s, int index, int value) // 返回修改s的第index位成value之后的s
{
  index <<= 1;
  s &= ~(3 << index);
  s |= value << index;
  return s;
}

signed main() 
{
	_FILE(code);

  int n = gi, m = gi, endX, endY;
	// 输入：不能走=0, 空地=1
  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++) {
      char ch;
      std::cin >> ch;
      if (ch == '.') {
        map[i][j] = 1;
        endX = i; endY = j;
      } else 
        map[i][j] = 0;
    }
	// map:地图
  int index = 0;
  dp[index][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int now = index ^ 1;
      dp[now].clear();
      for (auto it : dp[index]) {
        int currentStatus = it.first, currentAnswer = it.second;
        if (j == 0) // 
          currentStatus <<= 2; //
        int left = getStatus(currentStatus, j), up = getStatus(currentStatus, j + 1); // left : 左插头, right : 右插头
        if (map[i][j] == 0) {
          int tmp = getStatusChanged(getStatusChanged(currentStatus, j, 0), j + 1, 0);
          dp[now][tmp] += currentAnswer;
        } else if (left == 0 && up == 0) {
          if (map[i][j + 1] && map[i + 1][j]) {
            int tmp = getStatusChanged(getStatusChanged(currentStatus, j, 1), j + 1, 2);
            dp[now][tmp] += currentAnswer;
          }
        } else if (left == 0 || up == 0) {
          int value = left + up;
          if (map[i + 1][j]) 
            dp[now][getStatusChanged(getStatusChanged(currentStatus, j + 1, 0), j, value)] += currentAnswer;
          if (map[i][j + 1])
            dp[now][getStatusChanged(getStatusChanged(currentStatus, j, 0), j + 1, value)] += currentAnswer;
        } else if (left == up) {
          int v = left == 1 ? 1 : -1, tmp = j, target = left == 1 ? 2 : 1, status, c = 0;
          int currentValue = getStatus(currentStatus, tmp);
          do {
            if (currentValue == left) c++;
            if (currentValue == target) c--;
            tmp += v;
            currentValue = getStatus(currentStatus, tmp);
          } while (c != 0);
          tmp -= v;
          int tmp1 = tmp;
          tmp = j + 1;
          currentValue = getStatus(currentStatus, tmp);
          do {
            if (currentValue == left) c++;
            if (currentValue == target) c--;
            tmp += v;
            currentValue = getStatus(currentStatus, tmp);
          } while (c != 0);
          tmp -= v;
          status = getStatusChanged(currentStatus, std::min(tmp, tmp1), 1);
          status = getStatusChanged(status, std::max(tmp, tmp1), 2);
          dp[now][getStatusChanged(getStatusChanged(status, j, 0), j + 1, 0)] += currentAnswer;
        } else if ((left == 2 && up == 1) || (i == endX && j == endY)) {
          int tmp = getStatusChanged(getStatusChanged(currentStatus, j, 0), j + 1, 0);
          dp[now][tmp] += currentAnswer;
        }
      }
      index = now;
    }
  }

  std::cout << dp[index][0];

	return 0;
}
