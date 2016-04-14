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

#define MAX 200005

struct block{
	int l, r, v;
	
	block(){}
	block(int _l, int _r):l(_l),r(_r){}
	block(int _l, int _r, int _v):l(_l),r(_r),v(_v){}
};

bool cmp(block a, block b){
	return a.l < b.l;
}

bool cmp2(block a, block b){
	return a.r < b.r;
}

vector<block> b;
int ans[MAX];


int tree[1<<21];

int main(){
	
	int n, o, f;
	si(n);
	
	forn(i, n){
		sii(o, f);
		b.push_back(block(o, f));
	}
	
	sort(all(b), cmp);
	
	forn(i, n)b[i].v = i;
	
	sort(all(b), cmp2);
	
	
	
	forn(i, n)printf("%d\n", ans[i]);
	
	return 0;
}

