/**************************
  * Writer : Leo101
  * Problem : LOJ #10051. 「一本通 2.3 例 3」Nikitosh 和异或
  * Tags : Trie Tree
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
const int MaxN = 400000, MaxVal = MaxN * 32;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while ((ch < '0' || ch > '9') && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1,ch = getchar();
	while (ch <= '9' && ch >= '0') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

int Trie[MaxVal][2], Size = 1, Num[MaxVal], Val[MaxVal];
int l[MaxN], r[MaxN];
void Insert(int x)
{
	int Now = 0;
	for (int i = 31; i >= 0; i--) {
		int Op = (x >> i) % 2;
		if (Trie[Now][Op] == 0) Trie[Now][Op] = Size++;
		Now = Trie[Now][Op];
	}
	Val[Now] = x;
}
int Find(int x)
{
	int Now = 0;
	for (int i = 31; i >= 0; i--) {
		int Op = (x >> i) % 2;
		Op ^= 1;
		if (Trie[Now][Op] != 0) Now = Trie[Now][Op];
		else if (Trie[Now][Op ^ 1]) Now = Trie[Now][Op ^ 1];
	}
	return x ^ Val[Now];
}

int main()
{
	File(code);

	int n = gi, Now = 0;
	for (int i = 0; i < n; i++) Num[i] = gi;
	Insert(Now);
	for (int i = 0; i < n; i++) {
		Now ^= Num[i];
		l[i] = std::max(l[std::max(0, i - 1)], Find(Now));
		Insert(Now);
	}

	memset(Trie, 0, sizeof(Trie));
	Size = 1;

	Now = 0;
	Insert(Now);
	for (int i = n - 1; i >= 0; i--) {
		Now ^= Num[i];
		r[i] = std::max(r[i + 1], Find(Now));
		Insert(Now);
	}

	int Ans = 0;
	for (int i = 0; i < n - 1; i++) 
		Ans = std::max(Ans, l[i] + r[i + 1]);
	printf("%d", Ans);

	return 0;
}
