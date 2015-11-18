#include<bits/stdc++.h>

#define Node pair<int, int>
#define inf (1<<30)
#define MAX 205

using namespace std;

int V, E;
int dist[MAX];
vector<Node> ady[MAX];
int cycl[MAX];
int busy[MAX];
int used[MAX];

bool relaxation(int from, int to, int w){
	int aux = dist[from] + w;
	if(dist[to] > aux){
		dist[to] = aux;
		return true;
	}
	return false;
}

void init(){
	for(int i = 0 ; i <= V ; ++i){
		dist[i] = inf;
		cycl[i] = 0;
		used[i] = 0;
	}
}

void dfs(int from){
	if(used[from] == 1)return;
	used[from] = 1;
	int sz = ady[from].size(), to;
	
	for(int i = 0 ; i < sz ; ++i){
		to = ady[from][i].first;
		dfs(to);
	}
	
}

void bellman(int origen){
	init();
	dist[origen] = 0;
	int from, to, w, sz;
	
	for(int i = 1 ; i <= V - 1 ; ++i){
		for(from = 1 ; from <= V ; ++from){
			sz = ady[from].size();
			for(int j = 0 ; j < sz ; ++j){
				to = ady[from][j].first;
				w = ady[from][j].second;
				relaxation(from, to, w);
			}
		}
	}
	
	for(from = 1 ; from <= V ; ++from){
		sz = ady[from].size();
		for(int j = 0 ; j < sz ; ++j){
			to = ady[from][j].first;
			w = ady[from][j].second;
			if(relaxation(from, to, w))cycl[from] = cycl[to] = 1;
		}
	}
}
int cub(int x){
	return x*x*x;
}

int main(){
	int tc = 1, from, to , w, q, query;
	while(cin >> V){
		for(int i = 1 ; i <= V ; ++i){
			cin >> busy[i];
		}
		
		cin >> E;
		
		for(int i = 0 ; i <= V ; ++i)ady[i].clear();
		
		for(int i = 0 ; i < E ; ++i){
			cin >> from >> to;
			ady[from].push_back(Node(to, cub(busy[to] - busy[from])));
		}
		
		
		bellman(1);
		dfs(1);
		
		cin >> q;
		cout << "Set #" << tc++ << endl;
		while(q--){
			cin >> query;
			w = dist[query];
			if(w < 3 || w == inf || cycl[query] == 1)cout << "?" << endl;
			else if(used[query])cout << w << endl;
			else cout << "?" << endl;
		}
	}
	
	
	return 0;
}

