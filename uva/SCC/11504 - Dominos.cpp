#include<bits/stdc++.h>
#define MAX 100001

using namespace std;

int V, E, comp;

int parent[MAX];
int visited[MAX];
int component[MAX];
int connected[MAX];
vector<int> graph[MAX];
vector<int> transpose[MAX];
stack<int> S;

void init(){
	for(int i = 0 ; i  <= V ; ++i){
		graph[i].clear();
		transpose[i].clear();
		parent[i] = -1;
		visited[i] = 0;
		component[i] = -1;
		connected[i] = 0;
	}
	comp = 0;
}

void build_transpose(){
	int sz;
	for(int i = 1 ; i <= V ; ++i){
		sz = graph[i].size();
		for(int j = 0 ; j < sz ; ++j){
			transpose[graph[i][j]].push_back(i);
		}
	}
}

void dfs(int from){
	visited[from] = 1;
	int sz = graph[from].size(), to;
	for(int i = 0 ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0){
			parent[to] = from;
			dfs(to);
		}
	}
	S.push(from);
}

void dfs2(int from, int comp){
	visited[from] = 1;
	component[from] = comp;
	int sz = transpose[from].size(), to;

	for(int i = 0 ; i < sz ; ++i){
		to = transpose[from][i];
		if(visited[to] == 0)dfs2(to, comp);
	}
}

void dfs3(int from){
	visited[from] = 1;
	
	int sz = graph[from].size(), to;
	
	for(int i = 0 ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0)dfs3(to);		
		else{
			if(component[to] != component[from]){
				//cout << " " << from << " " << to << endl;
				connected[component[to]] = 1;
			}
		}
	}
}

void scc(){
	build_transpose();
	for(int i = 1 ; i <= V ; ++i)if(visited[i] == 0)dfs(i);
	
	for(int i = 0 ; i <= V ; ++i)visited[i] = 0;
	
	int cont = 0, current;
	
	while(!S.empty()){
		current = S.top();
		//cout << "stack: " << current << endl;
		S.pop();
		if(visited[current] == 1)continue;
		dfs2(current, comp);
		comp++;
	}
	
	for(int i = 0 ; i <= V ; ++i)visited[i] = 0;
	
	for(int i = 1 ; i <=  V ; ++i)if(visited[i] == 0)dfs3(i);
	
	for(int i = 1 ; i <=  V ; ++i){
		//cout << i << " parent: " << parent[i] << " component: " << component[i] << endl;
		if(parent[i] == -1 && connected[component[i]] == 0){
			cont++;
		}
	}
	
	cout << cont << endl;
}

int main(){

	int T, from, to;
	//freopen("11504.in", "r", stdin);
	//freopen("11504.out", "w", stdout);
	cin >> T;
	
	for(int tc = 1 ; tc <= T ; ++tc){
		cin >> V >> E;
		init();
		for(int i = 0 ; i < E ; ++i){
			cin >> from >> to;
			graph[from].push_back(to);
		}
		scc();
	}
	
	
	return 0;
}
