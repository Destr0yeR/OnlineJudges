#include<bits/stdc++.h>

using namespace std;

int padre[501];
int sets;

int Find(int x){
    if(padre[x] == x)return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
    sets--;
}
struct Point{
    int x, y;
}punto[501];

double distancia(Point a, Point b){
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

struct Edge{
    int x, y;
    double d;
}arista[250001];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

void init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
    sets = x;
}

int main()
{
    int s, p, T, x, y, cont;
    double d, maxi;

    scanf("%d", &T);

    for(int tc = 1 ; tc <= T ; ++tc){
        scanf("%d %d", &s, &p);
        init(p);

        for(int i = 0 ; i < p ; ++i){
            scanf("%d %d", &punto[i].x, &punto[i].y);
        }
        maxi = 0;
        cont = 0;
        for(int i = 0 ; i < p ; ++i){
            for(int j = i+1 ; j < p ; ++j){
                arista[cont].x = i;
                arista[cont].y = j;
                arista[cont].d = distancia(punto[i], punto[j]);
                cont++;
            }
        }

        sort(arista, arista + cont, cmp);

        for(int i = 0 ; i < cont && sets != s; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
                maxi = d;
            }
        }

        printf("%.2f\n", maxi);
    }


    return 0;
}
