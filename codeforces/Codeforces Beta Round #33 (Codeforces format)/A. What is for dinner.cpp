#include<bits/stdc++.h>

#define MAX 1001
#define INF (1<<30)

using namespace std;

int a[MAX];

int main(){
	int n, m, k, r, c, acu;
	
	cin >> n >> m >> k;
	
	for(int i = 0 ; i <= m ; ++i)a[i] = INF;
	
	for(int i = 0 ; i < n ; ++i){
		cin >> r >> c;
		a[r] = min(c, a[r]);
	}
	acu = 0;
	for(int i = 1 ; i <= m ; ++i)acu+=a[i];
	
	cout << min(k, acu) << endl;
	
	return 0;
}
