#include<bits/stdc++.h>
#define MAX 42

using namespace std;

typedef long long ll;

ll C[MAX];

map<ll, ll> m;

ll catalan(int n){
	if(C[n] != 0)return C[n];
	ll aux = (catalan(n-1)*(4*n-2))/(n+1);
	
	m[aux] = n;
	
	return C[n] = aux;
}

int main(){
	memset(C, 0, sizeof(C));
	C[0] = 1;
	C[1] = 1;
	m[1] = 1;
	
	catalan(23);
	
	ll n;
	
	while(cin >> n){
		if(m.count(n))cout << m[n] << endl;
	}
}
