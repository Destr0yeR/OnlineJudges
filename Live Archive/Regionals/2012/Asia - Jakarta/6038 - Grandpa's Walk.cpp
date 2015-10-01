#include<bits/stdc++.h>
#define MAX 51
#define mset(x, y) memset(x, y, sizeof(x))

using namespace std;

int mat[MAX][MAX], val[MAX][MAX], n, m;
bool vis[MAX][MAX];

int dx[] = {-1, 0, 1, 0};
int dy[] = { 0,-1, 0, 1};


bool isValid(int x, int y){
	if(x < 0)return false;
	if(y < 0)return false;
	if(x >= n)return false;
	if(y >= m)return false;
	return true;
}

int dfs_visit(int x, int y){
	if(val[x][y]!=-1)return val[x][y];
	int sum = 0, X, Y;
	
	for(int i = 0 ; i < 4 ; ++i){
		X = x + dx[i];
		Y = y + dy[i];
		if(isValid(X, Y)){
			if(mat[X][Y] < mat[x][y]){
				vis[X][Y] = true;
				sum+=dfs_visit(X, Y);
			}
		}
	}
	if(sum == 0){
		sum = 1;
	}
	return val[x][y] = sum;
}

int dfs(){
	int sum = 0;
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0; j < m ; ++j){
			dfs_visit(i, j);
		}
	}
	
	for(int i = 0 ; i < n ; ++i){
		for(int j = 0 ; j < m ; ++j){
			if(!vis[i][j]){
				sum+=val[i][j];
			}
		}
	}
	
	return sum;
}

int main(){
	
	int T;
	
	cin >> T;
	
	for(int tc = 1; tc <= T ; ++tc){
		cin >> n >> m;
		mset(val, -1);
		mset(vis, false);
		
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < m ; ++j){
				cin >> mat[i][j];
			}
		}
		
		cout << "Case #" << tc << ": " << dfs() << endl;
	}
	
	return 0;
}
