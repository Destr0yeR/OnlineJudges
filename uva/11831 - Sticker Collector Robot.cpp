#include<bits/stdc++.h>

#define mset(x,y) memset(x, y, sizeof(x))
#define MAX 101

#define north 1
#define west 2
#define east 3
#define south 4

using namespace std;

int n, m, s, x, y, X, Y;
char mat[MAX][MAX];
int v[MAX][MAX];
int orientation;
string ins;
int items;

bool isValid(int i, int j){
	if(i < 0 || i >= n)return false;
	if(j < 0 || j >= m)return false;
	if(mat[i][j] == '#')return false;
	return true;
}

void move(char c){
	switch(c){
		case 'D':
			switch(orientation){
				case north:
					orientation = east;break;
				case east:
					orientation = south;break;
				case south:
					orientation = west;break;
				case west:
					orientation = north;break;
			}
			break;
		case 'E':
			switch(orientation){
				case north:
					orientation = west;break;
				case west:
					orientation = south;break;
				case south:
					orientation = east;break;
				case east:
					orientation = north;break;
			}
			break;
		case 'F':
			switch(orientation){
				case west:
					if(isValid(x, y-1)){
						y--;
						if(mat[x][y] == '*'){
							items++;
							mat[x][y] = '.';
						}
					}
					break;
				case south:
					if(isValid(x + 1, y)){
						x++;
						if(mat[x][y] == '*'){
							items++;
							mat[x][y] = '.';
						}
					}
					break;
				case east:
					if(isValid(x, y+1)){
						y++;
						if(mat[x][y] == '*'){
							items++;
							mat[x][y] = '.';
						}
					}
					break;
				case north:
					if(isValid(x-1, y)){
						x--;
						if(mat[x][y] == '*'){
							items++;
							mat[x][y] = '.';
						}
					}
					break;
			}
	}
}

void dfs(){
	for(int i = 0 ; i < s ; ++i){
		move(ins[i]);
	}
}

int main(){
	
	while(cin >> n >> m >> s){
		if(n == 0 && m == 0 && s == 0)break;
		for(int i = 0 ; i < n ; ++i){
			for(int j = 0 ; j < m ; ++j){
				cin >> mat[i][j];
				if(mat[i][j] == 'N')orientation = north, x=i, y = j;
				else if(mat[i][j] == 'S')orientation = south, x=i, y = j;
				else if(mat[i][j] == 'O')orientation = west, x=i, y = j;
				else if(mat[i][j] == 'L')orientation = east, x=i, y = j;
			}
		}
		cin >> ins;
		items = 0;
		dfs();
		cout << items << endl;
		
	}
	return 0;
}
