#include<bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	
	char a, b;
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> m;
	
	if(n > m){
		a = 'B';
		b = 'G';
	}
	else{
		a = 'G';
		b = 'B';
	}
	
	int mini = min(n,m), maxi = max(n,m);
	
	for(int i = 0 ; i < mini ; ++i){
		cout<< a << b;
	}
	
	for(int i = mini ; i < maxi ; ++i)cout << a;
	
	cout << "\n";
	
	return 0;
}
