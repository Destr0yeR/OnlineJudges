#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	
	ll n, a, b, c;
		
	cin >> n;
	
	if(n>=3){
		if(n%2 == 0){
			a = n;
			b = n-1;
			c = n-3;
			if(n%3 == 0){
				a = n-2;
			}
		}
		else {			
			a = n;
			b = n-1;
			c = n-2;
		}
		
		cout << a*b*c << endl;
	}
	else{
		if(n == 1)cout << 1 << endl;
		else if(n == 2)cout << 2 << endl;
	}
	
	return 0;
}
