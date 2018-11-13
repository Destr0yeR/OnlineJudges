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

const double PI = 4*atan(1);
const double TPI = 2*PI;

int main(){
	int n;
	vi a, res;
	
	si(n);
	a.resize(n);
	res.resize(n);
	
	forn(i, n)si(a[i]);
	
	int dp[n+1][3];
	
	dp[0][0] = 0;
	dp[0][1] = (a[0] == 1 || a[0] == 3) ? 1 : 0;
	dp[0][2] = (a[0] == 2 || a[0] == 3) ? 1 : 0;
	
	forr(i, 1, n) {
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
		dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + ((a[i] == 1 || a[i] == 3) ? 1 : 0);
		dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + ((a[i] == 2 || a[i] == 3) ? 1 : 0);
	}
	/*
	forn(i, n) {
		cout << i << " -> " << dp[i][0] << " - " << dp[i][1] << " - " << dp[i][2] << endl;
	}*/
	
	int maxi = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	
	printf("%d\n", n - maxi);
	
	return 0;
}
