#include<bits/stdc++.h>

using namespace std;

char mat[5][5];

int main(){
		
	int n;
	
	while(cin >> n){
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < n ; ++j){
				cin << mat[i][j];
			}
		}
	}
	
	
	return 0;
}
