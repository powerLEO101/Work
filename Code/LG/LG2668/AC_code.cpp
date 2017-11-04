#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 25;
int a[maxn], num[maxn];
int n, t, ans;

int chupai()
{
    memset(num, 0, sizeof(num));
    for (int i = 0; i <= 13; i++)
        num[a[i]]++;
    int tot = 0;
    while (num[4] && num[2] > 1)
    {
        num[4]--;
        num[2] -= 2;
        tot++;
    }
    while (num[4] && num[1] > 1)
    {
        num[4]--;
        num[1] -= 2;
        tot++;
    }
    while (num[4] && num[2])
    {
        num[4]--;
        num[2]--;
        tot++;
    }
    while (num[3] && num[2])
    {
        num[3]--;
        num[2]--;
        tot++;
    }
    while (num[3] && num[1])
    {
        num[3]--;
        num[1]--;
        tot++;
    }
    return tot + num[1] + num[2] + num[3] + num[4];
}

void dfs(int step)
{
    if (step >= ans)
        return;
    int temp = chupai();
    if (temp + step < ans)
        ans = temp + step;
    for (int i = 2; i <= 13; i++)
    {
        int j = i;
        while (a[j] >= 3)
            j++;
        if (j - i >= 2)
        {
            for (int j2 = i + 1; j2 <= j - 1; j2++)
            {
                for (int k = i; k <= j2; k++)
                    a[k] -= 3;
                dfs(step + 1);
                for (int k = i; k <= j2; k++)
                    a[k] += 3;
            }
        }
    }
    for (int i = 2; i <= 13; i++)
    {
        int j = i;
        while (a[j] >= 2)
            j++;
        if (j - i >= 3)
        {
            for (int j2 = i + 2; j2 <= j - 1; j2++)
            {
                for (int k = i; k <= j2; k++)
                    a[k] -= 2;
                dfs(step + 1);
                for (int k = i; k <= j2; k++)
                    a[k] += 2;
            }
        }
    }
    for (int i = 2; i <= 13; i++)
    {
        int j = i;
        while (a[j] >= 1)
            j++;
        if (j - i >= 5)
        {
            for (int j2 = i + 4; j2 <= j - 1; j2++)
            {
                for (int k = i; k <= j2; k++)
                    a[k]--;
                dfs(step + 1);
                for (int k = i; k <= j2; k++)
                    a[k]++;
            }
        }
    }
}

int main()
{
	freopen("landlords.in","r",stdin);
	freopen("landlords.out","w",stdout);
    scanf("%d%d", &t, &n);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (x == 1)  //转换掉A
                x = 13; 
            else
            if (x)
                x--;
            a[x]++;
        }
        ans = 1e9;
        dfs(0);
        printf("%d\n", ans);
    }

    return 0;
}
