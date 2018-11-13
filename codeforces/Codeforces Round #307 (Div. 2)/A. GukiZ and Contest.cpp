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
typedef pair<int, int> pii;

const double PI = 4*atan(1);
const double TPI = 2*PI;

bool cmp(pii a, pii b) {
	return a.second > b.second;
}

int main(){
	int n, x;
	
	vector< pii > a;
	vi ans;
	
	si(n);
	ans.resize(n);
	a.resize(n);
	
	forn(i, n) {
		si(x);
		a[i] = pii(i, x);
	}
	
	sort(all(a), cmp);
	
	int last = 20001;
	int position = 0;
	int real = 0;
	
	forn(i, n) {
		real ++;
		if(a[i].second < last) {
			position = real;
			
		}
		last = a[i].second;
		ans[a[i].first] = position;
	}
	
	forn(i, n) {
		if(i)printf(" ");
		printf("%d", ans[i]);
	}
	
	puts("");
	
	return 0;
}
