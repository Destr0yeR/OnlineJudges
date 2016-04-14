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

#define MAX 1000002
#define MOD 1000000007

ll a[MAX];
ll s[MAX];

int main(){
	int n;
	ll ans = 0;
    si(n);
    
    forn(i, n)sll(a[i]);
	
	forn(i, n){
		ans += a[i]-1;
		ans %= MOD;
	}

    s[0] = 0;
    s[1] = min(a[0]-1, a[1]-1);
    forr(i, 2, n)s[i] = (min(a[i] - 1, a[i-1] - 1) + (s[i - 1] * min(a[i - 2] - 1, min(a[i - 1] - 1, a[i] - 1)))%MOD)%MOD;

	forr(i, 1, n)ans = (ans + (min(a[i] - 1, a[i - 1] - 1) * s[i])%MOD)%MOD;

    cout << ans << endl;

    return 0;
}

