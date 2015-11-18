#include<bits/stdc++.h>
#define Node pair<int, int>
#define MAX 101
#define inf (1<<30)

using namespace std;

int V;
vector<Node> ady[MAX];
int energy[MAX];
int dist[MAX];
int previous[MAX];
int visited[MAX];
vector<int> c;
int e[MAX];

bool relaxation(int from, int to, int w){
	int aux = dist[from] + w;
	if(aux <= 0)return false;
	if(dist[to] < aux){
		dist[to] = aux;
		previous[to] = from;
		return true;
	}
	return false;
}



void dfs(int from){
	if(visited[from] == 1)return;
	visited[from] = 1;
	int sz = ady[from].size();
	for(int i = 0 ; i < sz ; ++i){
		dfs(ady[from][i].first);
	}
}

void init(){
	int sz;
	for(int i = 1 ; i <= V ; ++i){
		sz = ady[i].size();
		for(int j = 0 ; j < sz ; ++j){
			ady[i][j].second = energy[ady[i][j].first];
		}
		dist[i] = -inf;
	}
	memset(visited, 0, sizeof(visited));
	memset(e, 0, sizeof(e));
}

bool bellman(int origen){
	int from, to, w, sz;
	dist[origen] = 100;
	bool cycle = false;
	
	for(int i = 1 ; i <= V-1 ; ++i){
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
			if(relaxation(from, to, w)){
				if(e[from] == 0){
					e[from] = 1;
					c.push_back(from);
				}
				if(e[to] == 0){
					e[to] = 1;
					c.push_back(from);
				}
				cycle =  true;
			}
		}
	}
	return cycle;
}

int main(){
	int E, aux, sz;
	while(cin >> V){
		if(V == -1)break;
		for(int i = 1 ; i <= V ; ++i){
			ady[i].clear();
		}
		c.clear();
		for(int i = 1 ; i <= V ; ++i){
			cin >> energy[i];
			cin >> E;
			while(E--){
				cin >> aux;
				ady[i].push_back(Node(aux, 0));
			}
		}
		init();
		bool cycle = bellman(1);
		if(cycle){
			sz = c.size();
			for(int i = 0 ; i < sz ; ++i){
				dfs(c[i]);
			}
		}
		if(V == 1) cout << "winnable" << endl;
		else if(dist[V] > 0){
			cout << "winnable" << endl;
		}
		else if(cycle && visited[V])cout << "winnable" << endl;
		else cout << "hopeless" << endl;
	}
	
	
	return 0;
}
