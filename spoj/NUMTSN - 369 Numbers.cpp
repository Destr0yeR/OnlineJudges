#include <bits/stdc++.h>

#define si(x) scanf("%d", &(x))
#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define forr(i, a, b) for(int i = a, i < b ; ++i)
#define rforn(i, n) for(int i = n-1 ; i >= 0 ; --i)
#define rforr(i, a, b) for(int i = a-1, i >= b ; --i)

#define MAX 55

#define MOD 1000000007

#define mset(x, y) memset(x, y, sizeof(y))

typedef long long ll;

using namespace std;

ll memo[MAX][MAX][MAX][MAX];
ll dp[MAX][MAX][MAX][MAX];

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

ll sol(int dig, int nt, int ns, int ne){
	if(nt >= MAX || ns >= MAX || ne >= MAX)return 0;
	if(dig == 0){
		if(nt == ns && ns == ne){
			return nt >= 1;
		}
		return 0;
	}
	if(memo[dig][nt][ns][ne])return dp[dig][nt][ns][ne];
	memo[dig][nt][ns][ne] = 1;
	
	ll ans = 0LL;
	
	for(int i = 0 ; i < 10 ; ++i){
		if(i == 3){
			ans = (ans + sol(dig-1, nt+1, ns, ne)%MOD)%MOD;
		}
		else if(i == 6){
			ans = (ans + sol(dig-1, nt, ns+1, ne)%MOD)%MOD;
		}
		else if(i == 9){
			ans = (ans + sol(dig-1, nt, ns, ne+1)%MOD)%MOD;
		}
		else{
			ans = (ans + sol(dig-1, nt, ns, ne)%MOD)%MOD;
		}
	}
	
	return dp[dig][nt][ns][ne] = ans%MOD;
}

ll solve(string x){
	
	int j, sz;
	j = sz = x.size();
	ll ans = 0LL;
	
	int curr;
	int nt, ns, ne;
	
	nt = ns = ne = 0;
	
	for(int i = 0 ; i < sz ; ++i){
		j--;
		curr =  x[i] - '0';
		for(int k = 0 ; k < curr ; ++k){
			if(k == 3){
				ans = (ans + sol(j, nt+1, ns, ne)%MOD)%MOD;
			}
			else if(k == 6){
				ans = (ans + sol(j, nt, ns+1, ne)%MOD)%MOD;
			}
			else if(k == 9){
				ans = (ans + sol(j, nt, ns, ne+1)%MOD)%MOD;
			}
			else{
				ans = (ans + sol(j, nt, ns, ne)%MOD)%MOD;
			}
		}
		
		if(curr == 3)nt++;
		else if(curr == 6)ns++;
		else if(curr == 9)ne++;
	}
	
	return ans%MOD;
}

int main()
{
	int t;
	string a, b;
	
	si(t);
	
	mset(memo, 0);
	mset(dp, 0);
	
	forn(i, t){
		cin >> a >> b;
		cout << (solve(add(b)) - solve(a) + 2*MOD)%MOD << "\n";
	}
	
	
    return 0;
}
