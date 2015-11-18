#include<bits/stdc++.h>
#define MAX 2501

using namespace std;

int n, m;
int mat[51][51];
int visited[51][51];


int dx[] = {-1, 0, 0, 1};
int dy[] = { 0, 1,-1, 0};

struct par{
	char c;
	int v;
	par(){}
	par(int _c, int _v){c = _c; v = _v;}
}p[MAX];


bool cmp(par a, par b){
	if(a.v == b.v)return a.c < b.c;
	return a.v > b.v;
}

bool isValid(int i, int j, int c){
	if( i < 0 || i >= n)return false;
	if( j < 0 || j >= m)return false;
	if( mat[i][j] != c)return false;
	if(visited[i][j] == 1)return false;
	
	return true;
}

int dfs(int x, int y, int c){
	int acu = 1, X, Y;
	visited[x][y] = 1;
	for(int i = 0 ; i < 4 ; ++i){
		X = x + dx[i];
		Y = y + dy[i];
		if(isValid(X, Y, c)){
			acu += dfs(X, Y, c);
		}
	}
	return acu;
}

int main(){
	char aux;
	int tc = 1;
	//freopen("10946.in", "r", stdin);
	//freopen("10946.out", "w", stdout);
	while(cin >> n >> m){
		if(n == 0 && m == 0)break;
		memset(visited, 0, sizeof(visited));
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < m ; ++j){
				cin >> aux;
				if(aux == '.'){
					visited[i][j] = 1;
					continue;
				}
				visited[i][j] = 0;
				mat[i][j] = aux - 'A';
			}
		}
		int cont = 0;
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < m ; ++j){
				if(mat[i][j] == -1)continue;
				if(visited[i][j] == 0){
					p[cont++] = par(mat[i][j] + 'A', dfs(i, j, mat[i][j]));
				}
			}
		}
		
		sort(p, p + cont , cmp);
		
		cout << "Problem "<< tc++ << ":" << endl;
		for(int i = 0 ; i < cont ; ++i){
			cout << p[i].c << " " << p[i].v << endl;
		}
	}
	
	return 0;
}
