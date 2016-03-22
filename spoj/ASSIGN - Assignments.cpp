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

#define count_bits(x) __builtin_popcount(x)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

int n;

#define MAX 21

ll dp[(1 << MAX)];

int ady[MAX][MAX];

int main(){
	int curr;
	
	TEST(t){
		si(n);
		mset(dp, 0);
		mset(ady, 0);
		forn(i, n)forn(j, n)cin >> ady[i][j];
		dp[(1 << n)-1] = 1;
		
		rforn(i, (1 << n)-1){
			curr = count_bits(i);
			
			forn(j, n)if(ady[curr][j] && !(i & (1 << j))){
				dp[i] += dp[i | (1 << j)];
			}
		}
		
		cout << dp[0] << "\n"; 
	}

	return 0;
}
