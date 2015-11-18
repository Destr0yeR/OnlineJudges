#include<bits/stdc++.h>
#define MAX 1001

using namespace std;

int V, E;

int mat[MAX][MAX];
int visited[MAX];
int parent[MAX];

void init(){
	memset(mat, 0, sizeof(mat));
	memset(visited, 0, sizeof(visited));
	for(int i = 0 ; i <= V ; ++i){
		parent[i] = -1;
	}
}

void dfs(int from){
	visited[from] = 1;
	for(int to = 1 ; to <= V ; ++to){
		if(mat[from][to]){
			if(visited[to] == 0){
				parent[to] = from;
				dfs(to);
			}
			else if(visited[to] == 1 && to != parent[from]){
				mat[to][from] = 0;
				int prev = from;
				while(prev != to){
					mat[prev][parent[prev]] = 0;
					prev = parent[prev];
				}
			}
		}
	}
}

int main(){
	int from, to, tc = 1;
	while(cin >> V >> E){
		if(V == 0 && E == 0)break;
		init();
		for(int i = 0 ; i < E ; ++i){
			cin >> from >> to;
			mat[from][to] = 1;
			mat[to][from] = 1;
		}
		
		for(int i = 1 ; i <= V ; ++i){
			if(visited[i] == 0)dfs(i);
		}
		
		cout << tc++ << endl << endl;
		
		for(from = 1 ; from <= V ; ++from){
			for(to = 0 ; to <= V ; ++to){
				if(mat[from][to] == 1){
					cout << from << " " << to << endl;
				}
			}
		}
		cout << "#" << endl;
	}
	
	return 0;
}
