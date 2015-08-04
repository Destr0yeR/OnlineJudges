#include<bits/stdc++.h>

using namespace std;

#define mset(x, y) memset((x), (y), sizeof((x)))
#define MAX 10005
#define Node pair<int, int>
#define INF 1<<30

vector< Node > ady[ MAX ];
int dist[ MAX ];
bool vis[ MAX ];
int prev[ MAX ];

bool cmp(Node a, Node b){
    return a.second < b.second;
}

priority_queue < Node,  vector< Node> , cmp> Q;
int V;

void init(){
    mset(dist, INF);
    mset(vis , false);
    mset(prev, -1);
}

void relajacion( int actual, int adyacente, int peso){
    cout << actual << " " << adyacente << " " << peso << endl;
    if( dist[ actual ] + peso < dist [ adyacente ]){
        dist[ adyacente ] = dist[ actual ] + peso;
        prev[ adyacente ] = actual;
        Q.push( Node( adyacente, dist[ adyacente ] ));
    }
}

void print( int destino ){
    if( prev[ destino ] != -1 )
        print( prev[ destino ] );
    printf("%d " , destino );
}

void dijkstra(int inicial){
    int actual;
    int adyacente;
    int peso;
    Q.push(Node(inicial, 0));
    dist[inicial] = 0;
    while( !Q.empty() ){
        actual = Q.top().first;
        Q.pop();
        if(vis[ actual ]) continue;
        vis[ actual ] = true;

        for( int i = 0 ; i < ady[ actual ].size() ; ++i ){
            adyacente =  ady[actual][i].first;
            peso = ady[actual][i].second;
            if( !vis[ adyacente ] ){
                relajacion( actual, adyacente, peso);
            }
        }
    }
}

int main()
{
    //freopen(" - in.txt", "r", stdin);
    //freopen(" - out.txt", "w", stdout);
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int m;
    cin >> V >> m;
    int a, b, w;

    for(int i = 0 ; i < m ; ++i){
        cin >> a >> b >> w;
        ady[a].push_back(Node(b,w));
        ady[b].push_back(Node(a,w));
    }

    for(int i = 0 ; i < m ; ++i){

    }

    init();
    dijkstra(0);

    int q;
    cin >> q;
    int aux;

    for(int i = 0 ; i <= V ; ++i){
        cout << i << " : " << prev [ i ] << endl;
    }

    return 0;
}
