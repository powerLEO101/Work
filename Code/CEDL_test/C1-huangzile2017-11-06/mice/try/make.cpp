#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("mice.in","w",stdout);
	srand(time(0));
	int n = rand()%100,m = rand()%100;
	for(int i = 0;i<n;i++)cout<<rand()%n+1<<" ";
	cout<<endl;
	for(int i = 0;i<m;i++)cout<<rand()%n+1<<" "<<n<<endl;
	return 0;
}