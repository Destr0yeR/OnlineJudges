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
typedef vector<int> vi;
typedef long long ll;

using namespace std; 

const double PI = 4*atan(1);
const double TPI = 2.0 * PI;

void fft(vcd& A, bool invert){
	int n = sz(A), bit, mid;
	cd wlen, w, u, v;
	long double angle;
	
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
				v = w * A[i + j + mid];
				A[i + j] = u + v;
				A[i + j + mid] = u - v;
				w *= wlen; 
			}
		}
	}
	if(invert)forn(i, n)A[i] /= n;
}

vi mult(vi A, vi B){
	int k = 1, mx = max(sz(A), sz(B));
	vcd fA(all(A));
	vcd fB(all(B));
	
	while(k < mx) k <<= 1;
	k <<= 1;
	
	vi C(k);
	fA.resize(k);
	fB.resize(k);
	
	fft(fA, false);
	fft(fB, false);
	
	forn(i, sz(fA))fA[i] *= fB[i];
	fft(fA, true);
	
	if(sz(fA) > (1 << 20))fA.resize(1 << 20);
	forn(i, sz(fA)){
		if(int(fA[i].real() + 0.5) > 0)C[i] = 1;
		else C[i] = 0;
	}
	return C;
}

vi acu[10];

int main(){
	int n, k, x;
	sii(n, k);
	
	vi A(1);
	A[0] = 1;
	acu[0].resize(1 << 10);
	forn(i, n){
		si(x);
		acu[0][x] = 1;
	}
	
	forr(i, 1, 10)if((i << 1) <= k)acu[i] = mult(acu[i-1], acu[i-1]);
	forn(i, 10)if((1 << i) & k)A = mult(A, acu[i]);

	int cnt = 0;
	forn(i, sz(A)){
		if(A[i] > 0){
			if(cnt++ > 0)printf(" ");
			printf("%d", i);
		}
	}
	
	puts("");
	
	return 0;
}
