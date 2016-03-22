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

#define MAX 22
#define MAXN 82

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int K;


ull memo[MAX][MAXN][MAXN];
ull dp[MAX][MAXN][MAXN];

ll expo[15];

string add(string s){
	int sz = s.size();
	
	bool lev = false;
	
	rforn(i, sz){
		if(s[i] == '9'){
			s[i] = '0';
			lev = true;
		}
		else{
			s[i]++;
			lev = false;
		}
		if(!lev)break;
	}
	
	if(lev){
		s = "1" + s;
	}
	
	return s;
}

ll F(int dig, int rsum, int rdig){

	if(memo[dig][rsum][rdig])return dp[dig][rsum][rdig];
	memo[dig][rsum][rdig] = 1;
	if(dig == 0){
		return dp[dig][rsum][rdig] = (rsum == 0 && rdig == 0);
	}
	
	ll ans = 0LL;
	
	forn(i, 10){
		ans += F(dig-1, (rsum + i)%K, (rdig + i*(expo[dig-1]%K))%K);
	}
	
	return dp[dig][rsum][rdig] = ans;
}

ll solve(string x){
	ll ans = 0LL;
	int rsum = 0, rdig = 0;
	
	int len, j, curr;
	j = len = (int)x.size();
	
	forn(i, len){
		j--;
		curr = x[i] - '0';
		forn(k, curr){
			ans += F(j, (rsum + k)%K, (rdig + k*(expo[j]%K))%K); 
		}
		rsum = (rsum + curr)%K;
		rdig = (rdig + curr*(expo[j]%K))%K;
	}
	
	return ans;
}

int main(){
	int t;
	string a, b;
	si(t);
	
	expo[0] = 1;
	for(int i = 1 ; i < 15 ; ++i)expo[i] = 10*expo[i-1];
	
	while(t--){
		mset(memo, 0);
		mset(dp, 0);
		
		cin >> a >> b >> K;
		
		if(K > 82) cout << "0\n";
		else cout << solve(add(b)) - solve(a) << "\n";
	}
	
	return 0;
}
