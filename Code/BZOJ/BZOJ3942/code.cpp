#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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

char S[1000005],T[1000005];
int Shift[1000005],Pre[1000005];
char Stack[1000005];

int main()
{
	File(code);
	scanf("%s%s",S,T);
	int j = -1,Len = strlen(T);
	Shift[0] = -1;
	for(int i = 1;i<Len;i++)
	{
		while(j>-1&&T[i]!=T[j+1])j = Shift[j];
		if(T[i]==T[j+1])j++;
		Shift[i] = j;
	}
	int Top = 0,LenS = strlen(S);
	Pre[0] = -1;
	j = -1;
	for(int i = 0;i<LenS;i++)
	{
		Stack[++Top] = S[i];
		while(j>-1&&Stack[Top]!=T[j+1])j = Shift[j];
		if(Stack[Top]==T[j+1])j++;
		Pre[Top] = j;
		if(j==Len-1)
		{
			Top-=Len;
			j = Pre[Top];
		}
	}
	for(int i = 1;i<=Top;i++)putchar(Stack[i]);
	return 0;
}
