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
	int n; si(n);
	
	ll mat[n][n];
	
	int c, r;
	
	vector<long long> b, u;
	b.resize(n);
	u.resize(n);
	
	forn(i, n)forn(j, n) {
		cin >> mat[i][j];
		if(!mat[i][j]) {
			c = i;
			r = j;
		}
		b[i] += mat[i][j];
		u[j] += mat[i][j];
	}
	
	if(n == 1) {
		puts("1");
		return 0;
	}
	
	int test = 1;
	ll sum = 0;
	
	if(c > 0) test = 0;
	
	forn(i, n) sum += mat[test][i];
	
	ll inRow = 0, inColumn = 0;
	
	forn(i, n) {
		inRow += mat[c][i];
		inColumn += mat[i][r];
	}
	
	ll sumDiagonal = 0, sumTrans = 0;
	
	mat[c][r] = sum - inRow;
	forn(i,n) {
		sumDiagonal += mat[i][i];
		sumTrans += mat[i][n-i-1];
	}
	
	bool different = false;
	forn(i, n) {
		if(i != c) {
			if(b[i] != sum) {
				different = true;
			}
		}
		if(i != r) {
			if(u[i] != sum) {
				different = true;
			}
		}
	}
	
	
	if(inRow != inColumn || inRow >= sum || sumDiagonal != sumTrans || sumDiagonal != sum || different) {
		puts("-1");
	}
	else {
		cout <<  sum - inRow << endl;
	}
	
	return 0;
}
