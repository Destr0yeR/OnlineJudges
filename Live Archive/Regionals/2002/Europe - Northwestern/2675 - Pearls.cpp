#include<bits/stdc++.h>
#define MAX 1002

using namespace std;

int main(){
	
	int T, c, a[MAX], p[MAX], dp[MAX], aux;
	
	long long sum[MAX];
	
	cin >> T;
	
	while(T--){
		cin >> c;
		sum[0] = 0;
		for(int i = 1 ; i <= c ; ++i){
			cin>>a[i]>>p[i];
			sum[i] = sum[i-1] + a[i];
			dp[i]=(1<<29);
		}
		
		dp[0] = 0;
		for(int i = 1 ; i <= c ; ++i){
			for(int j = 0 ; j < i ; ++j){
				aux = dp[j] + (sum[i]-sum[j]+10)*p[i];
				if(dp[i] > aux){
					dp[i] = aux;
				}
			}
		}
		
		
		cout << dp[c] << endl;
	}
	
	return 0;
}
