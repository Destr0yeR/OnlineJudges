#include<bits/stdc++.h>
#define MAX 10001

using namespace std;

int visited[MAX], V, E, q;
vector<int> graph[MAX];

void dfs(int from){
	int sz = graph[from].size(), to;
	visited[from] = 1;
	for(int i = 0 ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0)dfs(to);
	}
}

void init(){
	for(int i = 0 ; i <= V ; ++i)graph[i].clear();
	memset(visited, 0, sizeof(visited));
}

int main(){
	
	int T, a, b;
	cin >> T;
	
	while(T--){
		cin >> V >> E >> q;
		init();
		
		for(int i = 0 ; i < E ; ++i){
			cin >> a >> b;
			graph[a].push_back(b);
		}
		
		for(int i = 0 ; i < q ; ++i){
			cin >> a;
			if(visited[a] == 0)dfs(a);
		}
		
		int tot = 0;
		
		for(int i = 1 ; i <= V ; ++i){
			if(visited[i] == 1)tot++;
		}
		
		cout << tot << endl;
	}
	
	return 0;
}
