#include<bits/stdc++.h>

using namespace std;

int padre[201];

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

struct Edge{
    int x, y, d;
}arista[19901];

bool cmp(Edge a, Edge b){
    return a.d > b.d;
}

void init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
}

int main()
{
    int n, r, d, cont, x, y, mini;

    string f, t;
    char tmpf[100], tmpt[100];

    for(int tc = 1 ; ; ++tc){
        scanf("%d %d", &n, &r);
        if(n == 0 && r == 0)return 0;
        init(n);
        mini = 0;
        map<string, int> m;
        cont = 0;
        for(int i = 0 ; i < r ; ++i){
            scanf("%s %s %d",&tmpf, &tmpt, &d);
            string f(tmpf);
            string t(tmpt);
            if(m[f] == 0)m[f] = cont++;
            if(m[t] == 0)m[t] = cont++;
            x = m[f];
            y = m[t];
            arista[i].x = x;
            arista[i].y = y;
            arista[i].d = d;
        }
        scanf("%s %s", &tmpf, &tmpt);
        string f(tmpf);
        string t(tmpt);
        sort(arista, arista + r, cmp);

        for(int i = 0 ; i < r ; ++i){
            x = arista[i].x;
            y = arista[i].y;
            d = arista[i].d;
            if(Find(x) != Find(y)){
                if(Find(m[f]) != Find(m[t])){
                    Union(x, y);
                    mini = d;
                }
            }
        }

        printf("Scenario #%d\n", tc);
        printf("%d tons\n", mini);
        printf("\n");
    }

    return 0;
}

