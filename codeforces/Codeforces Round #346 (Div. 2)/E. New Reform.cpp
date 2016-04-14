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

#define MAX 100001

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

vi ady[MAX];
bitset<MAX> vis;

bool dfs(int u, int v){
	vis[u] = 1;
	bool cycle = false;
	int curr;
	
	forn(i, sz(ady[u])){
		curr = ady[u][i];
		if(curr == v)continue;
		if(vis[curr]){
			cycle = true;
			continue;
		}
		cycle = cycle or dfs(ady[u][i], u);
	}
	
	return cycle;
}

int main(){
	
	int n, m, x, y, ans;
	sii(n, m);
	vis.reset();
	
	forn(i, m){
		sii(x, y);
		x--;
		y--;
		ady[x].push_back(y);
		ady[y].push_back(x);
	}
	ans = 0;
	forn(i, n){
		if(vis[i])continue;
		ans += dfs(i, -1)?0:1;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

