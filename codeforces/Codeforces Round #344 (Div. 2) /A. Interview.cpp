#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int t, a, b, s;
	
	cin >> t;
	for(int i = 1 ; i < n; ++i){
		cin >> a;
		t = t|a;
	}
	cin >> s;
	for(int i = 1 ; i < n; ++i){
		cin >> b;
		s = s|b;
	}
	
	cout << t + s<< endl;
	
	return 0;
}
