#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll f[50];
map<ll, ll> m;

void fibo(){
	f[0] = 0, f[1] = 1;
	m[0] = 0; m[1] = 1;
	for(int i = 2 ; i < 50 ; ++i){
		f[i] = f[i-1] + f[i-2];
		m[f[i]] = i;
	}
}

int main(){
	fibo();
	
	ll n;
	
	cin >> n;
	
	if(n == 0){
		printf("0 0 0\n");
	}
	else if(n == 1){
		printf("0 0 1\n");
	}
	else if(n == 2){
		printf("0 1 1\n");
	}
	else if(n == 3){
		printf("1 1 1\n");
	}
	else {
		int i = m[n];
		
		cout << f[i-4] << " " << f[i-3] << " " << f[i-1] << "\n";
	}
	
	return 0;
}
