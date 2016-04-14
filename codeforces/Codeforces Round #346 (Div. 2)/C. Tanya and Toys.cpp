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

#define MAX 100001

int a[MAX];
	vi ans;
	set<int> st;

int main(){
	int n, m;
	
	sii(n, m);
	forr(i, 1, n+1){
		si(a[i]);
		st.insert(a[i]);
	}
	
	forr(i, 1, m+1){
		if(st.count(i)) continue;
		if(m >= i) ans.push_back(i), m -= i;
		else break;
	}
	
	printf("%d\n", sz(ans));
	forn(i, sz(ans)) printf("%d ", ans[i]);
	
	return 0;
}

