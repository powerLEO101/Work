#include <cstdio>

using namespace std;
// orz whzzt

namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a integer
	template <class I>
	inline void gi (I &x) {
		for (c = gc(); c < '0' || c > '9'; c = gc());
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15);
	}
	// print a integer
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

int main () {
	freopen ("xor.in", "r", stdin); freopen ("xor.out", "w", stdout);
	gi (n);
	for (int i = 1; i <= n; i ++) gi (a[i]);
	gi (q);
	for (int i = 1, l, r, d; i <= q; i ++) {
		gi (l), gi (r), gi (d);
		print (d);
		putc ('\n');
	}
	io :: flush ();
	return 0;
}

