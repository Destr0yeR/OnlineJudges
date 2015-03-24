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
}

void init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
    sets = x;
}

struct Edge{
    int x, y, d;
}arista[100001];

bool cmp(Edge a, Edge b){
    return a.d > b.d;
}

int main()
{
    int c, total, x, y, d, n, m;
    scanf("%d", &c);
    while(c--){
        scanf("%d %d", &n, &m);
        init(n);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &arista[i].x, &arista[i].y , &arista[i].d);
        }
        sort(arista, arista + m, cmp);
        total = 0;
        for(int i = 0 ; i < m ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                Union(x, y);
            }
            else{
                total += d;
            }
        }
        printf("%d\n", total);
    }
    scanf("%d", &c);
    return 0;
}
