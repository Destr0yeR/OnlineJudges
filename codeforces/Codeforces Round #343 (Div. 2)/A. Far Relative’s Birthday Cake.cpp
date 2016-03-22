#include<bits/stdc++.h>

#define MAX 101

using namespace std;

int r[MAX], c[MAX];

int main(){
	
	int n;
	char ch;
	
	cin >> n;
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			cin >> ch;
			if(ch == 'C'){
				r[i]++;
				c[j]++;
			}
		}
	}
	
	long long ans = 0LL;
	
	for(int i = 1 ; i <= n ; ++i){
		ans += (c[i]*(c[i]-1)/2) + (r[i]*(r[i]-1)/2);
	}
	
	cout << ans << endl;
	
	return 0;
}
