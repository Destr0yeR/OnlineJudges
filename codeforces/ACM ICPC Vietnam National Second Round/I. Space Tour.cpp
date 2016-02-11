#include<bits/stdc++.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define GR 0
#define GL 1

using namespace std;

char mat[1002][1002];
int D[1002][1002][4][2];

int dx[] = { 0, 0,-1, 1};
int dy[] = {-1, 1, 0, 0};

int m, n;

int dp(int y, int x, int dir, int gir){
	if(mat[y][x] == '0'){
		return 0;
	}
	if(D[y][x][dir][gir] != -1)return D[y][x][dir][gir];
	
	int ans = 1, X, Y, ndir, ngir;
	X = x;
	Y = y;
	switch(dir){
		case UP:
			{
				switch(gir){
					case GR:
						{
							X = x+1;
							ndir = RIGHT;
							ngir = GL;
						}break;
					case GL:
						{
							X = x-1;
							ndir = LEFT;
							ngir = GR;
						}break;
				}
			}break;
		case DOWN:
			{
				switch(gir){
					case GR:
						{
							X = x-1;
							ndir = LEFT;
							ngir = GL;
						}break;
					case GL:
						{
							X = x+1;
							ndir = RIGHT;
							ngir = GR;
						}break;
				}
			}break;
		case LEFT:
			{
				switch(gir){
					case GR:
						{
							Y = y-1;
							ndir = UP;
							ngir = GL;
						}break;
					case GL:
						{
							Y = y+1;
							ndir = DOWN;
							ngir = GR;
						}break;
				}
			}break;
		case RIGHT:
			{
				switch(gir){
					case GR:
						{
							Y = y+1;
							ndir = DOWN;
							ngir = GL;
						}break;
					case GL:
						{
							Y = y-1;
							ndir = UP;
							ngir = GR;
						}break;
				}
			}break;
	}
	
	ans = 1 + dp(Y, X, ndir, ngir);
	
	return D[y][x][dir][gir] = ans;
}

int solve(int y, int x){
	int ans = 0, X, Y;
	
	for(int i = 0 ; i < 4 ; ++i){
		X = x + dx[i];
		Y = y + dy[i];
		
		ans += dp(Y, X, i, GR);
	}
	
	return ans + 1;
}

int main(){
	
	int T, ans;
	scanf("%d", &T);
	
	while(T--){
		memset(mat, '0', sizeof(mat));
		memset(D, -1, sizeof(D));
		scanf("%d %d", &m, &n);
		
		for(int i = 1 ; i <= m ; ++i){
			for(int j =  1 ; j <= n ; ++j){
				cin >> mat[i][j];
			}
		}
		
		ans = 0;
		for(int i = 1 ; i <= m ; ++i){
			for(int j = 1 ; j <= n; ++j){
				if(mat[i][j] == '0')continue;
				ans = max(ans, solve(i,j));
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
