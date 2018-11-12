#include<bits/stdc++.h>

using namespace std;

int dp[90][11];
int memo[90][11];

int f(int d, int s){
	if(d == 0 && s == 0)return 1;
	if(d < 0 || s < 0)return 0;
	
	if(memo[s][d]) return dp[s][d];
	
	memo[s][d] = 1;
	int ans = 0;
	
	for (int i = 0; i < 10; i++)
	{
		ans += f(d-1, s - i);
	}
	
	//cout << d << ", " << s << " => " << ans << endl;
	
	return dp[s][d] = ans;
}

int main() {
	
	int s;
	
	while(cin >> s){
		memset(memo, 0, sizeof(memo));
		int tmp = (s == 1 ? 1 : 0);
		cout << f(9, s) + tmp << "\n";
	}
	
	return 0;
}
