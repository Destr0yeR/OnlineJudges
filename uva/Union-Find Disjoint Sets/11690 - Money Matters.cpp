#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

typedef unsigned long long ull;

int cantidad[50001];
int padre[50001];

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    int padreX = Find(x);
    int padreY = Find(y);
    if(padreX == padreY)return;
    cantidad[padreY] += cantidad[padreX];
    padre[padreX] = padreY;
}

bool check(int x){
    if(cantidad[Find(x)] == 0)return true;
    return false;
}

int main()
{
    //freopen(" - in.txt","r",stdin);
    //freopen(" - out.txt","w",stdout);
    int N, n, m, x, y;

    scanf("%d",&N);

    for(int tc = 1 ; tc <= N ; ++tc){
        scanf("%d %d", &n, &m);
        for(int i = 0 ; i < n ; ++i){
            cantidad[i] = 0;
            padre[i] = i;
        }

        for(int i = 0 ; i < n ; ++i)scanf("%d",&cantidad[i]);

        for(int i = 0 ; i < m ; ++i){
            scanf("%d %d", &x, &y);
            Union(x, y);
        }
        bool posible = true;

        for(int i = 0; i < n ; ++i){
            if(!check(i)){
                posible = false;
                break;
            }
        }

        printf("%s\n",(posible?"POSSIBLE":"IMPOSSIBLE"));
    }


    return 0;
}
