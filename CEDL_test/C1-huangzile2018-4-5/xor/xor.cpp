#include <cstdio>


namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int qr;
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	template <class I>
	inline void gi (I &x) {
		for (c = gc(); c < '0' || c > '9'; c = gc());
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
	}
	template <class I>
	inline void print (I &x) {
		if (!x) putc ('0');
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
}
using io :: gi;
using io :: putc;
using io :: print;

const int N = 1000005;
int a[N], n, q;
int l[N],r[N],Ans[N];
int Base[100],Head[N],Next[N],Tim[N];

int main () {
	freopen ("xor.in", "r", stdin); freopen ("xor.out", "w", stdout);
	gi (n);
	for (int i = 1; i <= n; i ++) gi (a[i]);
	gi (q);
	for (int i = 1, l, r, d; i <= q; i ++)
	{
		gi (l[i]), gi (r[i]), gi (Ans[i]);
		Next[Head[r[i]]];
		Head[r[i]] = i;
	}
	for(int i = 1;i<=n;i++)
	{
		int Now = a[i],Time = i;
		for(int j = 30;j>=0;j--)
		{
			if(!((1<<j)&Now))continue;
			if(!Base[j])Base[j] = Now;
			else if(Tim[j]<=Time)
			{
				std::swap(Tim[j],Time);
				std::swap(Base[j],Now);
			}
			x^=a[j];
		}
		for(int j = Head[i];j;j = Next[j])
		{
			for(int k = 30;k>=0;k--)
				if(Tim[k]>=l[j])
					Ans = std::max(Ans,Ans^Base[j]);
		}
	}
	for(int i = 1;i<=n;i++)
	{
		print(Ans[i]);
		putc("\n");
	}
	io::flush ();
	return 0;
}

