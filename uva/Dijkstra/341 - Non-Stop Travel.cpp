#include<bits/stdc++.h>
#define MAX 22
#define Node pair<int, int>
#define inf (1<<30)
#define mset(x, y) memset(x, y, sizeof(x))

using namespace std;

struct cmp {
    bool operator() ( const Node &a , const Node &b ) {
        return a.second > b.second;
    }
};

vector<Node> ady[MAX];
int dist[MAX];
int previous[MAX];
int visited[MAX];
priority_queue< Node , vector<Node> , cmp > Q;
int V;

void init(){
	fill(dist + 1, dist + V + 1, inf);
	mset(previous, -1);
	mset(visited, 0);
}

void path( int origen, int to ){
    if( previous[ to ] != -1 )
        path( origen, previous[ to ] );
    if(origen!=to)cout<<" ";
    cout << to;
}

void relaxation(int current, int to , int w){
	int aux = dist[current] + w;
	
	if(  aux < dist[to]){
		dist[to] = aux;
		previous[to] = current;
		Q.push( Node(to, dist[to] ));
	}
}

void dijkstra(int origen){
	Q.push( Node(origen, 0) );
	dist[origen] = 0;
	int current, t, w, sz;
	while(!Q.empty()){
		current = Q.top().first;
		Q.pop();
		if(visited[current] == 1)continue;
		visited[current] = 1;
		sz = ady[current].size();
		
		for(int i = 0 ; i < sz ; ++i){
			t = ady[current][i].first;
			w = ady[current][i].second;
			if(visited[t] != 1){
				relaxation( current, t, w);
			}
		}
	}
}

int main(){
	int n, t, w, o, d;
	int tc = 1;
	while(cin>>V){
		if(!V)break;
		for(int i = 1 ; i <= V ; ++i){
			ady[i].clear();
			cin >> n;
			while(n--){				
				cin >> t >> w;
				ady[i].push_back(Node(t, w));
			}
		}
		cin >> o >> d;
		init();
		dijkstra(o);
		
		cout << "Case " << tc++ <<": Path = ";
		path(o, d);
		cout << "; " << dist[d] <<" second delay" << endl;
	}
	
	return 0;
}
