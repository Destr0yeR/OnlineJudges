#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;
typedef unsigned long long ll;

map<int, int> mx, my;
map< pair<int, int>, int> m;

int main(){
	int n, x, y;
	si(n);
	
	ll ans = 0;
	
	forn(i, n){
		sii(x, y);
		ans += (mx[x] + my[y] - m[make_pair(x, y)]);
		mx[x]++;
		my[y]++;
		m[make_pair(x, y)]++;
	}
	
	cout << ans << endl;

	return 0;
}



