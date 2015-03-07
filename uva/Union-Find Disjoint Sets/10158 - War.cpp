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

int A, B;
bool setA, setB;

int aliado[10001];
int enemigo[10001];

int Find(int x){
    if(x == aliado[x])return x;
    return aliado[x] = Find(aliado[x]);
}

bool areFriends(int x, int y){
    return (Find(x) == Find(y));
}

bool areEnemies(int x, int y){
    return (Find(x) != Find(y));
}

void Union(int x, int y){
    aliado[Find(x)] = aliado[Find(y)];
}

void setFriends(int x, int y){
    Union(x, y);

    if(x == enemigo[x] && y == enemigo[y]){

    }
    else if(x == enemigo[x]){
        enemigo[x] = enemigo[y];
    }
    else if(y == enemigo[y]){
        enemigo[y] = enemigo[x];
    }
    else {
        Union(enemigo[x],enemigo[y]);
    }
}

void setEnemies(int x, int y){
    if(x == enemigo[x] && y == enemigo[y]){
        enemigo[x] = y;
        enemigo[y] = x;
    }
    else if(enemigo[x] == x){
        enemigo[x] = y;
        Union(x,enemigo[y]);
    }
    else if(enemigo[y] == y){
        enemigo[y] = x;
        Union(y,enemigo[x]);
    }
    else{
        Union(x,enemigo[y]);
        Union(y,enemigo[x]);
    }

}


int main()
{
    int n, c, x, y, i;
    scanf("%d",&n);
    REP(i,n+1){aliado[i]=i;enemigo[i]=i;}
    while(scanf("%d %d %d", &c, &x, &y)){
        if(c == 0 && x == 0 && y == 0)break;
        switch(c){
            case 1:
                setFriends(x, y);
                break;
            case 2:
                setEnemies(x, y);
                break;
            case 3:
                printf("%d\n",(areFriends(x, y)?1:0));
                break;
            case 4:
                printf("%d\n",(areEnemies(x, y)?1:0));
                break;
        }
    }

    return 0;
}
