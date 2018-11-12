#include<bits/stdc++.h>

#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;

long long lcm(long long x, long long y) {
	long long gcd = __gcd(x, y);
	
	return (x / gcd)*y;
}


int main(){
	long long t, n;
	
	cin >> t;
	
	for(long long i = 0 ; i < t ; ++i){
		cin >> n;
		long long lc = lcm(n+1, 4*n);
		
		cout << lc / (n+1) + 1 << endl;
	}
	
	return 0;
}

