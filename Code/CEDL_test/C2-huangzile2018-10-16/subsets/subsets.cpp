/**************************
  * Writer : Leo101
  * Problem : Luogu3067 Balanced Cow Subsets 
  * Tags : Dfs, Meet In The Middle
**************************/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define File(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
#define gi get_int()
#define _ 21
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

class data
{
public:
	int Value, Status;
};
std::vector<data> Datal, Datar;
bool cmp1 (const data& a, const data& b)
{
	return a.Value < b.Value;
}
bool cmp2(const data& a, const data& b)
{
	return a.Value > b.Value;
}

int Num[_], n;
void Dfs(int Now, int Target, int Value = 0, int Status = 0)
{
	if (Now > Target) {
		if (Target == n / 2)
			Datal.push_back((data){Value, Status});
		else 
			Datar.push_back((data){Value, Status});
		return ;
	}

	Dfs(Now + 1, Target, Value + Num[Now], Status | (1 << Now));
	Dfs(Now + 1, Target, Value - Num[Now], Status | (1 << Now));
	Dfs(Now + 1, Target, Value, Status);
}

bool Vis[1 << _];
int main()
{
	File(code);

	n = gi;
	for (int i = 0; i < n; i++) Num[i] = gi;

	Dfs(0, n / 2);
	Dfs(n / 2 + 1, n - 1);

	std::sort(Datal.begin(), Datal.end(), cmp1);
	std::sort(Datar.begin(), Datar.end(), cmp2);

	std::vector<data>::iterator Index_l = Datal.begin(),
				    Index_r = Datar.begin();
	int Ans = 0;
	while (Index_l != Datal.end() && Index_r != Datar.end()) {
		while (Index_r != Datar.end() && Index_l -> Value + Index_r -> Value > 0) Index_r++;
		std::vector<data>::iterator Pre = Index_r;
		while (Index_r != Datar.end() && Index_l -> Value + Index_r -> Value == 0) {
			if (Vis[Index_l -> Status | Index_r -> Status] == false) {
				Vis[Index_l -> Status | Index_r -> Status] = true;
				Ans++;
			}
			Index_r++;
		}
		if ((Index_l + 1) != Datal.end() && Index_l -> Value == (Index_l + 1) -> Value) Index_r = Pre;
		Index_l++;
	}

	printf("%d", Ans > 0 ? Ans - 1 : 0);

	return 0;
}


