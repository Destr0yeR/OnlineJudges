#include<bits/stdc++.h>

using namespace std;

int padre[10001];
int sets;

int Find(x){
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
    return a.d < b.d;
}

int main()
{
    int c;
    scanf("%d", &c);
    while(c--){
        scanf("%d %d", &n, &m);
        init(n);
        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d %d", &arista[i].x, &arista[i].y ; &arista[i].d);
        }
        sort(arista, arista + m, cmp);

        for(int i = 0 ; i < m ; ++i){

        }
    }
    scanf("%d", &c);
    return 0;
}
