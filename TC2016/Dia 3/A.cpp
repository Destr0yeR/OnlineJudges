#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define sz(x) (int)x.size()

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

#ifdef ONLINE_JUDGE
	#define sll(x) scanf("%I64d", &x)
#else
	#define sll(x) cin >> x
#endif

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;


#define mod 1000003
#define MAX 1000001

ll per[MAX], mper[MAX];
ll fx[MAX], mfx[MAX];

ll f(int n){
	if(n == 1)return 0LL;
	
	if(mfx[n] == 1)return fx[n];
	mfx[n] = 1;
	
	return fx[n] = ((n%mod)*((1 + f(n-1)%mod)%mod))%mod;
}


ll p(int n){
	if(n == 1)return 1LL;
	
	if(mper[n] == 1)return per[n];
	mper[n] = 1;
	
	return mper[n] = ((n%mod)*(p(n-1)))%mod;
}

ll s(int n){
	return (f(n) + 1)%mod;
}

int main(){
	forn(i,MAX)mfx[i] = mper[i] = 0;
	int n, t;
	si(t);
	
	fx[1] = 0;
	for(int i = 2 ; i < MAX ; ++i){
		fx[i] = ((i%mod)*((1 + f(i-1)%mod)%mod))%mod;
	}
	
	forn(i, t){
		si(n);
		cout << (fx[n] + 1)%mod << "\n";
	}
}
