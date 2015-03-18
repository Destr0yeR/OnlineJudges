#include<bits/stdc++.h>

using namespace std;

int padre[751];

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

struct Point{
    int x, y;
}punto[751];

double distancia(Point a, Point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

struct Edge{
    int x, y;
    double d;
}arista[562501];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

void init(int n){
    for(int i = 0 ; i <= n ; ++i)padre[i] = i;
}
int main()
{

    //freopen("10397 - in.txt","r",stdin);
    //freopen("10397 - out.txt","w",stdout);
    int n, m, x, y, cont;
    double d, total;
    while(scanf("%d", &n) == 1){
        init(n);
        for(int i = 1 ; i <= n ; ++i){
            scanf("%d %d", &punto[i].x, &punto[i].y);
        }
        scanf("%d", &m);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        cont = 0;
        for(int i = 1 ; i <= n ; ++i){
            for(int j = i+1 ; j <= n ; ++j){
                arista[cont].x = i;
                arista[cont].y = j;
                arista[cont].d = distancia(punto[i], punto[j]);
                cont++;
            }
        }

        sort(arista, arista + cont, cmp);
        total = 0;
        for(int i = 0 ; i < cont ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
                total += d;
            }
        }

        printf("%.2f\n", total);
    }

    return 0;
}
