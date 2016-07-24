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


int main(){
	string s;
	int n;
	
	cin >> s >> n;
	cout << "Tournament: " << s << endl;
	cout << "Number of players: " << n << endl;
	cout << "New ratings:" << endl;
	
	double w, we, rad, me = 0;
	int ra, k;
	
	forn(i, n){
		cin >> s >> ra >> w >> we >> k;
		me += (ra * 1.0)/(n*1.0);
		rad = ra + (k * 1.0) * (w - we);
		ra = int(rad + 0.5);
		cout << s << " " << ra << endl;
	}
	
	cout << "Media Elo: " << int(me + 0.5) << endl;
}

