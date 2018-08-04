#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define File(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
#define gi get_int()
#define _ 1001
int get_int()
{
	int x = 0,y = 1;char ch = getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch = getchar();
	if(ch=='-')y = -1,ch = getchar();
	while(ch<='9'&&ch>='0')x = x*10+ch-'0',ch = getchar();
	return x*y;
}

char Str[_];

bool Is_num(char a){return a<='9'&&a>='0';}

int main()
{
	File(simplify);
	std::cin>>Str;
	int Len = strlen(Str);
	if(Len>3)std::cout<<0<<std::endl<<Str;
	else 
	{
		std::cout<<0<<std::endl;
		if(Len==1||Len==2)std::cout<<Str;
		else
		{
			if(Is_num(Str[0])==true&&Is_num(Str[1])==true)std::cout<<Str;
			if(Is_num(Str[0])==true&&Is_num(Str[1])==false)
			{
				if(Str[1]=='+')std::cout<<Str[0]-'0'+(Str[2]-'0');
				if(Str[1]=='-')std::cout<<Str[0]-'0'-(Str[2]-'0');
				if(Str[1]=='*')std::cout<<(Str[0]-'0')*(Str[2]-'0');
			}
			if(Is_num(Str[0])==false)std::cout<<Str;
		}
	}
	return 0;
}
