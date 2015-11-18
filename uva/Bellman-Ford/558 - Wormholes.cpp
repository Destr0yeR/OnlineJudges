#include<bits/stdc++.h>
#define Node pair<int, int>
#define inf (1<<30)
#define MAX 100001

using namespace std;

int V, E;
int dist[MAX];

vector<Node> ady[MAX];

void init(){
	for(int i = 0 ; i <= V ; ++i){
		dist[i] = inf;
	}
}

bool relaxation(int from, int to, int w){
	int aux = dist[from] + w;
	if(dist[to] > aux){
		dist[to] = aux;
		return true;
	}
	return false;
}

void debug(){
	for(int from = 0 ; from < V ; ++from){
		cout << from << " " << dist[from] << endl;
	}
}

bool bellman(int origen){
	init();
	int sz, from, to, w;
	dist[origen] = 0;
	
	for(int i = 1 ; i <= V-1 ; ++i){
		for(from = 0 ; from < V ; ++from){
			sz = ady[from].size();
			for(int j = 0 ; j < sz ; ++j){
				to = ady[from][j].first;
				w = ady[from][j].second;
				relaxation(from, to, w);
			}
		}
	}
	
	for(from = 0 ; from < V ; ++from){
		sz = ady[from].size();
		for(int j = 0 ; j < sz ; ++j){
			to = ady[from][j].first;
			w = ady[from][j].second;
			if(relaxation(from, to, w)){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int T, from ,to, w;
	cin >> T;
	while(T--){
		cin >> V >> E;
		for(int i = 0 ; i <= V ; ++i)ady[i].clear();
		
		for(int i = 0 ; i < E ; ++i){
			cin >> from >> to >> w;
			ady[from].push_back(Node(to, w));
		}
		
		if(bellman(0))cout << "possible" << endl;
		else cout << "not possible" << endl;
	}
	
	return 0;
}
