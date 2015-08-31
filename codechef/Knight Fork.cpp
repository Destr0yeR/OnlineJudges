#include<bits/stdc++.h>

#define MAX 1001
using namespace std;

int T, n, m, x, y, ans, X, Y;

int mat[MAX][MAX];
int c[MAX][MAX];
int u[MAX][MAX];
int row[MAX];
int col[MAX];
int dia1[MAX];
int dia2[MAX];

int dx[] = { 1, 1,-1,-1, 2, 2,-2,-2};
int dy[] = { 2,-2, 2,-2, 1,-1, 1,-1};

bool isValid(int i, int j){
	if(row[i])return false;
	if(col[j])return false;
	if(i < 1 || i > n)return false;
	if(j < 1 || j > n)return false;
	if(mat[i][j] == 1)return false;
	return true;
}

int main(){
	
	cin >> T;
	
	while(T--){
		cin >> n >> m;
		ans = 0;
		memset(mat, 0 , sizeof(mat));
		memset(c, 0, sizeof(c));
		memset(u, 0, sizeof(u));
		for(int i = 0 ; i < m ; ++i){
			cin >> x >> y;
			mat[x][y] = 1;
		}
		
		for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= n ; ++j){
				x = i;
				y = j;
				if(mat[x][y] == 0)continue;
				for(int k = 0 ; k < 8 ; ++k){
					X = x + dx[k];
					Y = y + dy[k];
					if(isValid(X,Y)){
						if(u[X][Y] == 0){
							u[X][Y] = 1;
						}
						else{
							if(c[X][Y] == 0){
								c[X][Y] = 1;
								ans++;
							}
						}
					}
				}
			}
		}
			
			
		cout << ans << endl;
	}
	
	return 0;
}
