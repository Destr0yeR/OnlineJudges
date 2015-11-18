#include<bits/stdc++.h>
#define MAX 2001
#define MAX_EDGES 5000005

using namespace std;

int V, E;

int visited[MAX];
int padre[MAX];
int used[MAX];
vector<int> graph[MAX], transpose[MAX];
stack<int> S;

struct Edge{
	int from, to, direction;
	Edge(){}
	Edge(int _from, int _to, int _direction){from = _from; to = _to; direction = _direction;}
}edge[MAX_EDGES];

int Find(int x){
	if(x == padre[x])return x;
	return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
	padre[Find(x)] = Find(y);
}


void reset(){
	for(int i = 0 ; i <= V ; ++i)visited[i] = 0;
}

void init(){
	reset();
	for(int i = 0 ; i <= V ; ++i){
		padre[i] = i;
		graph[i].clear();
		transpose[i].clear();
		used[i] = 0;
	}
}

void dfs(int from, bool guard){
	int pFrom = Find(from);
	
	int to, sz = graph[pFrom].size();
	visited[pFrom] = 1;
	for(int i = 0 ; i < sz ; ++i){
		to = Find(graph[pFrom][i]);
		if(visited[to] == 0)dfs(to, guard);
	}
	
	if(!guard)S.push(Find(from));
}

void build_transpose(){
	int from, to, sz, pFrom;
	
	for(from = 1 ; from <= V ; ++from){
		pFrom = Find(from);
		if(used[pFrom] == 0){
			sz = graph[pFrom].size();
			for(int i = 0 ; i < sz ; ++i){
				to = Find(graph[pFrom][i]);
				transpose[to].push_back(pFrom);
			}
		}
	}
}

void dfs2(int from){
	int pFrom = Find(from);
	int to, sz = transpose[pFrom].size();
	visited[pFrom] = 1;
	for(int i = 0 ; i < sz ; ++i){
		to = Find(transpose[pFrom][i]);
		if(visited[to] == 0)dfs2(to);
	}
}

void scc(){
	for(int i = 1 ; i <= V ; ++i)if(visited[Find(i)] == 0)dfs(Find(i), false);
	build_transpose();
	reset();
	
	int current, comp = 0;
	while(!S.empty()){
		current = Find(S.top());
		S.pop();
		if(visited[current] == 1)continue;
		dfs2(current);
		comp++;
	}
	
	if(comp == 1)cout << 1 << endl;
	else cout << 0 << endl;
}

int main(){
	int from, to, direction;
	while(cin >> V >> E){
		if(V == 0 && E == 0)break;
		init();

		for(int i = 0 ; i <  E ; ++i){
			cin >> from >> to >> direction;
			edge[i] = Edge(from, to, direction);
			if(direction == 2)Union(from, to);
		}
		
		for(int i = 0 ; i < E ; ++i){
			if(edge[i].direction == 1){
				graph[Find(edge[i].from)].push_back(Find(edge[i].to));
			}
		}
		scc();
	}
	
	return 0;
}
