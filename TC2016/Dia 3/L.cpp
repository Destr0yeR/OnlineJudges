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

#define MAX 41622

vi p, v;
bitset<MAX> b;
map<int, int> rp;

void sieve(){
	b.set();
	b[0] = b[1] = 1;
	int sq = sqrt(MAX);
	
	int cnt = 1;
	p.push_back(2);
	rp[2] = 0;
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	for(int i = 3 ; i <= sq ; i+=2)if(b[i])for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
	
	for(int i = 3 ; i < MAX ; i+=2)if(b[i]){rp[i] = cnt++;p.push_back(i);}
}

void getDiv(int n){
	forn(i, sz(p)){
		if(p[i] > n)break;
		if(n%p[i] == 0){
			v.push_back(p[i]);
			while(n%p[i] == 0)n/=p[i];
		}
	}
}
int L;
map<int, int> bc;
#define mod 1000000007
int ans;

void dfs(int node, int par){
	bc[node] = 1;
	if(node > 1 && node < L)ans = (ans + node)%mod;
	
	int next;
	for(int i = par ; i < sz(p) ; ++i){
		if(L/node < p[i])break;
		next = node * p[i];
		if(bc[next] == 0)dfs(next, i);
		else cout << node << " " << next << " " << p[i] << endl;
	}
}

int main(){
	sieve();
	
	int n;
	while(si(n) == 1){
		v.clear();
		bc.clear();
		getDiv(n);
		L = n;
		
		ans = 0;
		forn(i, sz(v))dfs(v[i], rp[v[i]]);
		
		cout << sz(bc) << endl;
		
		printf("%d\n", ans);
	}
}
