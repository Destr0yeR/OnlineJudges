#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, a, b, acu = 0;
	
	cin >> n >> a >> b;
	
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	if(n == (a+b+1) && b == 0){
		cout << -1 << endl;
		return 0;
	}
	
	cout << 1;
	
	if(b == 0){
		cout << " 1";
		n--;
	}
	
	acu = 1;
	
	for(int i = 0 ; i < b ; ++i){
		acu*=2;
		cout << " " << acu;
	}
	
	for(int i = 0 ; i < a ; ++i){
		acu++;
		cout << " " << acu;
	}
	
	for(int i = 0 ; i < (n - (a+b) - 1) ; ++i){
		cout << " " << acu;
	}
	
	cout << endl;
	
	return 0;
}
