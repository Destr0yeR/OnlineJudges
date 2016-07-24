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

typedef unsigned long long ull, ll;

typedef complex<double> cd;

typedef vector<int> vi;
typedef vector<cd> vcd;

#define MAX (1 << 31)

ll f(ll a,ll b){
	ll ans = 0ULL;
	ll x;
	while(a>=b){
		x = a/b;
		ans += x;
		a = x;
	}
	return ans;
}
string octal(ll n){
	if(n == 0LL)return "0";
	string s="";
	int x;
	while(n>0ULL){
		x=n%8ULL;
		n/=8ULL;
		s=char(x+'0')+s;
	}
	return s;
}
int main(){
	ll a,b,p;
	ll x,y;
	
	while(cin >> a>>b>>p){
		x=f(b,p);
		y=f(a-1,p);
		ll aux=(x-y);
		string k=octal(aux);
		cout<<k<<endl;
	}
	return 0;
}
