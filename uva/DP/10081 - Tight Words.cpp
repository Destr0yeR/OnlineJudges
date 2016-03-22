#include <bits/stdc++.h>

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define sc(c) scanf("%c", &c)
#define ss(s) scanf("%s", s)

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a ; i < b ; ++i)

#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = b-1 ; i >= a ; --i)

#define mset(x, y) memset(x, y, sizeof(x))
#define all(x) x.begin(), x.end()

#define TEST(t) int T; cin >> T; for(int t = 1 ; t <= T ; ++t)

using namespace std;

#define MAXK 11
#define MAXN 101

typedef long double ll;

int memo[MAXK][MAXN];
ll dp[MAXK][MAXN];
int lim;

ll cua(ll x){return x*x;}

ll expo(int b, int e){
	if(e == 0)return 1;
	if(e == 1)return b;
	
	if(e%2 == 0)return cua(expo(b, e/2));
	
	return b*cua(expo(b,e/2));
}

ll F(int k, int n){
	if(k < 0 || k >= lim)return 0;
	if(n == 1)return 1;
	if(memo[k][n] == 1)return dp[k][n];
	memo[k][n] = 1;
	
	return dp[k][n] = F(k-1, n-1) + F(k, n-1) + F(k+1, n-1);
}

int main(){
	int n, k;
	ll ans = 0.0, res = 0.0;
	while(sii(k, n) == 2){
		mset(memo, 0);
		ans = 0;
		lim = k+1;
		forn(i, lim){
			ans += F(i, n);
		}
		
		res = (double)(ans*100.0)/(double)(expo(k+1, n));
		cout.precision(5);
		
		printf("%.5Lf\n", res);
	}
	return 0;
}



