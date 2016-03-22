#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define sz(x) (int)x.size()

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#define MAX (1 << 19)

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;

const double PI = 4 * atan(1);
const double TPI = 2.0 * PI;

vcd A;
int h[MAX], k[MAX];

void fft(vcd &A, bool invert){
	int n = sz(A), mid, bit;
	double angle;
	cd wlen, w, u, v;
	
	for(int i = 1, j = 0 ; i < n ; ++i){
		bit = n >> 1;
		for( ; j >= bit ; bit >>= 1)j -= bit;
		j += bit;
		if(i < j)swap(A[i], A[j]);
	}
	
	for(int i = 1, j = 0; i<n; ++i){
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)j -= bit;
		j += bit;
	}
	
	for(int len = 2 ; len <= n ; len <<= 1){
		angle = TPI / len * (invert?-1:1);
		wlen = cd(cos(angle), sin(angle));
		mid = len/2;
		for(int i = 0 ; i < n ; i+=len){
			w = cd(1, 0);
			forn(j, mid){
				u = A[i + j];
				v = w * A[i + j + mid];
				A[i + j] = u + v;
				A[i + j + mid] = u - v;
				w *= wlen;
			}
		}
	}
	
	if(invert)forn(i, n)A[i] /= n;
}

int main(){
	int n, m, x, ans;
	A.resize(MAX);
	vector<int> d;
	
	while(si(n) == 1){
		fill(all(A), cd(0, 0));
		mset(k, 0);
		d.clear();
		ans = 0;
		
		forn(i, n){
			si(x);
			k[x] = 1;
			A[x] = cd(1, 0);
		}
		
		si(m);
		forn(i, m){
			si(x);
			d.push_back(x);
		}
		
		fft(A, false);
		
		forn(i, MAX)A[i] *= A[i];
		
		fft(A, true);
		
		forn(i, sz(d)){
			if(k[d[i]] || ((int)(A[d[i]].real() + 0.5)))ans ++;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}



