#include<bits/stdc++.h>

using namespace std;

int padre[100001];

int Find(int x){
    if(x == padre[x]) return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    padre[Find(x)] = Find(y);
}

void init(int x){
    for(int i = 0 ; i <= x ; ++i)padre[i] = i;
}

int main()
{
    int x, y, cont = 0, total = 0;
    init(100000);
    while(scanf("%d", &x) == 1){
        if(x == -1){
            printf("%d\n", total);
            init(100000);
            total = 0;
        }
        else{
            scanf("%d", &y);
            if(Find(x) != Find(y)){
                Union(x, y);
            }
            else{
                total++;
            }
        }
    }
    return 0;
}
