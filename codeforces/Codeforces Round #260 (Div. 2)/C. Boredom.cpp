#include<bits/stdc++.h>
#define mset(x, y) memset(x, y, sizeof(x))
#define MAX 100001

using namespace std;

long long n, aux, a[MAX+1], dp[MAX+1];

int main(){
	cin >> n;
	mset(a, 0);
	mset(dp, 0);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> aux;
		a[aux]++;
	}
	dp[0] = 0;
	dp[1] = a[1];
	
	for(int i = 2 ; i < MAX+1 ; ++i){
		dp[i] = max(dp[i-1], dp[i-2] + a[i]*i);
	}
	
	cout << dp[MAX] << endl;
	
	return 0;
}
