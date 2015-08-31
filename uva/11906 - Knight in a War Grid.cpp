#include<bits/stdc++.h>

#define MAX 101
#define mset(x,y) memset(x, y, sizeof(x))

using namespace std;

int T, r, c, m, n;

struct Point{
	int x, y;
};

int mat[MAX][MAX];

void bfs(){
	Point aux, u;
	queue<Point> q;
	aux.x = 0, aux.y = 0;
	q.push(aux);
	
	while(!q.isEmpty()){
		u = q.front();
		q.pop();
	}
}

int main(){
	cin >> T;
	
	while(T--){
		cin >> r >> c >> m >> n;
		cin >> w;
		for(int i = 0 ; i < w ; ++i){
			cin >> x >> y;
			mat[x][y] = -1;
		}
	}
	
	return 0;
}
