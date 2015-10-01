#include<bits/stdc++.h>
#define MAX 10000001
#define MOD 1000000007

using namespace std;

//long long dp[2][MAX];

long long solve(/*int p, */int n){
	/*if(dp[p][n] != -1)return dp[p][n];
	cout << p << " " << n << endl;
	if(p == 1){
		
		return dp[1][n] = (solve(0,n-1)%MOD + 2*solve(1,n-1)%MOD)%MOD;
	}
	else{
		return dp[0][n] = (3*solve(1,n-1))%MOD;
	}
	*/
	long long d = 1, nd = 0, aux, tmp;
	
	for(int i = 1 ; i <= n ; ++i){
		aux = (3*nd)%MOD;
		tmp = (nd*2 + d)%MOD;
		d = aux;
		nd = tmp;
	}
	return d;
}

int main(){
	
	int n;
	cin >> n;
	/*memset(dp, -1, sizeof(dp));
	
	dp[0][0] = 1;
	dp[1][0] = 0;
	*/
	//solve(0, n);
	
	//cout << dp[0][n] << endl;
	
	cout << solve(n) << endl;
	
	return 0;
}
