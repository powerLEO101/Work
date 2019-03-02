#include <iostream>
#include <cstdio>
#include <cstring>

const int MAXN = 11000000;

char a[MAXN | 1], s[MAXN << 1 | 1];
int p[MAXN << 1 | 1];

inline int manacher() {
	int len = strlen(a + 1), lenS = 0, pos = 0, maxP = 0, ans = 0;
	s[0] = '$';
	s[++lenS] = '#';
	for(int i = 1; i <= len; ++i) {
		s[++lenS] = a[i];
		s[++lenS] = '#';
	}
	s[lenS + 1] = '\0';
	for(int i = 1; i <= lenS; ++i) {
		if(i < maxP) p[i] = std::min(p[2 * pos - i], maxP - i);
		else p[i] = 1;
		while(s[i - p[i]] == s[i + p[i]]) ++p[i];
		if(maxP < i + p[i]) {
			pos = i;
			maxP = i + p[i];
		}
		ans = std::max(ans, p[i] - 1);
	}
	return ans;
}

int main() {
	scanf("%s", a + 1);
	printf("%d\n", manacher());
	return 0;
}
