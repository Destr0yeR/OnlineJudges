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

#define MAX 1000001

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	b[0] = b[1] = 0;
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	for(int i = 3 ; i <= sq ; i+=2)if(b[i])for(int j=i;j*i<MAX;j++)b[i*j] = 0;

	p.push_back(2);
	for(int i = 3 ; i < MAX ; i+=2)if(b[i])p.push_back(i);
}

bool isPrime(ll n){
	if(n < 2)return false;
	ll sq = sqrt(n);
	
	forn(i, sz(p)){
		if(p[i] > sq)break;
		if(n%p[i] == 0)return false;
	}
	
	return true;
}

int main(){
	ll m, n;
	sieve();
	TEST(t){
		sll(m);
		sll(n);
		for(ll i = m ; i <= n ; ++i){
			if(isPrime(i))printf("%lld\n", i);
		}
		puts("");
	}
}
