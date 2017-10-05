#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int Num1[1001],Num2[1001];
int a[1001],b[1001];
bool c[1001];
int Ans = 0,n;
void Get_ans(int deep,int sum)
{
	
}
int main()
{
	std::cin>>n;
	for(int i = 0;i<n;i++)std::cin>>a[i]>>b[i];
	for(int i = 0;i<n;i++)
	{
		Num1[a[i]-1] = i;
		Num2[b[i]-1] = i;
	}
	
	return 0;
}
