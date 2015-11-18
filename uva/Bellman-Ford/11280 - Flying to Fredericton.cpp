#include<bits/stdc++.h>
#define Node pair<int, int>
#define inf (1<<30)
#define MAX 101

using namespace std;

int V, E;
map<string, int> m;
vector<Node> ady[MAX];
int dist[MAX];
vector<int> v;

void relaxation(int from, int to, int w){
	int aux = dist[from] + w;
	if(dist[to] > aux){
		dist[to] = aux;
	}
}

void init(){
	for(int i = 1 ; i <= V ; ++i){
		dist[i] = inf;
	}
}

void bellman(int origen){
	init();
	dist[origen] = 0;
	int from, to, w, sz;
	
	for(int i = 1 ; i <= V-1 ; ++i){
		for(from = V ; from >= 1 ; --from){
			if(dist[from] != inf){
				sz = ady[from].size();
				for(int j = 0 ; j < sz ; ++j){
					to = ady[from][j].first;
					w = ady[from][j].second;
					relaxation(from, to, w);
				}
			}
		}
		v.push_back(dist[V]);
	}
}

int main(){
	
	int T, w, q, query, sz;
	cin >> T;
	string city, from, to;
	
	for(int tc = 1 ; tc <= T ; ++tc){
		cin >> V;
		v.clear();
		m.clear();
		for(int i = 1 ; i <= V ; ++i)ady[i].clear();
		
		for(int i = 1 ; i <= V ; ++i){
			cin >> city;
			m[city] = i;
		}
		
		cin >> E;
		
		for(int i = 0 ; i < E ; ++i){
			cin >> from >> to >> w;
			ady[m[from]].push_back(Node(m[to], w));
		}
		
		bellman(1);
		
		cin >> q;
		if(tc!=1)cout << endl;
		cout << "Scenario #" << tc << endl;
		sz = v.size();
		while(q--){
			cin >> query;
			query = min(query, sz-1);
			if(v[query] != inf)cout << "Total cost of flight(s) is $" << v[query] << endl;
			else cout << "No satisfactory flights" << endl;
		}
	}
	
	return 0;
}
