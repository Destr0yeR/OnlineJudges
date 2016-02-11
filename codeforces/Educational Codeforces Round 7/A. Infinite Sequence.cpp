#include<bits/stdc++.h>

using namespace std;

int main(){
	
	long long n;
	long long ans, aux;
	
	cin >> n;
	
	ans = sqrt(2*n);
	
	aux = (ans*(ans+1)/2);
	
	while(aux >= n){
		ans--;
		aux = (ans*(ans+1)/2);
	}
	
	ans = n - aux;
	
	cout << ans << endl;
	
	return 0;
}
