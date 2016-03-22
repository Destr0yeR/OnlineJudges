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

typedef long long ll;

int c[25];

ll solve(ll n){
	ll ans = (n/25)*15;
	int res = n%25;
	
	return ans + c[res];
}

int main()
{
	ll n;
	int x = 1;
	for(int j = 0 ; j < 25 ; j+=10){
		for(int i = 0 ; i < 5 ; ++i){
			c[i+j] = x++;
		}
	}
	
	while(cin >> n){
		if(n == -1)break;
		cout << solve(n) << "\n";
	}
    return 0;
}
