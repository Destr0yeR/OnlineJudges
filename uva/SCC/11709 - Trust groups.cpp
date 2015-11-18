#include<bits/stdc++.h>
#define MAX 1001

using namespace std;

int V, E;
vector<int> graph[MAX], transpose[MAX];
int parent[MAX], visited[MAX];
string rm[MAX];
stack<int> S;
map<string, int> m;

void init(){
	m.clear();
	
	for(int i = 0 ; i <= V ; ++i){
		graph[i].clear();
		transpose[i].clear();
		parent[i] = -1;
		visited[i] = 0;
	}
}

void dfs(int from){
	visited[from] = 1;
	int to, sz = graph[from].size();
	
	for(int i = 0  ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0)dfs(to);
	}
	S.push(from);
}

void build_transpose(){
	int from, to, sz;
	for(from = 1 ; from <= V ; ++from){
		sz = graph[from].size();
		for(int i = 0 ; i < sz ; ++i){
			to = graph[from][i];
			transpose[to].push_back(from);
		}
	}
}

void dfs2(int from){
	visited[from] = 1;
	int to, sz = transpose[from].size();
	
	for(int i = 0 ; i < sz ; ++i){
		to = transpose[from][i];
		if(visited[to] == 0)dfs2(to);
	}
}

void scc(){
	for(int i = 1 ; i <= V ; ++i)if(visited[i] == 0)dfs(i);
	build_transpose();
	
	int cont = 0, current;
	
	for(int i = 0 ; i <= V ; ++i)visited[i] = 0;
	
	while(!S.empty()){
		current = S.top();
		S.pop();
		if(visited[current] == 1)continue;
		dfs2(current);
		cont++;
	}
	
	cout << cont << endl;
}

int main(){
	int from;
	string s, a, b;
	
	while(cin >> V >> E){
		if(V == 0 && E == 0)break;
		init();
		cin.ignore();
		for(from = 1 ; from <= V ; ++from){
			getline(cin, s);
			m[s] = from;
			rm[from] = s;
		}
		
		for(int i = 0 ; i < E ; ++i){
			getline(cin, a);
			getline(cin, b);
			graph[m[a]].push_back(m[b]);
		}
		
		scc();
		
	}
	
	return 0;
}
