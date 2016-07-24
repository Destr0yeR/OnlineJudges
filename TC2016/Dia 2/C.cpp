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

#define MAX 10005

bitset<MAX> vis;
int dis[MAX], low[MAX], par[MAX], orden, p[MAX];

typedef pair<int, int> node;
#define mp(x, y) make_pair(x, y)
#define PB(x) push_back(x) 
#define fi first
#define se second

vi ady[MAX];

vector<node> v;

void dfs(int curr){
	
	low[curr] = dis[curr] = ++orden;
	vis[curr] = 1;
	int next;
	
	forn(i, sz(ady[curr])){
		next = ady[curr][i];
		
		if(vis[next] == 0){
			par[next] = curr;
			dfs(next);
			low[curr] = min(low[curr], low[next]);
			if(low[next] == dis[next]){
				v.PB(mp(curr, next));
			}
		}
		else if(next != par[curr]){
			low[curr] = min(low[curr], low[next]);
		}
	}
}

int Find(int x){return (p[x] == x)?x:p[x] = Find(p[x]);}
void Union(int x, int y){p[Find(x)] = Find(y);}

void init(){
	forn(i, MAX){
		ady[i].clear();
		par[i] = low[i] = dis[i] = -1;
		p[i] = i;
	}
	v.clear();
	vis.reset();
	orden = 0;
}

int main(){
	int n, m , q, x, y;
	while(sii(n, m)){
		si(q);
		if(n == 0 && m == 0 && q == 0)break;
		init();
		
		forn(i, m){
			sii(x, y);
			x--;y--;
			ady[x].PB(y);
			ady[y].PB(x);
		}
		
		forn(i, n)if(vis[i] == 0)dfs(i);
		forn(i, sz(v))Union(v[i].fi, v[i].se);
		
		forn(i, q){
			sii(x, y);
			x--; y--;
			if(Find(x) == Find(y))puts("Y");
			else puts("N");
		}
		puts("-");
	}
}
