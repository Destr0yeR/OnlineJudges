#include<bits/stdc++.h>

using namespace std;

int dp[101];

int f(int x){
	if(dp[x] != -1)return dp[x];
	
	return dp[x] = x*x + f(x-1);
}

int main(){
	
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	
	int n;
	
	while (cin >> n){
		if(n == 0)break;
		cout << f(n) << endl;
	}
	
	
	return 0;
}
