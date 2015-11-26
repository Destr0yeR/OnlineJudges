#include<bits/stdc++.h>

#define MAX 101

using namespace std;

int a[MAX];

int main(){
	
	int n, m, tot = 0;
	
	cin >> n >> m;
	
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	
	sort(a, a+n);
	
	for(int i = 0 ; i < m ; ++i){
		if(a[i] >= 0)break;
		tot -= a[i];
	}
	
	cout << tot << endl;
	
	return 0;
}
