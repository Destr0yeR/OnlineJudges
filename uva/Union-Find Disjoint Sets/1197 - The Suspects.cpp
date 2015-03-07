#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
using namespace std;

#define DEBUG
#define REP(i,a) for(i=0;i<a;i++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define VE vector<int>
#define SZ size()
#define PB push_back

using namespace std;

typedef unsigned long long ull;

int n, m, i, k, j, tmp, total, aux;
int padre[30001];

int Find(int x){
    if(padre[x] == x)return x;
    return padre[x] = Find(padre[x]);
}

void Union(int x, int y){
    if(Find(x) == 0){
        padre[Find(y)] = padre[Find(x)];
    }
    padre[Find(x)] = padre[Find(y)];
}

int main()
{

    while(scanf("%d %d", &n, &m)){
        if(n == 0 && m == 0)break;
        REP(i,n){padre[i] = i;}

        REP(i,m){
            scanf("%d",&k);

            scanf("%d",&aux);
            REP(j,k-1){
                scanf("%d",&tmp);
                Union(tmp,aux);
            }
        }

        total = 0;
        REP(i,n){
            if(Find(i) == 0){total++;}
        }

        printf("%d\n",total);
    }

    return 0;
}
