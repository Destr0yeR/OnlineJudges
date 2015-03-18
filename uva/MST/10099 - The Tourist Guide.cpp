#include<bits/stdc++.h>

using namespace std;


int padre[101];

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

struct Edge{
    int x, y, d;
}arista[10005];

bool cmp(Edge a, Edge b){
    return a.d > b.d;
}

void init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
}

int main()
{
    int n, r, x, y, d, mini, s, de, t;
    for(int tc = 1 ; ; ++tc){
        scanf("%d %d", &n, &r);
        if(n == 0 && r == 0)return 0;
        init(n);
        for(int i = 0 ; i < r ; ++i){
            scanf("%d %d %d", &arista[i].x, &arista[i].y, &arista[i].d);
        }

        sort(arista, arista + r, cmp);

        scanf("%d %d %d", &s, &de ,&t);

        for(int i = 0 ; i < r ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                if(Find(s) != Find(de)){
                    Union(x, y);
                    mini = d;
                }
            }
        }

        int rpta = ceil(t*1.0/(mini-1));

        printf("Scenario #%d\n",tc);
        printf("Minimum Number of Trips = %d\n",rpta);
        printf("\n");

    }

    return 0;
}
