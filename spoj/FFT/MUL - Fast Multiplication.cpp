#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define sz(x) (int)x.size()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

typedef complex<double> cd;
typedef vector<cd> vcd;

const double PI = 4*atan(1);
const double TPI = 2.0*PI;

void fft(vcd &A, bool invert) {
	int n = sz(A);

	for(int i = 1, j = 0; i<n; ++i){
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)j -= bit;
		j += bit;
		if(i < j)swap(A[i], A[j]);
	}
	
	double angle;
	
	for(int len = 2; len <= n; len <<= 1) {
		angle = TPI / len * (invert ? -1 : 1);
		cd wlen(cos(angle), sin(angle));
		
		for(int i = 0; i < n; i += len) {
			cd w(1);
			for (int j = 0; j < len / 2; ++j) {
				cd u = A[i + j], v = A[i + j + len / 2] * w;
				A[i + j] = u + v;
				A[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
	for (int i = 0; i < n; ++i)
		A[i] /= n;

}

void FFT(vcd &arr, bool invert){
	int n = sz(arr);
	if(n == 1)return;
	
	double angle;
	vcd w(n);
	
	forn(i, n){
		angle = (TPI * i) / n * (invert?-1:1);
		w[i] = cd(cos(angle), sin(angle));
	}
	int mid = n >> 1;
	vcd A(mid), B(mid);
	
	forn(i, mid){
		A[i] = arr[i << 1];
		B[i] = arr[(i<<1) + 1];
	}
	
	FFT(A, invert);
	FFT(B, invert);
	
	cd aux;
	
	forn(i, mid){
		aux = w[i]*B[i%mid];
		arr[i] = A[i%mid] + aux;
		arr[i+mid] = A[i%mid] - aux;
	}
}

void FFT(vcd &arr){
	FFT(arr, false);
}

void IFFT(vcd &arr){
	FFT(arr, true);
	int n = sz(arr);
	forn(i, n)arr[i] /= n;
}

void mult(vcd &A, vcd &B){
	//FFT(A);
	//FFT(B);
	fft(A, false);
	fft(B, false);
	vcd C(sz(A));
	
	forn(i, sz(C))C[i] = A[i] * B[i];
	//IFFT(C);
	fft(C, true);
	vector<int> v(sz(A));
	int r = 0;
	
	forn(i, sz(C)){
		v[i] = int(C[i].real() + 0.5) + r;
		if(v[i] >= 10){
			r = v[i]/10;
			v[i] %= 10;
		}
		else r = 0;
	}
	int a = sz(v)-1;
	while(v[a] == 0)a--;

	rforn(i, a+1)cout << v[i];
	if(a < 0)cout << "0";
	cout << "\n";
}

int main(){
	string s, t;
	ios_base::sync_with_stdio(false);
	TEST(n){
		vcd A, B;
		cin >> s >> t;
		rforn(i, sz(s)){
			A.push_back(cd(s[i] - '0',0));
		}
		rforn(i, sz(t)){
			B.push_back(cd(t[i] - '0',0));
		}
		int k = 1, ta, tb;
		
		while(k < (sz(A) + sz(B)))k *= 2;
		ta = k - sz(A);
		tb = k - sz(B);
		forn(i, ta)A.push_back(cd(0,0));
		forn(i, tb)B.push_back(cd(0,0));
		mult(A, B);
	}
	
	return 0;
}



