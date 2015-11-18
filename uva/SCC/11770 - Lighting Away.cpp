#include<bits/stdc++.h>
#define MAX 10001

using namespace std;

int V, E, comp;
vector<int> graph[MAX], transpose[MAX];
int visited[MAX];
int parent[MAX];
stack<int> S;

void reset(){
	for(int i = 0 ; i <= V ; ++i)visited[i] = 0;
}

void init(){
	reset();
	comp = 0;
	for(int i = 0 ; i <= V ; ++i){
		graph[i].clear();
		transpose[i].clear();
		parent[i] = -1;
	}
}

void dfs(int from, bool guard){
	int to, sz = graph[from].size();
	visited[from] = 1;
	for(int i = 0 ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0)dfs(to, guard);
	}
	if(!guard)S.push(from);
}

void scc(){
	//build_transpose();
	for(int i = 1 ; i <= V ; ++i)if(visited[i] == 0)dfs(i, false);
	reset();
	int current;
	while(!S.empty()){
		current = S.top();
		S.pop();
		
		if(visited[current] == 1)continue;
		dfs(current, true);
		comp++;
	}
	
	cout << comp << endl;
}

int main(){
	int T, from, to;
	cin >> T;
	
	for(int tc = 1 ; tc <= T ; ++tc){
		cin >> V >> E;
		init();
		
		for(int i = 0 ; i < E ; ++i){
			cin >> from >> to;
			graph[from].push_back(to);
		}
		cout << "Case " << tc << ": ";
		scc();
	}
	
	return 0;
}
