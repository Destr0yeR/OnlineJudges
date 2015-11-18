#include<bits/stdc++.h>
#define MAX 101

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

int mat[MAX][MAX], n;
int visited[MAX][MAX];
int used[MAX];

bool isValid(int i, int j, int c){
	if( i < 1 || i > n )return false;
	if( j < 1 || j > n )return false;
	if( mat[i][j] != c )return false;
	if( visited[i][j] == 1)return false;
	
	return true;
}

void dfs_visit(int x, int y, int c){
	//cout << "visit: " << x << " " << y << " " << c << endl;
	int X, Y;
	visited[x][y] = 1;
	for(int i = 0 ; i < 4 ; ++i){
		X = x + dx[i];
		Y = y + dy[i];
		if(isValid(X, Y, c))dfs_visit(X, Y, c);
	}
}

void init(){
	memset(used, 0, sizeof(used));
	memset(visited, 0, sizeof(visited));
	memset(mat, 0, sizeof(mat));
}

void dfs(){
	bool posible = true;
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(visited[i][j] == 0){
				if(used[mat[i][j]] == 0){
					used[mat[i][j]] = 1;
					dfs_visit(i, j, mat[i][j]);
				}
				else{
					posible = false;
					break;
				}
			}
		}
		if(posible == false)break;
	}
	
	if(posible) cout << "good" << endl;
	else cout << "wrong" << endl;
		
}

int main(){
	string s;
	int a, b, cont;
	while(getline(cin, s)){
		stringstream in(s);
		in >> n;
		if(n == 0)break;
		init();
		cont = 1;
		for(int i = 1 ; i < n ; ++i){
			getline(cin, s);
			stringstream ss(s);
			
			while(ss >> a >> b){
				mat[a][b] = cont;
			}
			cont++;
		}
		
		/*for(int i = 1 ; i <= n ; ++i){
			for(int j = 1 ; j <= n ; ++j){
				cout <<mat[i][j] << " ";
			}
			cout << endl;
		}*/
		
		dfs();
	}
	
	return 0;
}

