#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int a[100005];

int main(){
	
	int n;
	ll acu = 0, prom = 0;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; ++i){
		cin >> a[i];
		acu+=a[i];
	}
	
	prom = acu/n;
	
	if(acu == prom*n)cout << n << "\n";
	else cout << n-1 << "\n";
	
	return 0;
}
