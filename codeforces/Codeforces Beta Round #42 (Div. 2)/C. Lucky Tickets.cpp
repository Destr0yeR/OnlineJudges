#include<bits/stdc++.h>

using namespace std;

int a[3];

int main(){
	
	int n, x;
	memset(a, 0, sizeof(a));
	
	cin >> n;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> x;
		a[x%3]++;
	}
	
	cout << (a[0]/2) + min(a[1],a[2]) << endl;
	
	return 0;
}
