#include<bits/stdc++.h>

#define MAX 20001

using namespace std;

bool cmp(int x, int y){
	return x > y;
}

int a[MAX];

int main(){
	
	int t, n, acu;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		
		for(int i = 0 ; i < n ; ++i)cin >> a[i];
		
		sort(a, a + n, cmp);
		
		acu = 0;
		for(int i = 2 ; i < n ; i+=3)acu+=a[i];
		
		cout << acu << '\n';
	}
	
	return 0;
}
