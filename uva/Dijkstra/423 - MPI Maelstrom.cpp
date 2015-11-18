#include<bits/stdc++.h>
#define MAX 102
#define inf (1<<30)
#define Node pair<int, int>
#define mset(x, y) memset(x, y, sizeof(x))

using namespace std;

struct cmp {
	bool operator () ( const Node &a, const Node &b ) {
		return a.second > b.second;
	}
};

vector<Node> ady[MAX];
priority_queue<Node, vector<Node>, cmp > Q;
int dist[MAX];
int visited[MAX];
int previous[MAX];
int V;

void init(){
	fill(dist, dist + MAX, inf);
	mset(visited, 0);
	mset(previous, -1);
}

void relaxation(int current, int to, int w){
	int aux = dist[current] + w;
	if(dist[to] > aux){
		dist[to] = aux;
		previous[to] = current;
		Q.push(Node(to, dist[to]));
	}
}

void dijkstra(int origen){
	Q.push(Node(origen,0));
	dist[origen] = 0;
	int current, to, w, sz;
	while(!Q.empty()){
		current = Q.top().first;
		Q.pop();
		if(visited[current] == 1)continue;
		
		visited[current] = 1;
		sz = ady[current].size();
		
		for(int i = 0 ; i < sz ; ++i){
			to = ady[current][i].first;
			w = ady[current][i].second;
			
			if(visited[to]  != 1){
				relaxation(current, to , w);
			}
		}
	}
}

int toNum(string s){
	istringstream buffer(s);
	int value;
	buffer >> value;
	return value;
}


int main(){
	
	int aux, maxi;
	string s;
	
	cin >> V;
	
	for(int i = 1 ; i <= V ; ++i){
		ady[i].push_back(Node(i,0));
	}
	
	for(int i = 2 ; i <= V ; ++i){
		for(int j = 1 ; j < i ; ++j){
			cin >> s;
			if(!(s.size() == 1 && s[0] == 'x')){
				aux = toNum(s);
				ady[i].push_back(Node(j, aux));
				ady[j].push_back(Node(i, aux));
			}
		}
	}
	
	init();
	dijkstra(1);
	
	maxi = 0;
	for(int i = 1 ; i <= V ; ++i)maxi = max(maxi, dist[i]);
	
	cout << maxi << endl;
	
	return 0;
}
