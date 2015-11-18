#include<bits/stdc++.h>
#define MAX 21

using namespace std;

typedef long long ll;

ll C[MAX];

ll catalan(int n){
	if(C[n] != -1)return C[n];
	
	return C[n] = (catalan(n-1)*(4*n-2))/(n+1);
}

int main(){
	int tc = 0, n;
	memset(C, -1, sizeof(C));
	C[0] = 1;
	while(cin >> n){
		if(tc++)cout << '\n';
		
		cout << catalan(n) << '\n';
	}
}
