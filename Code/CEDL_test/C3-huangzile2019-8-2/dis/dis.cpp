#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define gi get_int()
#define _FILE(s) freopen(#s".in", "r", stdin); freopen(#s".out", "w", stdout)
const int MAXN = 3e5;
int get_int()
{
	int x = 0, y = 1; char ch = getchar();
	while (!isdigit(ch) && ch != '-')
		ch = getchar();
	if (ch == '-') y = -1, ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

char str[MAXN], str1[MAXN], str2[MAXN];
int shift1[MAXN], shift2[MAXN];

void getShift(char str[], int shift[])
{
	int j = -1, len = strlen(str);
	shift[0] = -1;
	for (int i = 1; i < len; i++) {
		while (j != -1 && str[i] != str[j + 1]) j = shift[j];
		if (str[i] == str[j + 1]) j++;
		shift[i] = j;
	}
}
int getAns(char str[], char str1[], int shift[])
{
	int j = -1, len = strlen(str), len1 = strlen(str1);
	for (int i = 0; i < len; i++) {
		while (j != -1 && str[i] != str1[j + 1]) j = shift[j];
		if (str[i] == str1[j + 1]) j++;
		if (j == len1 - 1) return i;
	}
	std :: cout << std :: endl;
	return -1;
}

int main()
{
	_FILE(dis);

	int index = 0;
	char ch = getchar();
	while (ch != ',') 
		str[index++] = ch,
		ch = getchar();
	str[index] = '\0';
	index = 0;
	ch = getchar();
	while (ch != ',') {
		str1[index++] = ch;
		ch = getchar();
	}
	str1[index] = '\0';
	std :: cin >> str2;
	
	int len1 = strlen(str1), len2 = strlen(str2), len = strlen(str);
	std :: reverse(str2, str2 + len2);
	getShift(str2, shift2);
	getShift(str1, shift1);

	int index1 = getAns(str, str1, shift1);
	std :: reverse(str, str + len);
	int index2 = getAns(str, str2, shift2);

	if (index1 == -1 || index2 == -1) {
		std :: cout << -1;
		return 0;
	}
	index2 = len - index2 - 1;

	if (index1 >= index2) std :: cout << -1;
	else std :: cout << index2 - index1 - 1;
	
	return 0;
}
