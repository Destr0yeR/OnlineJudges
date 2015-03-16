#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

typedef unsigned long long ull;

struct Edge{
    int origen;
    int destino;
    int distancia;
}arista[50001];

bool cmp(Edge a, Edge b){return a.distancia < b.distancia;}

int padre[2001];

int Find(int x){
    if(x == padre[x])return x;
    return padre[x] = Find(padre[x]);
}
void Union(int x, int y){
    padre[Find(x)] = Find(y);
}



int main()
{
    //freopen(" - in.txt","r",stdin);
    //freopen(" - out.txt","w",stdout);
    int T, N, M, x, y, cont, d, total;
    char a[8], b[8];
    char s[30];

    gets(s);
    sscanf(s,"%d",&T);

    for(int tc = 0 ; tc < T ; ++tc){
        map<string, int> m;
        cont = 1;
        total = 0;
        gets(s);
        gets(s);
        sscanf(s,"%d",&M);
        gets(s);
        sscanf(s,"%d",&N);

        for(int i = 1 ; i <= M ; ++i){
            padre[i] = i;
        }

        for(int i = 0 ; i < N ; ++i){
            gets(s);
            sscanf(s,"%s %s %d", &a, &b, &d);
            string tmpa(a), tmpb(b);
            if(m[tmpa] == 0){m[tmpa] = cont++;}
            if(m[tmpb] == 0){m[tmpb] = cont++;}
            x = m[tmpa];
            y = m[tmpb];
            arista[i].origen = x;
            arista[i].destino = y;
            arista[i].distancia = d;
        }

        sort(arista, arista + N, cmp);

        for(int i = 0 ; i < N ; ++i){
            x = arista[i].origen;
            y = arista[i].destino;
            d = arista[i].distancia;

            if(Find(x) != Find(y)){
                total+= d;
                Union(x, y);
            }
        }
        if(tc != 0)printf("\n");
        printf("%d\n",total);

        m.clear();
    }

    return 0;
}
