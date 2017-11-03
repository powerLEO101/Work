#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>

int score[6][6]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}}; 
int NA[201],NB[201];

int main()
{
	int n,na,nb,Ans1 = 0,Ans2 = 0;
	std::cin>>n>>na>>nb;
	for(int i = 0;i<na;i++)std::cin>>NA[i];
	for(int i = 0;i<nb;i++)std::cin>>NB[i];
	for(int i = 0;i<n;i++)
	{
		Ans1+=score[NA[i%na]][NB[i%nb]];
		Ans2+=score[NB[i%nb]][NA[i%na]];
	}
	std::cout<<Ans1<<" "<<Ans2<<std::endl;
	return 0;
}
