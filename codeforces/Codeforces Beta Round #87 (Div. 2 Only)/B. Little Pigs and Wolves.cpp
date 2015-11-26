#include<bits/stdc++.h>

using namespace std;

char mat[11][11];
int n, m;

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};

bool isValid(int x, int y){
	if(x < 1 || x > n)return false;
	if(y < 1 || y > m)return false;
	
	return true;
}

int main(){
	
	
	scanf("%d %d", &n, &m);
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			cin >> mat[i][j];
		}
	}
	
	int tot = 0, I, J;
	
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(mat[i][j] == 'W'){
				for(int k = 0 ; k < 4 ; ++k){
					I = i + dx[k];
					J = j + dy[k];
					if(isValid(I, J)){
						if(mat[I][J] == 'P'){
							tot++;
							break;
						}
					}
				}
			}
		}
	}
	
	printf("%d\n", tot);
	
	return 0;
}
