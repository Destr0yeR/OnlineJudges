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

#define MAX 1000006
#define mod 10000000000

vector<ll> v;
bitset<MAX> b;

void sieve(){
	b.set();
	
	b[0] = b[1] = 0;
	int sq = sqrt(MAX);
	
	
	for(int i = 4; i < MAX; i+=2)b[i] = 0;
	for(int i = 3; i <= sq; i+=2)if(b[i])for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
}

ll dp[MAX];

string to(ll x){
	string s = "";
	
	while(x > 0LL){
		s = char(x%10LL + '0') + s;
		x /= 10LL;
	}
	
	for(int i = sz(s) ; i < 10 ; i++){
		s = "0"+s;
	}
	
	return s;
}

int main(){
	int n;
	sieve();
	
	dp[1] = 1LL;
	
	for(ll i = 2LL ; i < MAX; i++){
		dp[i] = (dp[i-1]*(b[i]?i:1LL))%mod;
	}
	
	TEST(t){
		si(n);
		if(n < 30)printf("%lld\n", dp[n]);
		else cout << to(dp[n]) << "\n";
	}
}
