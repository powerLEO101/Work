#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    freopen("code.in","w",stdout);
    srand(time(0));
    int n=40000,m=100000;
    printf("%d %d\n",n,m);
    for(int i=1;i<=n;i++) printf("%d\n",rand());
    for(int i=2;i<=n;i++) printf("%d %d\n",i,rand()%(i-1)+1);
    for(int i=1;i<=m;i++) 
        printf("%d %d\n",rand()%n+1,rand()%n+1);
    return 0;
}
