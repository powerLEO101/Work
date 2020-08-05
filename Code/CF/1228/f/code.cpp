/**************************
 * Author : Leo101
 * Problem :
 * Tags :
 **************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define int long long
const int MAXN = 4e5 + 10;
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

int nodes[MAXN], tmpNodes[MAXN], deep[MAXN], tmpTot, tot;
int n, nowP, nowDis, nodeChanged = -1;

int qPow(int a, int b)
{
  int ans = 1;
  while (b) {
    if (b & 1) ans *= a;
    a *= a;
    b >>= 1;
  }
  return ans;
}

class Edge
{
public:
  int next, to;
} edges[MAXN];
int head[MAXN], eNum;
void addEdge(int from, int to)
{
  edges[eNum] = (Edge) {head[from], to};
  head[from] = eNum++;
}

void dfs(int now, int pre = -1, int dis = 0)
{
  if (dis > nowDis) {
    nowDis = dis;
    if (nowDis / 2 == n - 1 || nowDis / 2 == n - 2) {
      for (int i = 0; i < tmpTot; i++)
        nodes[i] = tmpNodes[i];
      tot = tmpTot;
    }
    nowP = now;
  }
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    tmpNodes[tmpTot++] = to;
    dfs(to, now, dis + 1);
    tmpTot--;
  }
}

int checkS1(int now, int pre)
{
  int cnt = -1;
  for (int i = head[now]; i != -1; i = edges[i].next) {
    cnt++;
  }
  if (cnt != 2 && cnt != 0) {
    std::cout << "0";
    exit(0);
  }
  if (cnt == 0) {
    return 1;
  }
  int prev = -1;
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    int height = checkS1(to, now);
    if (prev == -1) prev = height;
    else if (prev != height) {
      std::cout << "0";
      exit(0);
    }
  }
  return prev + 1;
}
void checkSubtree(int now, int pre)
{
  int a = 0, b = 0;
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    int tmp = deep[now] + checkS1(to, now);
    if (tmp != n - 1 && tmp != n) {
      std::cout << "0";
      exit(0);
    }
    if (tmp == n - 1) a++;
    if (tmp == n) b++;
  }
  if (a != 2 || b != 1) {
    std::cout << "0";
    exit(0);
  }
}

void check(int now, int pre = -1)
{
  int cnt = 0;
  for (int i = head[now]; i != -1; i = edges[i].next) {
    cnt++;
  }
  if (pre == -1) cnt++;
  if (cnt == 1 && deep[now] != n && deep[now] != n - 1) { // also here
    std::cout << "0";
    exit(0);
  }
  if (cnt == 2) { // check here is wrong answer
    if (nodeChanged != -1) {
      std::cout << "0";
      exit(0);
    }
    nodeChanged = now + 1;
    for (int i = head[now]; i != -1; i = edges[i].next) {
      int to = edges[i].to;
      if (to == pre) continue;
      int cnt1 = 0;
      for (int j = head[to]; j != -1; j = edges[j].next) 
        cnt1++;
      if (cnt1 != 1) {
        std::cout << "0";
        exit(0);
      }
    }
  }
  if (cnt == 4) {
    if (nodeChanged != -1) {
      std::cout << "0";
      exit(0);
    }
    nodeChanged = now + 1;
    checkSubtree(now, pre);
  }
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    check(to, now);
  }
}

void getDeep(int now, int pre = -1)
{
  for (int i = head[now]; i != -1; i = edges[i].next) {
    int to = edges[i].to;
    if (to == pre) continue;
    deep[to] = deep[now] + 1;
    getDeep(to, now);
  }
}

signed main() 
{
  _FILE(code);

  memset(head, -1, sizeof(head));
  n = gi;
  int m = qPow(2, n) - 3;
  for (int i = 0; i < m; i++) {
    int from = gi - 1, to = gi - 1;
    addEdge(from, to);
    addEdge(to, from);
  }
  dfs(0);
  nowDis = 0;
  tmpNodes[0] = nowP;
  tmpTot = 1;
  //std::cout << nowP << std::endl;
  dfs(nowP);
  nowDis = tot;
  //std::cout << tot << std::endl;
  //for (int i = 0; i < tot; i++)
    //std::cout << nodes[i] << ' ';
  //std::cout << std::endl;
  if (nowDis % 2 == 0) {
    nowDis /= 2;
    if (nowDis == n - 1) {
      deep[nodes[tot / 2 - 1]] = 1;
      getDeep(nodes[tot / 2 - 1]);
      check(nodes[tot / 2 - 1]);
      nodeChanged = -1;
      deep[nodes[tot / 2]] = 1;
      getDeep(nodes[tot / 2]);
      check(nodes[tot / 2]);
      if (nodes[tot / 2 - 1] > nodes[tot / 2]) {
        std::cout << "2" << std::endl;
        std::cout << nodes[tot / 2] + 1 << ' ' << nodes[tot / 2 - 1] + 1;
      } else {
        std::cout << "2" << std::endl;
        std::cout << nodes[tot / 2 - 1] + 1 << ' ' << nodes[tot / 2] + 1;
      }
    } else {
      std::cout << "0" << std::endl;
    }
  } else {
    int root = nodes[tot / 2];
    deep[root] = 1;
    getDeep(root);
    check(root);
    if (nodeChanged == -1) {
      std::cout << "0";
      exit(0);
    }
    std::cout << 1 << std::endl << nodeChanged;
  }

  return 0;
}
