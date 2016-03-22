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

#define MAXM 101

using namespace std;

int memo[MAXM][2];
int dp[MAXM][2];

int sw[105];
int step[1<<17];

void solve(){
	int n, m, x;
	sii(n, m);
	mset(step, 0);
	forn(i, m){
		sw[i] = 0;
		forn(j, n){
			si(x);
			sw[i] |= x<<j;
		}
	}
	
	queue<int> Q;
	int tn, tm;
	
	Q.push((1<<n)-1);
	step[(1<<n)-1] = 1;
	
	while(!Q.empty() && step[0] == 0) {
		tn = Q.front(), Q.pop();
		forn(i, m) {
			tm = tn^sw[i];
			if(step[tm] == 0) {
				step[tm] = step[tn]+1;
				Q.push(tm);
			}
		}
	}
	
	if(step[0] == 0)puts("IMPOSSIBLE");
	else printf("%d\n", step[0]-1);
}

int main(){
	mset(memo, 0);
	
	TEST(t){
		printf("Case %d: ", t);
		solve();
	}

	return 0;
}
