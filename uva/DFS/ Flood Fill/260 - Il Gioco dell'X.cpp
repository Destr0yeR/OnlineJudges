#include <bits/stdc++.h>


char tableo[201][201];
int visitado[201][201];
int usado[201];

void check(int x, int y, int n){
	if(x > 0 && x < n && y > 0 && y < n){

	}
	else{
		return;
	}
}

void dfs(int x, int y, int n){
	visitado[x][y] = 1;
	int i, j;
	i = x-1, j = y-1;
	check(i, j, n);
	i = x-1, j = y;
	check(i, j, n);
	i = x  , j = y-1;
	check(i, j, n);
	i = x  , j = y+1;
	check(i, j, n);
	i = x+1, j = y;
	check(i, j, n);
	i = x+1, j = y+1;
	check(i, j, n);
}

char proccess(int n){
	for(int i = 0 ; i < x ; ++i){
		for(int j = 0 ; j < x ; ++j){
			if(!visitado[i,j]) dfs(i,j,n);
		}
	}
}

void init(int n){
	memset(visitado, 0, sizeof(visitado));
	for(int i = 0 ; i < n; ++i){
		for(int j = 0 ; j < n ; ++j){
			scanf("%c", &tablero[i][j]);
		}
	}
}

int main(){

	int n;
	char winner;

	for(int tc = 1 ;  ; ++tc){
		scanf("%d", &n)
		if(n == 0) return 0;
		init(n);
		winner = proccess(n);
		printf("%d %c\n", tc, c);
	}

	return 0;
}