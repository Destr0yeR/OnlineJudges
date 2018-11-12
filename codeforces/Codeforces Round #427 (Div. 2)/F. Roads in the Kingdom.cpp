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

#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<long double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

#define INF (1<<30)

struct node{
	int u, w;
	
	node(int to, int w):to(to), w(w){}
	node(){}
	
	bool operator < (const node &b) const{
		return to < b.to;
	}
};

vi dist;
vector <vector<node> > g;
vi vis;

void dijkstra(int src){
	priority_queue<node> q;
	
	q.push(node(src, 0));
	dist[src] = 0;
	
	node curr;
	
	while(!q.empty()) {
		curr = q.top();
		q.pop();
		
		if(vis[curr.u] == 1)continue;
		vis[curr.u] = 1;
		
		forn(i, sz(g[curr.u])) {
			node next = g[curr.u][i];
			if(vis[next.u] == 1)continue;
			
			if(dist[curr.u] + next.w < dist[next.u]){
				dist[next.u] = dist[curr.u] + w;
				q.push(node(next.u, dist[next.u]);
			}
		}
	}
}

int main(){
	int n;
	si(n);
	
	g.clear();
	vis.clear();
	dist.clear();
	
	g.resize(n);
	vis.resize(n);
	dist.resize(n);
	
	forn(i, n)dist[i] = INF;
	
	int u, v, l;
	forn(i, n) {
		sii(u, v); si(l);
		u--; v--;
		g[u].pb(node(u, l));
		g[v].pb(node(v, l));
	}
	
	int src = -1, lst = 0;
	
	forn(i, n){
		if(sz(g[i]) > 1)continue;
		if(lst < g[i][0].w) {
			lst = g[i][0].w;
			src = i;
		}
	}
	
	if(src == -1){
		forn(i, n){
			
		}
		return 0;
	}
	
	cout << src << endl;
	
	dijkstra(src);

	return 0;
}
