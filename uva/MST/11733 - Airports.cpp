#include<bits/stdc++.h>

using namespace std;

int padre[10001];

int sets;

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
    sets--;
}

struct Edge{
    int x;
    int y;
    int d;
}arista[100001];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

int main()
{
    int T, airports, mini, n, m, a;

    scanf("%d", &T);

    for(int tc = 1 ; tc <= T ; ++tc){
        airports = 0;
        mini = 2147483647;
        scanf("%d %d %d",&n, &m , &a);
        sets = n;

        mini = min(n*a, mini);
        airports = n;

        for(int i = 0 ; i <= n ; ++i)padre[i] = i;

        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &arista[i].x, &arista[i].y, &arista[i].d);
        }

        sort(arista, arista + m, cmp);
        int x, y, d, total = 0, tmp;
        for(int i = 0 ; i < m ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;

            if(Find(x) != Find(y)){
                Union(x, y);
                total += d;
                tmp = total + sets*a;
                if(tmp < mini){
                    mini = tmp;
                    airports = sets;
                }
            }
        }

        printf("Case #%d: %d %d\n",tc, mini, airports);
    }
    return 0;
}
