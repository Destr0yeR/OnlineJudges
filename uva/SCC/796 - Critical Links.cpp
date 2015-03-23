#include<bits/stdc++.h>
#define MAX 1000
using namespace std;

int padre[MAX];
int ady[MAX][MAX];
int visitado[MAX];
int low[MAX];
int dist[MAX];



struct Edge{
    int x, y;
}arista[MAX];

bool cmp(Edge a, Edge b){
    if(a.x != b.x){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int n;
int orden;
int cont;

void dfs(int x){
    dist[x] = ++orden;
    low[x] = dist[x];
    visitado[x] = 1;
    for(int i = 0 ; i < n ; ++i){
        if(ady[x][i]){
            if(!visitado[i]){
                padre[i] = x;
                dfs(i);
                low[x] = min(low[x], low[i]);
                if(low[i] == dist[i]){
                    //printf("%d - %d\n", x, i);
                    if(x > i){
                        arista[cont].x = i;
                        arista[cont].y = x;
                        cont++;
                    }
                    else{
                        arista[cont].x = x;
                        arista[cont].y = i;
                        cont++;
                    }
                }
            }
            else if(i != padre[x]){
                low[x] = min(low[x], low[i]);
            }
        }
    }
}

void init(int x){
    cont =  0;
    orden = 0;
    memset(visitado,0,sizeof(visitado));
    memset(padre, -1 , sizeof(padre));
    memset(low, -1 , sizeof(padre));
    memset(dist, -1 , sizeof(padre));
    memset(ady, 0 , sizeof(ady));
}

int main()
{
    //freopen("796 - in.txt","r",stdin);
    //freopen("796 - out.txt","w",stdout);
    int k, dc, x, y, tmp;
    int tc = 1;
    while(scanf("%d", &n) == 1){
        if(n == 0){
            printf("0 critical links\n");
            printf("\n");
            continue;
        }
        init(n);
        for(int i = 0 ; i < n ; ++i){
            scanf("%d", &k);
            scanf(" (%d)", &dc);
            for(int j = 0 ; j < dc ; ++j){
                scanf(" %d", &tmp);
                ady[k][tmp] = 1;
            }
        }
        for(int i = 0 ; i < n ; ++i){
            if(!visitado[i])dfs(i);
        }
        printf("%d critical links\n", cont);
        sort(arista, arista + cont , cmp);
        for(int i = 0 ; i < cont ; ++i){
            printf("%d - %d\n", arista[i].x, arista[i].y);
        }
        printf("\n");
    }
    return 0;
}
