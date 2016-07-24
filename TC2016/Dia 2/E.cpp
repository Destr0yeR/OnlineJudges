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

map<char, int> mg, ms;

bool check(){
	map<char, int>::iterator it;
	
	for(it = mg.begin() ; it != mg.end() ; it++){
		if(mg[it->first] != ms[it->first])return false;
	}
	return true;
}

int main(){
	int cg, cs;
	string g, s;
	sii(cg, cs);
	cin >> g >> s;
	
	forn(i, sz(g))mg[g[i]]++;
	forn(i, sz(g))ms[s[i]]++;
	int cont = 0;
	
	if(check())cont++;
	
	forr(i, sz(g), sz(s)){
		ms[s[i]]++;
		ms[s[i-sz(g)]]--;
		if(check())cont++;
	}
	
	cout << cont << endl;
}
