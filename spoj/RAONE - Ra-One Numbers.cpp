#include<bits/stdc++.h>

#define offset 100
#define MAX 1000001

using namespace std;

typedef long long ll;

int memo[19][301];
ll dp[19][301];
int len;

ll F(int dig, int sum){
	if(dig == 0)return sum == 1;
	if(memo[dig][sum + offset] == 1)return dp[dig][sum + offset];

	memo[dig][sum + offset] = 1;

	ll ans = 0LL;

	for(int i = 0 ; i < 10 ; ++i){
        if(dig %2 == 0) ans += F(dig - 1, sum + i);
        else ans += F(dig - 1, sum -i);
	}

	return dp[dig][sum + offset] = ans;
}

ll solve(ll x){
	ll ans = 0LL, sum = 0LL;

	char cad[20];

	sprintf(cad, "%lld", x);

	len = strlen(cad);

	int j = len;

	for(int i = 0 ; i < len ; ++i){
        j--;

        int d = cad[i] - '0';

        for(int k = 0 ; k < d; ++k){
            if((j+1) %2 == 0){
                ans += F(j, sum + k);
            }
            else{
                ans += F(j, sum - k);
            }
        }
        if((j+1) % 2 == 0)sum += d;
        else sum -= d;
	}

	return ans;
}

int main(){
	int T;

	scanf("%d", &T);

	ll a, b;

	for(int tc = 1 ; tc <= T ; ++tc){
		scanf("%lld %lld", &a, &b);
		printf("%lld\n", solve(b+1) - solve(a));
	}

	return 0;
}
