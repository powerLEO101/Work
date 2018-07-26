#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<queue>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

int Trie[1000005][40],Num = 0,End[1000005],Shift[1000005];
void Build(std::string s)
{
	int Now = 0;
	for(int i = 0;i<s.size();i++)
	{
		if(Trie[Now][s[i]-'a']==0)Trie[Now][s[i]-'a'] = ++Num;
		Now = Trie[Now][s[i]-'a'];
	}
	End[Now]++;
}
void Get_Shift()
{
	std::queue<int> Q;
	for(int i = 0;i<26;i++)if(Trie[0][i]!=0)Q.push(Trie[0][i]);
	while(!Q.empty())
	{
		int Now = Q.front();Q.pop();
		for(int i = 0;i<26;i++)
			if(Trie[Now][i]!=0)Shift[Trie[Now][i]] = Trie[Shift[Now]][i],Q.push(Trie[Now][i]);
			else Trie[Now][i] = Trie[Shift[Now]][i];
	}
}
int Get_ans()
{
	int Now = 0;
	std::string s;
	std::cin>>s;
	int Ans = 0;
	for(int i = 0;i<s.size();i++)
	{
		Now = Trie[Now][s[i]-'a'];
		for(int Temp = Now;Temp&&~End[Temp];Temp = Shift[Temp])
			Ans+=End[Temp],End[Temp] = -1;
	}
	return Ans;
}

int main()
{
	File(code);
	int n = gi;
	for(int i = 0;i<n;i++)
	{
		std::string s;
		std::cin>>s;
		Build(s);
	}
	Get_Shift();
	std::cout<<Get_ans();
	return 0;
}
