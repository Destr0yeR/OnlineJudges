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
	map<int, int> mp;
	
	int fThree = 0, fTwo = 0, sum = 0, x;
	bool isTwo = false;
	
	forn(i, 5) {
		si(x);
		mp[x]++;
		sum += x;
	}
	
	for(map<int, int>::reverse_iterator it = mp.rbegin() ; it != mp.rend() ; ++it) {
		if(it->second >= 3) {
			fThree = 3*it->first;
		}
		if(it->second == 2 && !isTwo) {
			isTwo = true;
			fTwo = 2 * it->first;
		}
	}
	
	//cout << fThree << " " << fTwo << endl;
	
	printf("%d\n", min(sum - fThree, sum - fTwo));
	
	return 0;
}
