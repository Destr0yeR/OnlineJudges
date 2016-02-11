#include<bits/stdc++.h>

using namespace std;

int mat[101][5];
char ans[101];

int main(){
	int T, q, m;
	scanf("%d", &T);
	char c, r;
	
	while(T--){
		cin >> q >> m;
		for(int i = 0 ; i < 101 ; i++)for(int j = 0 ; j < 4 ; ++j)mat[i][j] = 1;
		
		for(int i = 0 ; i < 101 ; ++i)ans[i] = '?';
		
		for(int i = 0 ; i < m ; ++i){
			for(int j = 0 ; j < q ; ++j){
				cin >> c >> r;
				if(r == 'T'){
					ans[j] = c;
				}
				else {
					
					mat[j][c-'A'] = 0;
				}
			}
		}
		int cont, idx;
		for(int i = 0 ; i < q ; ++i){
			cont = 0;
			if(ans[i] != '?')continue;
			for(int j = 0 ; j < 4 ; ++j){
				if(mat[i][j] == 1){
					idx = j;
					cont++;
				}
			}
			
			if(cont == 1){
				ans[i] = idx + 'A';
			}
			else{
				ans[i] = '?';
			}
		}
		
		for(int i = 0 ; i < q ; ++i){
			if(i)cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	
	return 0;
}
