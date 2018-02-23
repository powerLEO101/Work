#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdio>

int main()
{
  int a,b;
  std::cin>>a>>b;
  int temp;
  while(std::cin>>temp>>temp)
    {
      std::cout<<"0.";
      for(int i = 0;i<b;i++)std::cout<<"0";
      std::cout<<std::endl;
    }
  return 0;
}
