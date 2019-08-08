#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define sL (s << 1)
#define sR (s << 1 | 1)

using namespace std;
const int Maxn = 0x3f3f3f3f;
const int N = 2e4 + 5, M = N << 2;
int d[N], c[N], w[N], s[N], st[N], ed[N], f[N]; 
int n, k, Ans, val[M], tag[M];

struct point
{
  int to; point *nxt;
}a[M], *T = a, *lst[N]; 

inline void addEdge(const int &x, const int &y) {T->nxt = lst[x]; T->to = y; lst[x] = T++;} 
template <class T> inline T Min(const T &a, const T &b) {return a < b? a : b;}
template <class T> inline void CkMin(T &a, const T &b) {if (a > b) a = b;}

inline int get()
{
  char ch; bool f = false; int res = 0;
  while (((ch = getchar()) < '0' || ch > '9') && ch != '-');
  if (ch == '-') f = true;
  else res = ch - '0';
  while ((ch = getchar()) >='0' && ch <= '9')
    res = (res << 3) + (res << 1) + ch - '0';
  return f? ~res + 1 : res;
}

inline void put(int x)
{
  if (x < 0)
    x = ~x + 1, putchar('-');
  if (x > 9) put(x / 10);
  putchar(x % 10 + 48);
}

inline void Push(const int &s) {val[s] = Min(val[sL], val[sR]);}
inline void Add(const int &s, const int &z) 
{val[s] += z; tag[s] += z;}

inline void Down(const int &s)
{
  if (!tag[s]) return ;
  Add(sL, tag[s]); Add(sR, tag[s]); tag[s] = 0;
}

inline void Build(const int &s, const int &l, const int &r)
{
  tag[s] = 0;
  if (l == r) return (void)(val[s] = f[l]);
  int mid = l + r >> 1;
  Build(sL, l, mid); Build(sR, mid + 1, r);
  Push(s);
}

inline int Query(const int &s, const int &l, const int &r, const int &x, const int &y)
{ 
  if (l == x && r == y) return val[s];
  Down(s); int mid = l + r >> 1; 
  if (y <= mid) return Query(sL, l, mid, x, y);
  else if (x > mid) return Query(sR, mid + 1, r, x, y);
  else return Min(Query(sL, l, mid, x, mid),
      Query(sR, mid + 1, r, mid + 1, y));
}

inline void Modify(const int &s, const int &l, const int &r, const int &x, const int &y, const int &z)
{
  if (l == x && r == y) return Add(s, z);
  Down(s); int mid = l + r >> 1;
  if (y <= mid) Modify(sL, l, mid, x, y, z);
  else if (x > mid) Modify(sR, mid + 1, r, x, y, z);
  else 
  {
    Modify(sL, l, mid, x, mid, z);
    Modify(sR, mid + 1, r, mid + 1, y, z);
  }
  Push(s);
}

int main()
{
  freopen("code.in", "r", stdin);
  
  n = get(); k = get() + 1;
  for (int i = 2; i <= n; ++i) d[i] = get();
  for (int i = 1; i <= n; ++i) c[i] = get();
  for (int i = 1; i <= n; ++i) s[i] = get();
  for (int i = 1; i <= n; ++i) w[i] = get();
  ++n; d[n] = w[n] = Maxn;  
  //当我们推导i时，我们只考虑了它和前面的基站产生的影响
  //这时对于最后一个基站我们不会考虑它和之后的村庄产生的影响
  //则我们可以在最后增加一个村庄
  //保证它必定被作为基站（无建设费用）且不对前面产生影响
  //这样就不会有遗漏的了 
  for (int i = 1; i <= n; ++i)
  {
    st[i] = lower_bound(d + 1, d + n + 1, d[i] - s[i]) - d;
    ed[i] = lower_bound(d + 1, d + n + 1, d[i] + s[i]) - d;
    std :: cout << st[i] << ' ' << ed[i] << std :: endl;
    if (d[ed[i]] > d[i] + s[i]) ed[i]--; addEdge(ed[i], i);
    //lower_bound查找的是大于等于x的第一个数
    //而ed[i]要求的是小于等于x的最后一个数
    //所以判断一下减一就可以了 
  }
  for (int i = 1; i <= k; ++i)
    if (i == 1)
    {
      int res = 0;
      for (int j = 1; j <= n; ++j)
      {
        f[j] = res + c[j];
        for (point *e = lst[j]; e; e = e->nxt)
          res += w[e->to];
      }
      Ans = f[n];
    }
    else 
    {
      Build(1, 1, n); int y;
      for (int j = 1; j <= n; ++j)
      {
        //注意线段树区间的边界条件
        f[j] = (j > i - 1 ? Query(1, 1, n, i - 1, j - 1) : 0) + c[j];
        for (point *e = lst[j]; e; e = e->nxt)
          if (st[y = e->to] > 1) Modify(1, 1, n, 1, st[y] - 1, w[y]);
        //这里其实只要修改区间[i, st[y] - 1]就行了
        //不过询问/修改的区间长对于线段树其实更快 
      }
      CkMin(Ans, f[n]);
    }
  return put(Ans), 0;
}
