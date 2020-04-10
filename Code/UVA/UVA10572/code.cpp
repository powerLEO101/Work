/**************************
  * Author : Leo101
  * Problem : UVA10572 Black & White
  * Tags :
**************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <tuple>
#include <utility>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
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

int stateArray[20], tmp[20];
std::map<std::tuple<int, int, bool, int>, int> dp[2];
// tuple(color, conStatus, upLeft, fixedCol)

std::pair<int, int> checkCapability(int currentStatus, int upLeft, int currentIndex)
{
	int up = (currentStatus >> j) & 1, left = (currentStatus >> (j - 1)) & 1; // might be wrong?
	if ((up + left + upLeft) != 0 && (up + left + upLeft) != 3)
		return std::make_pair(0, 1);
	if (up == 0)
		return std::make_pair(-1, 1);
	if (up == 1)
		return std::make_pair(0, -1);
}

int getColChanged(int currentStatus, int index, int value)
{
	currentStatus &= ~(1 << index);
	return currentStatus & (value << index);
}
int getBit(int currentStatus, int index)
{
	return (currentStatus >> index) & 1;
}
void toArray(int value)
{
	for (int i = 0; i < n; i++, value >>= 1)
		stateArray[i] = value & 1;
}
int toInt()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret |= stateArray[i] << i;
	return ret;
}
bool isLastOne(int index, int value)
{
	for (int i = n - 1; i >= 0; i--) {
		if (stateArray[i] == value) {
			return index == i;
		}
	}
	std::cout << "FUCKKKKK";
	exit(0);
}
int getStatusChanged(int currentCol, int currentStatus, int index, int value, int &fixedCol)
{	
	int up = getBit(currentCol, index), left = getBit(currentCol, index - 1);
	toArray(currentStatus);
	if (value != up && isLastOne(index, stateArray[index])) {
		fixedCol = up;
	}
	if (up == left && left == value) {
		int tmp = stateArray[index];
		for (int i = 0; i < n; i++) {
			if (stateArray[i] == tmp) 
				stateArray[i] = stateArray[index - 1];
		}
	} else if (value != left && value != up) {
		// maybe need to check unknown action here
		stateArray[index] = -1;
	} else if (value == left) {
		stateArray[index] = stateArray[index - 1];
	}
	for (int i = 0; i < n; i++)
		tmp[i] = -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (stateArray[i] == -1) {
			stateArray[i] = count++;
			continue;
		}
		if (tmp[stateArray[i]] != -1) {
			stateArray[i] = tmp[stateArray[i]];
			continue;
		}
		tmp[stateArray[i]] = count++;
		stateArray[i] = count - 1;
	}
	return toInt();
}

int main()
{
	_FILE(code);

	int T = gi;
	while (T--) {
		int n = gi, m = gi;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				char ch;
				std::cin >> ch;
				if (ch == '.') map[i][j] = -1;
				if (ch == '#') map[i][j] = 1;
				if (ch == 'o') map[i][j] = 0;
			}
		}
		int index = 0;
		dp[0][std::make_tuple(0, 0, false, -1)] = 1;
		dp[0][std::make_tuple(0, 0, true, -1)] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int now = index ^ 1;
				for (auto it : dp[index]) {
					int currentAnswer = it.second, currentStatus, currentCol, fixedCol;
					bool upLeft;
					std::tie(currentCol, currentStatus, upleft, fixedCol) = it.second;
					for (auto value : checkCapability(currentStatus, upLeft, j)) {
						if (value == -1 || value == fixedCol) continue;
						int nowFixedCol = -1;
						int color = getColChanged(currentStatus, j, value), \
						status = getStatusChanged(currentCol, currentStatus, j, value, nowFixedCol);
						dp[now][std::make_tuple(color, status, bool(getBit(currentCol)), j, nowFixedCol)] += currentAnswer;
					}
				}
				index = now;
			}
		}
	}

	for (auto it : dp[index]) {

	}

	return 0;
}
