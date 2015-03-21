#include<bits/stdc++.h>

using namespace std;

int padre[751];
int sets;

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
    sets--;
}

struct Point{
    int x, y;
}punto[751];

double distancia(Point a, Point b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

struct Edge{
    int x, y;
    double d;
}arista[570000];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

void init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
    sets = x;
}

int main()
{
    //freopen("10147 - in.txt", "r", stdin);
    //freopen("10147 - out.txt", "w", stdout);
    int T, n, m, cont, x, y;
    double d;
    scanf("%d", &T);
    for(int tc = 1 ; tc <= T ; ++tc){
        scanf("%d", &n);
        init(n);
        for(int i = 1 ; i <= n ; ++i){
            scanf("%d %d", &punto[i].x, &punto[i].y);
        }
        scanf("%d", &m);
        cont = 0;
        for(int i = 1 ; i <= n ; ++i){
            for(int j = i+1 ; j <= n ; ++j){
                arista[cont].x = i;
                arista[cont].y = j;
                arista[cont].d = distancia(punto[i], punto[j]);
                cont++;
            }
        }

        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d", &x, &y);
            if(Find(x) != Find(y)){
                Union(x, y);
            }
        }
        if(tc != 1)printf("\n");
        if(sets == 1){
            printf("No new highways need\n");
        }
        sort(arista, arista + cont, cmp);
        for(int i = 0 ; i < cont ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
                printf("%d %d\n", x, y);
            }
            if(sets == 1)break;
        }
    }

    return 0;
}
