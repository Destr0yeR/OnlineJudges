#include<bits/stdc++.h>

#define MAX 100005

using namespace std;

int a[MAX], ans[MAX];

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i)ans[i] = 2;
	
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	
	for(int i = 2 ; i < n ; ++i){
		if(a[i] == a[i-1] + a[i-2]){
			ans[i] = ans[i-1] + 1;
		}
	}
	
	int res = 0;
	
	for(int i = 0 ; i < n ; ++i){
		res = max(res, ans[i]);
	}
	
	if(n < 2)res = n;
	
	cout << res << endl;
	
	return 0;
}
