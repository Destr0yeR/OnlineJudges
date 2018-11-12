#include<bits/stdc++.h>

#define forn(i, n) for(int i = 0 ; i < n ; ++i)
#define si(x) scanf("%d", &x)
#define sii(x, y) scanf("%d %d", &x, &y)

using namespace std;

#define W first
#define V second

vector< pair<int, int> > v;

int dp[1001][51];

int solve(int k, int m) {
	
	pair<int, int> p = v[0];
	
	for (int i = 0; i <= k; i++)
	{
		dp[i][0] = p.W <= i ? p.V: 0;
	}
	
	
	for (int i = 1; i < m; i++)
	{
		p = v[i];
		
		for (int j = 0; j <= k; j++)
		{
			dp[j][i] = (p.W <= j) ?  max(dp[j-p.W][i-1] + p.V, dp[j][i-1]) : dp[j][i-1];
		}
		
	}
	
	
	return dp[k][m-1];
}

int main() {
	
	int n, k, m, x, y;
	
	si(n);
	
	forn(tc, n){
		sii(k, m);
		
		v.clear();
		v.resize(m);
		
		forn(i, m){
			sii(x, y);
			v[i] = make_pair(x, y);
		}
		
		printf("Hey stupid robber, you can get %d.\n", solve(k, m));
	}
	
	return 0;
}
