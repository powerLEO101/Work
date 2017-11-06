#include <bits/stdc++.h>
using namespace std;
int main()
{
	system("g++ code.cpp -o code");
	system("g++ mice.cpp -o AC_code");
	system("g++ make.cpp -o make");
	int T = 0;
	while(1)
	{
		cout<<"CASE"<<T++<<"#";
		system("./make");
		system("./AC_code");
		cout<<"1";
		system("./code");
		if(system("diff code.out mice.out"))
		{
			cout<<"WA"<<endl;
			return 0;
		}
		cout<<"AC"<<endl;
	}
	return 0;
}

