#include<iostream>
#include<iomanip>
#include<fstream>
#include<algorithm>
#include<cstring>

const int MAXN=100+10,MAXM=1000+10;
char k[MAXN],C[MAXM],M[MAXM];
char v[30][30]={
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ",
				"BCDEFGHIJKLMNOPQRSTUVWXYZA",
				"CDEFGHIJKLMNOPQRSTUVWXYZAB",
				"DEFGHIJKLMNOPQRSTUVWXYZABC",
				"EFGHIJKLMNOPQRSTUVWXYZABCD",
				"FGHIJKLMNOPQRSTUVWXYZABCDE",
				"GHIJKLMNOPQRSTUVWXYZABCDEF",
				"HIJKLMNOPQRSTUVWXYZABCDEFG",
				"IJKLMNOPQRSTUVWXYZABCDEFGH",
				"JKLMNOPQRSTUVWXYZABCDEFGHI",
				"KLMNOPQRSTUVWXYZABCDEFGHIJ",
				"LMNOPQRSTUVWXYZABCDEFGHIJK",
				"MNOPQRSTUVWXYZABCDEFGHIJKL",
				"NOPQRSTUVWXYZABCDEFGHIJKLM",
				"OPQRSTUVWXYZABCDEFGHIJKLMN",
				"PQRSTUVWXYZABCDEFGHIJKLMNO",
				"QRSTUVWXYZABCDEFGHIJKLMNOP",
				"RSTUVWXYZABCDEFGHIJKLMNOPQ",
				"STUVWXYZABCDEFGHIJKLMNOPQR",
				"TUVWXYZABCDEFGHIJKLMNOPQRS",
				"UVWXYZABCDEFGHIJKLMNOPQRST",
				"VWXYZABCDEFGHIJKLMNOPQRSTU",
				"WXYZABCDEFGHIJKLMNOPQRSTUV",
				"XYZABCDEFGHIJKLMNOPQRSTUVW",
				"YZABCDEFGHIJKLMNOPQRSTUVWX",
				"ZABCDEFGHIJKLMNOPQRSTUVWXY"};
int main()
{
	std::cin>>k>>C;
	int pos = 0;
	for(int i = 0;i<strlen(C);++i)
	{
		if(pos==strlen(k))pos = 0;
		char now_k = k[pos],now_c;
		if(now_k>='a'&&now_k<='z')now_k = now_k-'a'+'A';
		for(now_c = 'A';now_c<='Z';now_c++)
		{
			if(v[now_k-'A'][now_c-'A']==C[i]||v[now_k-'A'][now_c-'A']+32==C[i])
			{
				M[i] = now_c;
				if(C[i]>='a'&&C[i]<='z')M[i]+=32;
				pos++;
				break;
			 }
		}     
	}
	std::cout<<M;
	return 0;
}
