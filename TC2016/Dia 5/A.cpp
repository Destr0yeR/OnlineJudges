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


#define MAX 1000001

bitset<MAX> b;
vector<int> p;

void sieve(){
	b.set();
	
	int sq = sqrt(MAX);
	b[0] = b[1] = 0;
	for(int i = 4 ; i < MAX ; i+=2)b[i] = 0;
	for(int i = 3 ; i <= sq ; i+=2)if(b[i])for(int j=i;j*i<MAX;j++)b[i*j] = 0;

	int cont = 0;
	for(int i = 3 ; i < MAX ; i+=2)if(b[i]){
		p.push_back(i);
		cont++;
	}
}

int main(){
	sieve();
	int n, sz, a;
	
	while(scanf("%d", &n)){
		if(n == 0)break;
		sz = p.size();
		for(int i = 0 ; i < sz ; ++i){
			a = p[i];
			if(2*a > n)break;
			if(b[n-a] == 1)break;
		}
		
		if(2*a <= n)printf("%d = %d + %d\n", n, a, n-a);
		else puts("Goldbach's conjecture is wrong.");
	}
}
