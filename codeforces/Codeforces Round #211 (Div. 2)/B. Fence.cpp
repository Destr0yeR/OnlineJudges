#include<bits/stdc++.h>
#define mset(x, y) memset(x, y, sizeof(x))
#define MIN 1<<29
#define MAX 200005

using namespace std;

long long a[MAX];

int main(){
	int n, k, aux, min = MIN, index;
	mset(a, 0);
	cin >> n >> k;
	for(int i = 1; i <= n ; ++i){
		cin >> aux;
		a[i] = aux + a[i-1];
	}
	
	for(int i = 1 ; i <= n-k+1 ; ++i){
		aux = a[i+k-1] - a[i-1];
		if(min > aux){
			min = aux;
			index = i;
		}
	}
	
	cout << index << endl;
	
	return 0;
}
