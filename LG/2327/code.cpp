#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

namespace file
{
	std::ifstream cin("code.in");
	std::ofstream cout("code.out");
}

int num[10001],n;
bool state[10001];
void init(){for(int i = 0;i<10001;i++)state[i] = false;}

bool get_ans(int index)
{
	int temp = state[index]+state[index];
	if(index>=n-1)return temp==num[index];
	if(temp==num[index])
		return get_ans(index+1);
	else
	{
		state[index+1] = true;
		return get_ans(index+1);
	}
	return false;
}

int main()
{	
	file::cin>>n;
	for(int i = 0;i<n;i++)file::cin>>num[i];
	init();
	if(num[0]==0)std::cout<<get_ans(1);
	init();
	if(num[0]==1)
	{
		int temp_ans = 0;
		state[0] = true;temp_ans += get_ans(2);
		state[0] = false;state[1] = true;temp_ans += get_ans(2);
		std::cout<<temp_ans;
	}
	if(num[0]==2)
	{
		state[0] = state[1] = true;
		std::cout<<get_ans(2);
	}
	return 0;
}
