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

#define MAX 1002

using namespace std;

typedef long long ll;

ll memo[MAX][MAX];

int g[MAX], h[MAX];

int n, m;
vector<string> gc, hc;

struct ans{
	int c;
	ll v;
	ans(){};
	ans(int _c, int _v){c = _c; v = _v;}
	ans operator+(const ans &b)const{
		return ans(c + b.c, v + b.v);
	}
	bool operator<(const ans &b)const{
		if(v == b.v)return c > b.c;
		return v < b.v;
	}
};

ans dp[MAX][MAX];

ans F(int i, int j){
	if(i == n || j == m)return ans(0, 0);
	if(memo[i][j] == 1)return dp[i][j];
	memo[i][j] = 1;
	
	int k = j;
	
	while(gc[i] != hc[k] && k < m - 1)k++;
	int v = 0, c = 0;
	if(gc[i] == hc[k]){
		c = 1;
		v = g[i] + h[k];
	}
	
	return dp[i][j] = max(max(F(i+1, j), ans(c, v) + F(i+1, k+1)), F(i, j+1));
}

int main(){
	string cit, so;
	int v;
	ans rta;
	
	TEST(t){
		si(n);
		gc.clear();
		hc.clear();
		mset(memo, 0);
		
		forn(i, n){
			cin >> cit >> so >> v;
			gc.push_back(so);
			g[i] = v;
		}
		si(m);
		forn(i, m){
			cin >> cit >> so >> v;
			hc.push_back(so);
			h[i] = v;
		}
		rta = F(0, 0);
		cout << rta.v << " " << rta.c << endl;
	}

	return 0;
}



