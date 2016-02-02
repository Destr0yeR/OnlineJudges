#include<bits/stdc++.h>

#define offset 100
#define MAX 1000001

using namespace std;

typedef long long ll;

int memo[19][201];
ll dp[19][201];

ll F(int dig, int sum){
	if(dig == 0)return sum == 1;
	if(memo[dig][sum + offset] == 1)return dp[dig][sum + offset];
	
	memo[dig][sum + offset] = 1;
	
	ll ans = 0LL;
	
	for(int i = 0 ; i < 10 ; ++i){
		
	}
	
	return dp[dig][sum + offset] = ans;
}

ll solve(ll x){
	ll ans = 0LL;
	
	char cad[20];
	
	sprintf(cad, "%lld", x);
	
	int l = strlen(cad);
	
	int j = l;
	
	return ans;
}

int main(){
	int T;
	
	scanf("%d", &T);
	
	ll a, b;
	
	for(int tc = 1 ; tc <= T ; ++tc){
		scanf("%lld %lld", a, b);
		printf("%lld\n", solve(b+1) - solve(a));
	}
	
	return 0;
}
