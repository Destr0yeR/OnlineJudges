#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define sz(x) int(x.size())

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;

typedef long long ll;

const double PI = 4*atan(1);
const double TPI = 2*PI;

void fft(vcd& A, bool invert){
	int n = sz(A), bit, mid;
	double angle;
	
	cd wlen, w, u, v;
	
	for(int i = 1, j = 0 ; i < n ; ++i){
		bit = n >> 1;
		for( ; j >= bit ; bit >>= 1)j -= bit;
		j += bit;
		
		if(i < j)swap(A[i], A[j]);
	}
	
	for(int len = 2 ; len <= n ; len <<= 1){
		angle = TPI / len * (invert?-1:1);
		wlen = cd(cos(angle), sin(angle));
		mid = len >> 1;
		
		for(int i = 0 ; i < n ; i += len){
			w = cd(1, 0);
			forn(j, mid){
				u = A[i + j];
				v = w*A[i + j + mid];
				A[i + j] = u + v;
				A[i + j + mid] = u - v;
				w *= wlen;
			}
		}
	}
	
	if(invert)forn(i, n)A[i] /= n;
}

int main(){
	int n, c, k;
	
	TEST(t){
		vcd A, B;
		
		si(n);
		k = 1;
		while(k < 2*(n+1))k <<= 1;
		
		A.resize(k);
		B.resize(k);
		
		rforn(i, n+1){
			si(c);
			A[i] = cd(c, 0);
		}
		
		rforn(i, n+1){
			si(c);
			B[i] = cd(c, 0);
		}
		
		fft(A, false);
		fft(B, false);
		
		forn(i, k)A[i] *= B[i];
		
		fft(A, true);
		
		rforn(i, 2*n + 1){
			cout << ll(A[i].real() + 0.5);
			if(i)printf(" ");
			else puts("");
		}
	}

	return 0;
}



