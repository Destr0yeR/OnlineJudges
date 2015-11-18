#include<bits/stdc++.h>
#define MAX 26

using namespace std;

int V, E;

int visited[MAX];
vector<int> graph[MAX], transpose[MAX];
map<string, int> m;
string rm[MAX];
stack<int> S;

void reset(){
	for(int i = 0 ; i <= V ; ++i)visited[i] = 0;
}

void init(){
	reset();
	m.clear();
	for(int i = 0 ; i <= V ; ++i){
		graph[i].clear();
		transpose[i].clear();
	}
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

void dfs(int from){
	visited[from] = 1;
	int to, sz = graph[from].size();
	
	for(int i = 0 ; i < sz ; ++i){
		to = graph[from][i];
		if(visited[to] == 0)dfs(to);
	}
	S.push(from);
}

void dfs2(int from, bool space){
	visited[from] = 1;
	int to, sz = transpose[from].size();
	if(space)cout << ", ";
	cout << rm[from];
	for(int i = 0 ; i < sz ; ++i){
		to = transpose[from][i];
		if(visited[to] == 0)dfs2(to, true);
	}
}

void scc(){
	for(int i = 1 ; i <= V ; ++i)if(visited[i] == 0)dfs(i);
	reset();
	build_transpose();
	int current;
	
	while(!S.empty()){
		current = S.top();
		S.pop();
		
		if(visited[current] == 1)continue;
		
		dfs2(current, false);
		cout << endl;
	}
}

int main(){
	string a, b;
	int tc = 0;
	while(cin >> V >> E){
		if(V == 0 && E == 0)break;
		init();
		int cont = 1;
		for(int i = 0 ; i < E ; ++i){
			cin >> a >> b;
			if(!m.count(a)){
				rm[cont] = a;
				m[a] = cont++;
			}
			if(!m.count(b)){
				rm[cont] = b;
				m[b] = cont++;
			}
			graph[m[a]].push_back(m[b]);
		}
		if(tc)cout << endl;
		cout << "Calling circles for data set " << ++tc << ":" << endl;
		scc();
	}
	
	return 0;
}
