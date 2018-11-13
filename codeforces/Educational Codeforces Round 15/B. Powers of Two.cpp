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

typedef complex<long double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;
typedef vector<int>::iterator vit;

const double PI = 4*atan(1);
const double TPI = 2*PI;

int main(){
	ll n;  cin >> n;
	
	vector<ll> power, a;
	power.resize(32);
	a.resize(n);
	power[0] = 1;
	
	forr(i, 1, 32) {
		power[i] = power[i - 1] * 2;
	}
	
	map<ll, ll> mp;
	forn(i, n) {
		cin >> a[i];
		mp[a[i]]++;
	}
	
	ll ans = 0;
	
	forn(i, n) {
		forn(j, 32) {
			ll check = power[j] - a[i];
			
			if(mp[check] > 0 ){
				if(check == a[i]) {
					ans += mp[check] - 1;
				}
				else {
					ans += mp[check];
				}
			}
		}
	}
	
	cout << ans/2 << endl;
	
	return 0;
}
