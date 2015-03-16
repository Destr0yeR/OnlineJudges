#include<bits/stdc++.h>

using namespace std;

int padre[100001];
int sets;
int Find(int x){
    if(x == padre[x])return x;
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
}arista[10000001];

bool cmp(Edge a, Edge b){
    return a.d < b.d;
}

int main()
{
    int n, m, maxi;

    while(scanf("%d %d", &n , &m)){
        if(n == 0 && m == 0)break;

        maxi = 0;
        for(int i = 0 ; i < n ; ++i) padre[i] = i;
        sets = n;
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &arista[i].x, &arista[i].y, &arista[i].d);
        }

        sort(arista, arista + m, cmp);

        int x, y, d;

        for(int i = 0 ; i < m ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
                maxi = d;
            }
        }

        if(sets > 1){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("%d\n",maxi);
        }

    }

    return 0;
}
