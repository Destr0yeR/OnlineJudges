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

#define INF (1<<30)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

int n;

struct node{
	int x, y, w, f;
};

int dist[MAX][MAX];

struct cmp{
	bool operator () (const node &a, const node &b){
		return a.w > b.w;
	}
};

void dijkstra(){
	forn(i, n)forn(j, n)dist[i][j] = INF;
	
	q.push(node(0, 0, 0, 0));
	dist[0][0] = 0;
}

int main(){
	
}
