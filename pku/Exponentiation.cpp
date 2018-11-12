#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <complex>

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
		C[i] = int(fA[i].real() + 0.5);
	}
	
	forn(i, sz(C) - 1){
		C[i+1] += C[i]/10;
		C[i] %= 10;
	}
	
	return C;
}

vi acu[10];

int main() {
	string s;
	int n;
	
	while(cin >> s >> n) {
		vi A(1);
		A[0] = 1;
		acu[0].clear();
		acu[0].resize(7);
		
		int dec = sz(s);
		bool flag = false;
		int num = 0;
		
		forn(i, sz(s)) {
			if(s[i] == '.'){
				flag = true;
				dec--;
			}
			else {
				if(!flag)dec--;
				num *= 10;
				num += (s[i] - '0');
			}
		}
		
		int dig = 0;
		
		while(num > 0){
			acu[0][dig++] = num%10;
			num /= 10;
		}
		
		dec *= n;
		
		forr(i, 1, 10)if((i << 1) <= n)acu[i] = mult(acu[i-1], acu[i-1]);
		forn(i, 10)if((1 << i) & n) {
			A = mult(A, acu[i]);
		}
		
		string in = "", dc = "";
		
		flag = false;
		rforr(i, dec, sz(A)) {
			if(flag || A[i] > 0) {
				flag = true;
				in += (A[i] + '0');
			}
		}
		
		flag = false;
		
		forn(i, dec) {
			if(flag || A[i] > 0) {
				flag = true;
				char aux = char(A[i] + '0');
				dc = aux + dc;
			}
		}
		
		if(in != "")cout << in;
		if(dec > 0 && dc != ""){
			cout << ".";
			cout << dc;
		}
		cout << "\n";
	}
	
	return 0;
}
