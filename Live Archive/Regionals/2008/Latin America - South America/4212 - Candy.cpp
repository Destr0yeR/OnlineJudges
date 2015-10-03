#include<bits/stdc++.h>
#define MAX 100002

using namespace std;

int mat[MAX], res[MAX], aux[MAX], m, n;

int solve(int x[], int t){
	aux[0] = 0;
	aux[1] = x[1];
	
	for(int i = 2 ; i <= t; ++i){
		aux[i] = max(aux[i-1], x[i]+aux[i-2]);
	}
	return aux[t];
}

int main(){
	
	while(cin >> m >> n){
		if(m == 0 && n == 0)break;
		for(int i = 1 ; i <= m ; ++i){
			for(int j = 1; j <= n ; ++j){
				cin >> mat[j];
			}			
			res[i] = solve(mat, n);
		}
		cout << solve(res, m) << endl;
	}
	
	return 0;
}
