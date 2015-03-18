#include<bits/stdc++.h>

using namespace std;

int padre[201];

struct Point{
    int x, y;
}punto[201];

double distancia(Point x, Point y){
    int a = x.x - y.x;
    int b = x.y - y.y;
    return sqrt(a*a + b*b);
}

int Find(int x){
    if(x == padre[x])return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

struct Edge{
    int x, y;
    double d;
}arista[40001];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

int main()
{
    //freopen("534 - in.txt","r",stdin);
    //freopen("534 - out.txt","w",stdout);
    int n, cont, x, y;
    double d, maxi;
    int tc = 1;
    bool oc1, oc2 = false;
    while(scanf("%d", &n)){
        if(n == 0)break;
        for(int i = 0 ; i < n ; ++i)padre[i] = i;

        for(int i = 0 ; i < n ; ++i){
            scanf("%d %d", &punto[i].x, &punto[i].y);
        }

        cont = 0;
        maxi = 0;

        for(int i = 0 ; i < n ; ++i){
            for(int j = i+1 ; j < n ; ++j){
                arista[cont].x = i;
                arista[cont].y = j;
                arista[cont].d = distancia(punto[i], punto[j]);
                cont++;
            }
        }
        oc1 = false;
        oc2 = false;
        sort(arista, arista + cont, cmp);

        for(int i = 0 ; i < cont ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                if(Find(0) != Find(1)){
                    Union(x, y);
                    maxi = d;
                }
            }
        }
        printf("Scenario #%d\n",tc++);
        printf("Frog Distance = %.3f\n",maxi);
        printf("\n");
    }

    return 0;
}
