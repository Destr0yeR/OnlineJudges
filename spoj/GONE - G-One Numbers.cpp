#include<bits/stdc++.h>

#define MAX 201

using namespace std;

typedef long long ll;

bitset<MAX> b;
ll total;
int memo[19][181];
ll dp[19][181];

void sieve(){
	b.set();
	b[0] = b[1] = 0;
	
	int sq = sqrt(MAX);
	
	for(int i = 4 ;  i < MAX ; i+=2)b[i] = 0;
	
	for(int i = 3 ; i <= sq ; i+=2)if(b[i] == 1)for(int j = i ; j*i < MAX ; j+=2)b[i*j] = 0;
}

ll F(int dig, int sum){
	total++;
	if(dig == 0)return b[sum];
	if(memo[dig][sum])return dp[dig][sum];
	
	memo[dig][sum] = 1;
	
	ll ans = 0LL;
	
	for(int i = 0 ; i < 10 ; ++i){
		ans += F(dig-1, sum + i);
	}
	
	return dp[dig][sum] = ans;
}

ll solve(ll x){
	ll ans = 0LL, sum = 0LL;
	
	char cad[20];
	
	sprintf(cad, "%lld", x);
	
	int l = strlen(cad);
	int j = l;
	
	for(int i = 0 ; i < l ; ++i){
		j--;
		int d = cad[i] - '0';
		for(int k = 0 ; k < d ; ++k){
			ans += F(j, sum + k);
		}
		sum+=d;
	}
	
	return ans;
}

int main(){
	sieve();
	
	int T;
	ll a, b;
	
	scanf("%d", &T);
	total = 0;
	for(int tc = 1 ; tc <= T ; ++tc){
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", solve(b+1) - solve(a));
	}
	
	return 0;
};
