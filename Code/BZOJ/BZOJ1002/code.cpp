/**************************
  * Author : Leo101
  * Problem : BZOJ1002 [FJOI2007]轮状病毒
  * Tags : dp
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
using namespace std;
const int MAXN = 300;
int get_int() {
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


// bign from CSDN

struct bign{
  int d[MAXN], len;

  void clean() { while(len > 1 && !d[len-1]) len--; }

  bign() 			{ memset(d, 0, sizeof(d)); len = 1; }
  bign(int num) 	{ *this = num; } 
  bign(char* num) { *this = num; }
  bign operator = (const char* num){
    memset(d, 0, sizeof(d)); len = strlen(num);
    for(int i = 0; i < len; i++) d[i] = num[len-1-i] - '0';
    clean();
    return *this;
  }
  bign operator = (int num){
    char s[20]; sprintf(s, "%d", num);
    *this = s;
    return *this;
  }

  bign operator + (const bign& b){
    bign c = *this; int i;
    for (i = 0; i < b.len; i++){
      c.d[i] += b.d[i];
      if (c.d[i] > 9) c.d[i]%=10, c.d[i+1]++;
    }
    while (c.d[i] > 9) c.d[i++]%=10, c.d[i]++;
    c.len = max(len, b.len);
    if (c.d[i] && c.len <= i) c.len = i+1;
    return c;
  }
  bign operator - (const bign& b){
    bign c = *this; int i;
    for (i = 0; i < b.len; i++){
      c.d[i] -= b.d[i];
      if (c.d[i] < 0) c.d[i]+=10, c.d[i+1]--;
    }
    while (c.d[i] < 0) c.d[i++]+=10, c.d[i]--;
    c.clean();
    return c;
  }
  bign operator * (const bign& b)const{
    int i, j; bign c; c.len = len + b.len; 
    for(j = 0; j < b.len; j++) for(i = 0; i < len; i++) 
      c.d[i+j] += d[i] * b.d[j];
    for(i = 0; i < c.len-1; i++)
      c.d[i+1] += c.d[i]/10, c.d[i] %= 10;
    c.clean();
    return c;
  }
  bign operator / (const bign& b){
    int i, j;
    bign c = *this, a = 0;
    for (i = len - 1; i >= 0; i--)
    {
      a = a*10 + d[i];
      for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
      c.d[i] = j;
      a = a - b*j;
    }
    c.clean();
    return c;
  }
  bign operator % (const bign& b){
    int i, j;
    bign a = 0;
    for (i = len - 1; i >= 0; i--)
    {
      a = a*10 + d[i];
      for (j = 0; j < 10; j++) if (a < b*(j+1)) break;
      a = a - b*j;
    }
    return a;
  }
  bign operator += (const bign& b){
    *this = *this + b;
    return *this;
  }

  bool operator <(const bign& b) const{
    if(len != b.len) return len < b.len;
    for(int i = len-1; i >= 0; i--)
      if(d[i] != b.d[i]) return d[i] < b.d[i];
    return false;
  }
  bool operator >(const bign& b) const{return b < *this;}
  bool operator<=(const bign& b) const{return !(b < *this);}
  bool operator>=(const bign& b) const{return !(*this < b);}
  bool operator!=(const bign& b) const{return b < *this || *this < b;}
  bool operator==(const bign& b) const{return !(b < *this) && !(b > *this);}

  string str() const{
    char s[MAXN]={};
    for(int i = 0; i < len; i++) s[len-1-i] = d[i]+'0';
    return s;
  }
};

istream& operator >> (istream& in, bign& x)
{
  string s;
  in >> s;
  x = s.c_str();
  return in;
}

ostream& operator << (ostream& out, const bign& x)
{
  out << x.str();
  return out;
}

bign dp[MAXN];

int main() {
	_FILE(code);

  int n = gi;

  bign ans = 0;
  dp[1] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      dp[i] += dp[j] * (i - j);
    }
  }
  for (int i = 1; i <= n; i++)
    ans += dp[n - i + 1] * i * i;

  std :: cout << ans;

	return 0;
}
