#include<bits/stdc++.h>

#define MAX 300005
#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;

int n, k;

int a[MAX];

int main(){
	cin >> n >> k;
	
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	sort(a, a+n);
	
	int pares;
	
	pares = (n+k-1)/k;
	
	long long suma = 0;
	for(int i = 0 ; i < n ; i+=pares){
		for(int j = 0 ; j < pares-1 && n-1 > i + j; ++j){
			suma += abs(a[i + j] - a[i + j +1]);
		}
	}
	
	cout << suma << endl;
	
	return 0;
}
