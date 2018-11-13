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

vector<vector<pair<int, int > > > graph;
vector<bool> visit;

bool dfs(int current, const int &target, const int &color) {
	if(current == target)return true;
	visit[current] = true;
	
	for(size_t i = 0 ; i < graph[current].size() ; ++i) {
		pair<int, int> next = graph[current][i];
		
		if(visit[next.first]) continue;
		if(next.second != color) continue;
		if(dfs(next.first, target, color)) return true;
	}
	
	return false;
}

int main(){
	int n, m; sii(n, m);
	
	int u, v, c;
	
	set<int> st;
	
	graph.resize(n+1);
	
	forn(i, n)graph[i].clear();
	
	forn(i, m) {
		sii(u, v); si(c);
		
		graph[u].push_back(pair<int,int> (v, c));
		graph[v].push_back(pair<int,int> (u, c));
		
		st.insert(c);
	}
	
	int q; si(q);
	
	visit.resize(n+1);
	
	forn(i, q) {
		int ans = 0;
		sii(u, v);
		
		for(set<int>::iterator it = st.begin() ; it != st.end() ; ++it) {
			fill(all(visit), false);
			if(dfs(u, v, *it)) ans++;
		}
		
		printf("%d\n", ans);
	}
	
	return 0;
}
