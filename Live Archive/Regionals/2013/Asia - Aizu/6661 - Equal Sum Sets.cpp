#include<bits/stdc++.h>
#define mset(x, y) memset(x, y, sizeof(x))

using namespace std;

int dp[21][11][156];

int solve(int n, int k, int s){
	if(s < 0 || k < 0)return 0;
	if(dp[n][k][s] !=-1)return dp[n][k][s];
	
	int a = solve(n-1, k, s);
	int b = 0;
	
	if(s >= n && k > 0){
		b = solve(n-1, k-1, s-n);
	}

	return dp[n][k][s] =  a + b;
}

int main(){
	int n, s, k;
	
	while(cin >> n >> k >> s){
		if(n == 0 && k == 0 && s == 0)break;
		mset(dp,-1);
		mset(dp[0], 0);
		dp[0][0][0] = 1;
		
		cout << solve(n,k,s) << endl;
	}
	
	return 0;
}
