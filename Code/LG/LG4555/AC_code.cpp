#include <iostream>
#include <cstdio>
#include <cstring>

const int MAXN = 1e5;

int n;
int p[MAXN * 2 + 10], L[MAXN * 2 + 10], R[MAXN * 2 + 10];
char a[MAXN + 2], b[MAXN * 2 + 10];

void manacher() {
    int len = 0, pos = 0, maxp = 0;
    b[0] = ' ';
    b[++len] = '#';
    for(int i = 1; i <= n; ++i) {
        b[++len] = a[i];
        b[++len] = '#';
    }
    for(int i = 1; i <= len; ++i) {
        if(i <= maxp) p[i] = std::min(p[pos * 2 - i], maxp - i + 1);
        else p[i] = 1;
        while(b[i - p[i]] == b[i + p[i]]) ++p[i];
        if(i + p[i] - 1 > maxp) {
            maxp = p[i] + i - 1;
            pos = i;
        }
        L[i - p[i] + 2] = std::max(L[i - p[i] + 2], p[i] - 1);
        R[i + p[i] - 2] = std::max(R[i + p[i] - 2], p[i] - 1);
    }
    printf("%d\n", len);
    for(int i = 2; i <= 2 * n; ++i) L[i] = std::max(L[i], L[i - 2] - 2);
    for(int i = 2 * n; i >= 2; --i) R[i] = std::max(R[i], R[i + 2] - 2);
}

int main() {
    scanf("%s", a + 1);
    n = strlen(a + 1);
    manacher();
    int ans = 0;
    printf("%d\n", n * 2);
    for (int i = 1; i <= n * 2; i++) printf("%d ", p[i]);
    for(int i = 2; i < n * 2; i += 2) ans = std::max(R[i] + L[i + 2], ans);
    printf("%d\n", ans);
    return 0;
}
