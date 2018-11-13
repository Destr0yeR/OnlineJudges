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

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main(){
	int n; si(n);
	
	vector<pair<int, int> > a; a.resize(n);
	
	forn(i, n) {
		int x; si(x);
		a[i] = pair<int, int> (x, i+1);
	}
	
	sort(all(a), cmp);
	
	vector<pair<int, int> > b, c;
	b.resize(n);
	c.resize(n);
	
	bool first = false, second = false;
	
	forn(i, n) {
		b[i] = c[i] = a[i];
	}
	
	forn(i, n) forr(j, i+1, n) {
		if(a[i].first == a[j].first) {
			if(!first) { 
				swap(b[i], b[j]);
				first = true;
			}
			else if(!second) {
				swap(c[i], c[j]);
				second = true;
				break;
			}
		}
	}
	
	if(!first || !second) {
		puts("NO");
	}
	else {
		puts("YES");
		forn(i, n) {
			if(i)printf(" ");
			printf("%d", a[i].second);
		}
		puts("");
		
		forn(i, n) {
			if(i)printf(" ");
			printf("%d", b[i].second);
		}
		puts("");
		
		forn(i, n) {
			if(i)printf(" ");
			printf("%d", c[i].second);
		}
		puts("");
	}
	
	return 0;
}
