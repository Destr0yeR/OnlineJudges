#include<bits/stdc++.h>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;
int padre[1001];
int Find(int x){
    if(x == padre[x])return x;
    return padre[x] = Find(padre[x]);
}

struct Point{
    int x;
    int y;
}punto[1001];

ull _round(double x){
    return floor(x + 0.5);
}

double distancia(Point x, Point y){
    ll a = x.x - y.x;
    ll b = x.y - y.y;
    double d = sqrt(a*a + b*b);
    return d;
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

struct Edge{
    int x;
    int y;
    double d;
}arista[1000001];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

int main()
{
    //freopen("1235 - in.txt","r",stdin);
    //freopen("1235 - out.txt","w",stdout);
    int T, n, r, states;
    double roads, rails;

    scanf("%d", &T);

    for(int tc = 1 ; tc <= T ; ++tc){
        scanf("%d %d", &n, &r);
        roads = 0;
        rails = 0;
        states = 0;
        for(int i = 0 ; i <= n ; ++i)padre[i] = i;

        for(int i = 0 ; i < n ; ++i){
            scanf("%d %d", &punto[i].x, &punto[i].y);
        }
        int cont = 0;
        for(int i = 0 ; i < n ; ++i){
            for(int j = i+1 ; j < n ; ++j){
                arista[cont].x = i;
                arista[cont].y = j;
                arista[cont].d = distancia(punto[i], punto[j]);
                cont++;
            }
        }

        sort(arista, arista + cont, cmp);

        for(int i = 0 ; i < cont ; ++i){
            int x = arista[i].x;
            int y = arista[i].y;
            double d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
                if(d <= r){
                    roads += d;
                }
                else{
                    rails += d;
                    states++;
                }
            }
        }
        states++;

        printf("Case #%d: %d %llu %llu\n", tc, states, _round(roads), _round(rails));
    }

    return 0;
}
