#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int padre[2001];
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
}punto[2001];

double distancia(Point a, Point b){
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    return (dx*dx + dy*dy);
}

ll _round(ll d){
    ll t = static_cast<ll>(sqrt(static_cast<double>(d)));
    return t + (t*t < d);
}

struct Edge{
    int x, y;
    ll d;
}arista[1999001];


bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

void init(int n){
    for(int i = 0 ; i <= n ; ++i)padre[i] = i;
    sets = n;
}

void solve(int n, int t){
    init(n);
    int x, y;
    int cont = 0;
    ll maxi, d;
    for(int i = 0 ; i < n ; ++i){
        for(int j = i+1 ; j < n ; ++j){
            arista[cont].x = i;
            arista[cont].y = j;
            arista[cont].d = distancia(punto[i], punto[j]);
            cont++;
        }
    }

    sort(arista, arista + cont, cmp);
    maxi = 0;
    for(int i = 0 ; i < n ; ++i){
        if(sets <= t)break;
        x = arista[i].x;
        y = arista[i].y;
        d = arista[i].d;
        if(Find(x) != Find(y)){
            Union(x, y);
            maxi = max(d, maxi);
        }
    }

    printf("%I64d\n", _round(maxi));
}

int main()
{
    //freopen("1216 - in.txt","r",stdin);
    //freopen("1216 - out.txt", "w", stdout);
    int T, t, n, cont, x, y;
    ll maxi;
    ll d;
    scanf("%d",&T);
    while(T--){
        scanf("%d", &t);
        n = 0;

        while(true){
            scanf("%d", &x);
            if(x == -1)break;
            scanf("%d", &y);
            punto[n].x = x;
            punto[n].y = y;
            n++;
        }
        solve(n, t);
    }
    return 0;
}
