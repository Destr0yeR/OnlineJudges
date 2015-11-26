#include<bits/stdc++.h>

#define MAX 100

using namespace std;

int a[MAX];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	
	int n, k;
	
	cin >> n >> k;
	
	for(int i = 0 ; i < n ; ++i)cin >> a[i];
	
	sort(a, a + n, cmp);
	
	int cont = 0;
	
	for(int q = 1 ; q <= n ; ++q){
		if(cont == k)break;
		for(int i = q ; i <= n ; ++i){
			cout << q;
			for(int j = 0 ; j < q-1 ; ++j)cout << " " << a[j];
			cout << " " << a[i-1];
			cout << endl;
			cont++;
			if(k == cont)break;
		}
		
	}
	
	return 0;
}
