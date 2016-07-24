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

#define MAX 1000005
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

struct block{
	int h, i;
	block(){}
	block(int h, int i):h(h), i(i){}
};

bool cmp(block a, block b){
	return a.h < b.h;
}

bitset<MAX> b;

vector<block> v;

int main(){
	int n, h;
	int tot = 1;
	int ans = 1;
	
	si(n);
	
	b.reset();
	b[0] = b[n+1] = 1;
	
	forn(i, n){
		si(h);
		v.push_back(block(h, i+1));
	}
	sort(all(v), cmp);
	
	int ante = -1;
	forn(i, n){
		if(ante != v[i].h)ans = max(ans, tot);
		b[v[i].i] = 1;
		
		if(b[v[i].i-1] == 0 && b[v[i].i+1] == 0)tot ++;
		else if(b[v[i].i-1] == 1 && b[v[i].i+1] == 1)tot--;
		
		ante = v[i].h;
	}
	
	printf("%d\n", ans);
}
