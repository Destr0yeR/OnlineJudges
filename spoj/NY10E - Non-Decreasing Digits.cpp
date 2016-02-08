#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int memo[66][10];
ll dp[66][10];

ll F(int dig, int min){
	if(dig == 1)return 1;
	
	if(memo[dig][min] == 1)return dp[dig][min];
	
	memo[dig][min] = 1;
	
	ll ans = 0LL;
	
	for(int i = min ; i < 10 ; ++i){
		ans += F(dig-1, i);
	}
	
	return dp[dig][min] = ans;
}

ll solve(int x){
	ll ans = 0LL;
	
	for(int i = 0 ; i < 10 ; ++i){
		ans += F(x, i);
	}
	
	return ans;
}


int main(){
	
	int T,d, n;
	
	scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &d, &n);
		printf("%d %lld\n",d , solve(n));
	}
	
	return 0;
}
