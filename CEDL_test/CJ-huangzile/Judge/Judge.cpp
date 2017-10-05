#include<iostream>
#include<cstdlib>

int main()
{
	int Num = 0;
	system("g++ a.cpp -o a");
	system("g++ baoli.cpp -o baoli");
	system("g++ Make_data.cpp -o Make_data");
	while(1)
	{
		system("./a");
		system("./baoli");
		system("./Make_data");
		if(system("diff a.out baoli.out"))break;
		std::cout<<"#AC : "<<Num++;
		system("cls");
	}
	std::cout<<"#WA : "<<Num;
	return 0;
}
