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
	si(n);
	vi a;
	if(n == 1 || n == 2) {
		puts("1");
		puts("1");
		return 0;
	}
	if(n == 3) {
		puts("2");
		puts("1 3");
		return 0;
	}
	if(n == 4) {
		puts("4");
		puts("3 1 4 2");
		return 0;
	}
	
	a.resize(n);
	bool taken = false;
	
	int j = 0;
	
	forn(i, n) {
		a[j] = i;
		j+=2;
		if(j >= n && !taken) {
			j = 1;
			taken = true;
		}
	}
	printf("%d\n", n);
	forn(i, n) {
		if(i)printf(" ");
		printf("%d", a[i] + 1);
	}
	
	return 0;
}
